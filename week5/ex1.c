#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int thread_id[5];

void * Hello(int i) {
    printf("Hi! Thread: %d Was created in iteration %d !\n", (int) pthread_self(), i);
    sleep(2);
    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {
    int nt, i;
    for (i = 0; i < 5; ++i) {
        printf(" Create new thread ");
        nt = pthread_create(&thread_id[i], NULL, Hello, i);
        sleep(1);
    }
    pthread_exit(NULL);
}