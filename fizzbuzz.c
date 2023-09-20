#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stddef.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 32

typedef struct {
    int start;
    int end;
    char* result;
} ThreadData;

void* from_to(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    int start = data->start;
    int end = data->end;

    char* result = malloc(pow(2, 29)); // Assuming a maximum size
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    char* ptr = result;
    for (int i = start; i < end; i += 15) {
        ptr += sprintf(ptr, "%d\n", i);
        ptr += sprintf(ptr, "%d\n", i + 1);
        ptr += sprintf(ptr, "%dFizz\n", i + 2);
        ptr += sprintf(ptr, "%d\n", i + 3);
        ptr += sprintf(ptr, "%dBuzz\n", i + 4);
        ptr += sprintf(ptr, "%dFizz\n", i + 5);
        ptr += sprintf(ptr, "%d\n", i + 6);
        ptr += sprintf(ptr, "%d\n", i + 7);
        ptr += sprintf(ptr, "%dFizz\n", i + 8);
        ptr += sprintf(ptr, "%dBuzz\n", i + 9);
        ptr += sprintf(ptr, "%d\n", i + 10);
        ptr += sprintf(ptr, "%dFizz\n", i + 11);
        ptr += sprintf(ptr, "%d\n", i + 12);
        ptr += sprintf(ptr, "%d\n", i + 13);
        ptr += sprintf(ptr, "%dFizzBuzz\n", i + 14);
    }

    data->result = result;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    clock_t start_time, end_time;

    start_time = clock();
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].start = i * (1000000000 / NUM_THREADS) + 1;
        thread_data[i].end = (i + 1) * (1000000000 / NUM_THREADS) + 1;
        pthread_create(&threads[i], NULL, from_to, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        free(thread_data[i].result);

    }

    end_time = clock();


    printf("Execution time: %f seconds\n", (double)(end_time - start_time) / (4.5 * 1000000000 * 16));

    return 0;
}
