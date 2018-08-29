#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;    /* save the value at address x */
    *x = *y;      /* put y into x */
    *y = temp;    /* put temp into y */
    
    return;
}

int main()
{
    int firstNumber, secondNumber;
    
    printf("1st");
    scanf("%d", &firstNumber);
    
    printf("2nd");
    scanf("%d",&secondNumber);
    
    swap(&firstNumber, &secondNumber);
    
    printf("%d, %d \n", firstNumber, secondNumber);
    
    return 0;
}
