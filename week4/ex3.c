
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void readc(char *command){
    scanf("%s", command);
}

void tp()
{
printf("[user]$ ");
}

int main()
{
    char command[100];
    
    while(1){

    tp();
    readc(command);
    system(command);

    }
    return 0;
}


