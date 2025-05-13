// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // 1. Створення сокету
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Не вдалося створити сокет");
        exit(EXIT_FAILURE);
    }

    // 2. Налаштування адреси сервера
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // localhost

    // 3. Підключення до сервера
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Помилка при підключенні");
        exit(EXIT_FAILURE);
    }

    // 4. Ввід повідомлення
    printf("Введіть повідомлення: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // 5. Надсилання та отримання відповіді
    send(sock, buffer, strlen(buffer), 0);
    int bytes_received = read(sock, buffer, BUFFER_SIZE);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Відповідь від сервера: %s\n", buffer);
    }

    // 6. Закриття сокету
    close(sock);

    return 0;
}
