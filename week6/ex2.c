#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
        
int main()
{
    char z[] = "Lab6";
    int fd[2];
    pid_t p;
    
    pipe(fd);
    p = fork();
    
    if (p > 0) 
    {  
        close(fd[0]); 
        write(fd[1], z, strlen(z)+1); 
        close(fd[1]); 
    } 
    // child process 
    else
    { 
        close(fd[1]);
        char str[100]; 
        read(fd[0], str, 100); 
        close(fd[0]);
        puts(str);
        exit(0);
 
    } 
    
    return 0;
}