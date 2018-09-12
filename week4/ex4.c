
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void tp()
{
printf("[user]$ ");
}

int main()
{

	while(1){
	tp();
	char *line[100];
	int number;
	char command[100];
	gets(command);  
    char *token = strtok(command, " "); 
    while (token != NULL) 
    { 
        line[number] = token;

        number = number + 1;
        token = strtok(NULL, " "); 
    }

    execvp(line[0], line);

	}

    return 0;
}
