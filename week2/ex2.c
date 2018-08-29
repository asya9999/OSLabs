#include <stdio.h>
#include <string.h>


int main() {

    char name[1000];
    char reverse[1000];
    
    scanf("%s", name);
    for (int i = 0; i <  strlen(name); i++) {
        reverse[i] = name[ strlen(name) - i -1];
    }

    puts(reverse);
    
    return 0;
}
