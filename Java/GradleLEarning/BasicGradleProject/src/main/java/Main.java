import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;

import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.NetworkInterface;
import java.net.InetAddress;
import java.net.URI;
import java.util.Collections;
import java.util.Enumeration;

public class Main {
    public static void main(String[] args) throws Exception {
        int port = 8000;
        HttpServer server = HttpServer.create(new InetSocketAddress("0.0.0.0", port), 0);

        server.createContext("/", new HtmlHandler());
        server.createContext("/button", new ButtonHandler());
        server.setExecutor(null);
        server.start();

        System.out.println("Сервер запущено! До нього можна підключитись за адресами:");
        for (String ip : getLocalIPs()) {
            System.out.println("  ➤ http://" + ip + ":" + port + "/");
        }
    }

    static class HtmlHandler implements HttpHandler {
        public void handle(HttpExchange exchange) {
            try {
                String response = """
                        <!DOCTYPE html>
                        <html lang="uk">
                        <head>
                            <meta charset="UTF-8">
                            <title>Кнопки на сервері</title>
                        </head>
                        <body>
                            <h1>Натисни кнопку</h1>
                            <form action="/button" method="get">
                                <button type="submit" name="name" value="button1">Кнопка 1</button>
                                <button type="submit" name="name" value="button2">Кнопка 2</button>
                            </form>
                        </body>
                        </html>
                        """;

                exchange.getResponseHeaders().set("Content-Type", "text/html; charset=UTF-8");
                exchange.sendResponseHeaders(200, response.getBytes().length);
                OutputStream os = exchange.getResponseBody();
                os.write(response.getBytes());
                os.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    static class ButtonHandler implements HttpHandler {
        public void handle(HttpExchange exchange) {
            try {
                URI requestURI = exchange.getRequestURI();
                String query = requestURI.getQuery(); // name=button1 або name=button2
                String message = "Натиснуто кнопку: ";

                if (query != null && query.startsWith("name=")) {
                    String buttonName = query.substring("name=".length());
                    message += buttonName;
                } else {
                    message += "невідому";
                }

                System.out.println(message);

                String response = "<p>Дякую! " + message + "</p><p><a href='/'>Повернутись назад</a></p>";
                exchange.getResponseHeaders().set("Content-Type", "text/html; charset=UTF-8");
                exchange.sendResponseHeaders(200, response.getBytes().length);
                OutputStream os = exchange.getResponseBody();
                os.write(response.getBytes());
                os.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static java.util.List<String> getLocalIPs() {
        try {
            java.util.List<String> ipList = new java.util.ArrayList<>();
            Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
            for (NetworkInterface netint : Collections.list(nets)) {
                if (!netint.isUp() || netint.isLoopback()) continue;
                Enumeration<InetAddress> inetAddresses = netint.getInetAddresses();
                for (InetAddress inetAddress : Collections.list(inetAddresses)) {
                    if (!inetAddress.isLoopbackAddress() && inetAddress instanceof java.net.Inet4Address) {
                        ipList.add(inetAddress.getHostAddress());
                    }
                }
            }
            return ipList;
        } catch (Exception e) {
            e.printStackTrace();
            return java.util.List.of("localhost");
        }
    }
}
