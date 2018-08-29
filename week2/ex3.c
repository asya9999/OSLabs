//
//  main.c
//  ex3
//
//  Created by Анастасия on 29.08.2018.
//  Copyright © 2018 Анастасия. All rights reserved.
//

#include <stdio.h>
#include <math.h>
void triangle(int n){
  
        int x,y;
        for (y= 1; y <= n; y++)
        {
            for (x= 0; x < n-y; x++)
                putchar(' ');
            for (x= 0; x < 2*y-1; x++)
                putchar('*');
            putchar('\n');
        }
        
    }

int main(int argc, char**argv) {
    int n;
    sscanf(argv[1], "%d ", &n);
    triangle(n);
    
    return 0;
    
}
