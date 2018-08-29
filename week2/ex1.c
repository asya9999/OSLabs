#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    
    printf("%d\n", i);
    printf("%f\n", f);
    printf("%f\n", d);
    
    printf("%d\n", (int)sizeof(i));
    printf("%d\n", (int)sizeof(f));
    printf("%d\n", (int)sizeof(d));
    
    return 0;
}
