#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
        
int main()
{
    char z[] = "ex1";
    char new_str[20]; 
    
    int fd[2];
    pipe(fd);
    
    write(fd[1], z, strlen(z)+1); 
    close(fd[1]); 
    read(fd[0], new_str, 100); 
    close(fd[0]);

    puts(new_str);
    
    return 0;
}
