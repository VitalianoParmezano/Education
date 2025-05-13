#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 100
#define MAX_THREADS 4

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], RESULT[SIZE][SIZE];
int num_threads = 1;  // За замовчуванням 1 потік

// Генерація випадкових чисел [-100; 100]
int rand_range() {
    return rand() % 201 - 100;
}

// Ініціалізація матриць
void generate_matrices() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand_range();
            B[i][j] = rand_range();
            C[i][j] = rand_range();
        }
}

// Виведення матриці (обережно — буде багато виводу)
void print_matrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Функція для додавання (частину обробляє кожен потік)
void* add_matrices(void* arg) {
    int thread_id = *(int*)arg;
    int rows_per_thread = SIZE / num_threads;
    int start_row = thread_id * rows_per_thread;
    int end_row = (thread_id == num_threads - 1) ? SIZE : start_row + rows_per_thread;

    for (int i = start_row; i < end_row; i++)
        for (int j = 0; j < SIZE; j++)
            RESULT[i][j] = A[i][j] + B[i][j] + C[i][j];

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc >= 2)
        num_threads = atoi(argv[1]);

    if (num_threads != 1 && num_threads != 4) {
        printf("❌ Кількість потоків має бути 1 або 4.\n");
        return 1;
    }

    srand(time(NULL));
    generate_matrices();

    clock_t start_time = clock();

    if (num_threads == 1) {
        int tid = 0;
        add_matrices(&tid);
    } else {
        pthread_t threads[MAX_THREADS];
        int thread_ids[MAX_THREADS];

        for (int i = 0; i < num_threads; i++) {
            thread_ids[i] = i;
            pthread_create(&threads[i], NULL, add_matrices, &thread_ids[i]);
        }

        for (int i = 0; i < num_threads; i++)
            pthread_join(threads[i], NULL);
    }

    clock_t end_time = clock();
    double elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n✅ Додавання завершено. (A + B + C)\n");

    // Якщо хочеш — можеш виводити результат:
    // print_matrix(RESULT);

    printf("⏱️ Час виконання: %.6f секунд\n", elapsed);

    return 0;
}
