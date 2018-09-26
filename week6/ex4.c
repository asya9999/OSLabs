#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sighandler (int signal) {
    printf("Signal %d - SIGINT \n", signal);
    exit(1);
}
void sigustophandler (int signal) {
    printf("Signal %d - SIGSTOP \n", signal);
    exit(1);
}
void sigusr1handler (int signal) {
    printf("Signal %d - SIGUSR1 \n", signal);
    exit(1);
}
int main () {
    signal(SIGINT, sighandler);
    signal(SIGSTOP, sigustophandler);
    signal(SIGUSR1, sigusr1handler);
    while (1) 
    	{
    		sleep (10);
    	}
    return 0;
}

