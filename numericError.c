#include <stdio.h>

/*
*  General overflow. 
*  Can happen during calculation errors. Since the Integers we are using are 32-bits, overflow happens when 
*   our Integer gets larger then (2^32)+1 [4294967297] or -(2^32)-1 [-4294967297]. 
*       - For addition: 
*           x + y > 4294967290 => buffer overflow  
*       - For subtraction: 
*           x - y < -4294967297 => buffer overflow
*/
int UpperOverFlow = 4294967295;

int add(int x, int y) {
    int result = x + y;
    if (x > UpperOverFlow - y) {
        printf("\n\n******Error: Overflow with addition******");
        return -1;
    }
    return result;
}

int subtract(int x, int y) {
    int result = x - y;
    if ((result > x) || (result < -4294967296)) {
        printf("\n\n******Error: Overflow with subtration******");
        return -1;
    }
    return result;
}

int main() {
    //Addition - should pass 
    int x = 5;
    int y = 15;
    printf("\nPassing test, 5 + 15 = %i", add(x,y));

    //Addition - Should have overflow
    int a = 4294967290;
    int b = 10; 
    printf("\nFailing test, 4294967290 + 10 != %i", add(a,b));
    printf("\n");

    /************************************************/
}