#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
    pid_t c1;
    pid_t c2;
    
    int fd[2];
    pipe(fd);   
    
    c1 = fork();
    
    //parent
    if (c1>0) 
    {  
        int pid_c2_id;
        int fd2[2];
        pipe(fd2); 
        c2 = fork();
        
        //parent
        if(c2>0){
            close(fd2[1]);

            int concat_str; 
            read(fd2[0], &concat_str, sizeof(concat_str)); 
            close(fd2[0]);

            close(fd[0]); 
            write(fd[1], &concat_str, sizeof(concat_str)); 
            close(fd[1]);


            printf("Parent of %d\n", concat_str);
            while(waitpid(getpid(), NULL ,0)!=c2) {
                printf("Whait for child termination\n");
                sleep(2);
                //exit(0);
            }
        }
        //child
        else{
            close(fd2[0]); 
            int pi = getpid();
            write(fd2[1], &pi, sizeof(getpid())); 
            close(fd2[1]); 
            printf("C2\n");
            //will not stop
            while(1){
        }
        }
        
    } 
    // child process 
    else if(c1==0)
    {
        int pid_of_c2;
        close(fd[1]);
        read(fd[0], &pid_of_c2, sizeof(pid_of_c2)); 
        close(fd[0]);
        printf("The C2 child is %d\n", pid_of_c2);
        sleep(2);
        kill(c2, SIGSTOP);
        exit(0);
 
    } 

    return 0;
}
