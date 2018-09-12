#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() 
{
    int n = fork();
    if (n > 0) {
    printf("Hello from parent [PID - %d]\n", n); 
    } 
    else 
    if (n == 0) { 
    printf("Hello from child [PID - %d]\n", n); 
    } 
    return 0; 
}