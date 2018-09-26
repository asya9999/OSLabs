#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler (int signal) {
    printf("Signal %d - SIGINT \n", signal);
    exit(1);
}
int main () {
    signal(SIGINT, handler);
    while (1){ 
    	sleep (10);
    }
    return 0;
}

