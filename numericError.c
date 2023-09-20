#include <stdio.h>

/*
*  General overflow. 
*  Can happen during calculation errors. Since the Integers we are using are 32-bits signed integer, overflow happens when 
*   our Integer gets larger then 2,147,483,647 or smaller then -2,147,483,648. 
*       - For addition: 
*             
*       - For subtraction: 
*           x - y < -2,147,483,647 => buffer overflow
*/
int MAX_INT = 2147483647;

void printErrorStatement(char* functionName) {
    printf("\n\n******Error: Overflow with %s******", functionName);
    return;
}

int add(int x, int y) {
    //Check to make sure y is possitive, if not, send to subtract
    if (y < 0) {
        return subtract(x, y);
    }
    //Check to see if the number are to large for the check below. 
    if (x > MAX_INT - y || y > MAX_INT - x) {

    }
    //Since y is positive the addition will take place
    int result = x + y;
    //Throw error when result is less then the inputs. 
    if ((result < x) || (result < y) || (result - x != y) || (result - y != x)) {
        //printf("\n\n******Error: Overflow with addition******");
        char str[] = "Addition";
        printErrorStatement(str);
        return -1;
    }
    return result;
}

int subtract(int x, int y) {
    //Check to make sure y is possitive, if not, send to addition
    if (y < 0) {
        return addition(x,y);
    }
    //Since y is possitive the subtraction will take place
    int result = x - y;
    //Throw error 
    if ((result > x) || (result < -4294967296)) {
        printf("\n\n******Error: Overflow with subtration******");
        return -1;
    }
    return result;
}

int multiply(int x, int y) {
    int result = x * y;
    if (x == 0 || y == 0 || x != result / y) {
        printf("\n\n******Error: Overflow with subtration******");
        return -1;
    }
    return result;
}

int divide(int x, int y) {
    int result = x/y;
    if (y == 0) {
        printf("\n\n******Error: Overflow with subtration******");
        return -1;
    }
    //Check to make sure y is not a decimal, with decimals the end result could overflow
    if (y < 1 && y > 0) {

    }
}

int main() {
    printf("\n-----------------------------------------");
    //Addition w/ positives - Should pass 
    int x = 5;
    int y = 15;
    printf("\nPassing test, 5 + 15 = %i", add(x,y));

    //Addition w/ positives - Should have overflow
    int a = 4294967290;
    int b = 10; 
    printf("\nFailing test, 4294967290 + 10 != %i", add(a,b));

    /************************************************/
}