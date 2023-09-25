#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#include "ft_memcpy.c"

#define NUM_THREADS 32
typedef struct {
    int start;
    int end;
    char* result;
} ThreadData;


int itoa_(int number, char *buf) {
    char tmpbuf[12];
    char *cur = tmpbuf+11;
    *cur = '\n';
    int i = 1;
    for (; number > 0; i++) {
        cur--;
        int tmp = number % 10;
        number /= 10;
        *cur = tmp + '0';
    }
    memcpy(buf, cur, i);
    return i;
}

void* from_to(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    int start = data->start;
    int end = data->end;

    char* result = malloc(2 << 28); 

    char* ptr = result;
    for (int i = start; i < end;)
    {
        ptr += itoa_(i++, ptr);
        ptr += itoa_(i++, ptr);
        ptr += itoa_(i++, ptr);
        memcpy(ptr, "Fizz\n", 5); ptr += 5;
        ptr += itoa_(i++, ptr);
        ptr += itoa_(i++, ptr);
        memcpy(ptr, "Buzz\n", 5); ptr += 5;
        ptr += itoa_(i++, ptr);
        memcpy(ptr, "Fizz\n", 5); ptr += 5;
        ptr += itoa_(i++, ptr);
        ptr += itoa_(i++, ptr);
        ptr += itoa_(i++, ptr);
        memcpy(ptr, "Fizz\n", 5); ptr += 5;
        ptr += itoa_(i++, ptr);
        memcpy(ptr, "Buzz\n", 5); ptr += 5;
        ptr += itoa_(i++, ptr); 
        ptr += itoa_(i++, ptr);
        memcpy(ptr, "Fizz\n", 5); ptr += 5;
        ptr += itoa_(i++, ptr);
        ptr += itoa_(i++, ptr);
        ptr += itoa_(i++, ptr);
        memcpy(ptr, "FizzBuzz\n", 9); ptr += 9;
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
        //printf(thread_data[i].result);
        free(thread_data[i].result);

    }

    end_time = clock();
    printf("Execution time: %f seconds\n", (double)(end_time - start_time) / (4.5 * 100000 * 16));

    return 0;
}
