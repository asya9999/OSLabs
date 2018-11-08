#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int f = open("/dev/random", O_RDONLY);
    char string[21];
    //Null terminator
    string[20] = '\0';
    read(f, string, 20);
    printf("%s\n", string);
    close(f);
    return 0;
}