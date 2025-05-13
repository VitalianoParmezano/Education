// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // 1. Створення сокету
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Не вдалося створити сокет");
        exit(EXIT_FAILURE);
    }

    // 2. Налаштування адреси
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // localhost
    server_addr.sin_port = htons(PORT);

    // 3. Прив’язка сокету
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Помилка при bind");
        exit(EXIT_FAILURE);
    }

    // 4. Очікування підключення
    listen(server_fd, 1);
    printf("Сервер очікує на з'єднання...\n");

    // 5. Прийом підключення
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (client_fd < 0) {
        perror("Помилка при accept");
        exit(EXIT_FAILURE);
    }

    // 6. Отримання та повторення повідомлення
    int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Отримано повідомлення: %s\n", buffer);
        send(client_fd, buffer, strlen(buffer), 0);  // echo
    }

    // 7. Закриття сокетів
    close(client_fd);
    close(server_fd);

    return 0;
}
