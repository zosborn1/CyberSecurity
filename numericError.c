#include <stdio.h>

/*
*  General overflow. 
*  Can happen during calculation errors. Since the Integers we are using are 32-bits, overflow happens when 
*   our Integer gets larger then (2^32)+1 [4294967297] or -(2^32)-1 [-4294967297]. 
*       - For addition: 
*           x + y > 4294967290 => buffer overflow 
*               so if 4294967290 - x > y => no buffer overflow. 
*       - For subtraction: 
*           x - y < -4294967297 => buffer overflow
*/
int UpperOverFlow = 4294967295;

int add(int x, int y) {
    int result = x + y;
    if ((result < x) || (result < y)) {
        printf("\n******Error: Overflow with addition******");
        return -1;
    }
    return result;
    // if ((x < UpperOverFlow) && (y < (UpperOverFlow - x))) {
    //     return x + y;
    // }
    // else {
    //     printf("\nError: Overflow with Add()");
    //     return -1;
    // }
}

int main() {
    //Addition - should pass 
    int x = 5;
    int y = 15;
    printf("\n1st addition test: %i", add(x,y));

    //Addition - Should have overflow, testing large x value
    int a = 4294967290;
    int b = 10; 
    printf("\n2nd addition test: %i", add(a,b));
    printf("\n");
}