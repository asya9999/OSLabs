#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
    pid_t p;
    
    p = fork();
    
    if(p==0)
    {
        while(1){
            printf("I’m alive\n");   
            sleep(1);
        }
    }
    else{
        sleep(10);
        kill(p, SIGTERM);
        exit(0);
        
    }

    return 0;
}