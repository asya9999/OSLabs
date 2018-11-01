#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int myfd = open("ex1.txt", O_RDWR);
    char *text = "This is a nice day";

    char *file = mmap(NULL, strlen(text), PROT_READ | PROT_WRITE, MAP_SHARED, myfd, 0);

    ftruncate(myfd, strlen(text));
    for (int i = 0; i < strlen(text); i++){
      file[i] = text[i];}

    munmap(file, strlen(text));

    return 0;
}