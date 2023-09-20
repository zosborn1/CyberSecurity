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

/*Constents, headers for functions, and helper functions.*/
int MAX_INT = 2147483647;

//So functions can use eachother
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

//make printing errors easier
void printErrorStatement(char* functionName) {
    printf("\n\n******Error: Overflow with %s******", functionName);
    return;
}
/**************************************/

int add(int x, int y) {
    //Check to make sure y is possitive, if not, send to subtract
    if (y < 0) {
        printf("\n\n******Add reroute: second value was negative, going to subtract() ******");
        y = y * -1;
        return subtract(x, y);
    }
    //Since y is positive the addition will take place
    int result = x + y;
    //Throw error when result is less then the inputs. 
    if ((result < x) || (result < y) || (result - x != y) || (result == 0)) {
        char str[] = "Addition, one number is too large";
        printErrorStatement(str);
        return -1;
    }
    return result;
}

int subtract(int x, int y) {
    //Check to make sure y is possitive, if not, send to addition
    if (y < 0) {
        printf("\n\n******Subtract reroute: second value was negative, going to add() ******");
        y = y * -1;
        return add(x,y);
    }
    //Since y is possitive the subtraction will take place
    int result = x - y;
    //Throw error 
    if ((result + y != x) || (result == 0)) {
        char str[] = "Subtraction";
        printErrorStatement(str);
        return -1;
    }
    return result;
}

int multiply(int x, int y) {
    int result = x * y;
    if (x == 0 || y == 0 || x != result / y) {
        char str[] = "Multiply";
        printErrorStatement(str);
        return -1;
    }
    return result;
}

int divide(int x, int y) {
    int result = x/y;
    if (y == 0) {
        char str[] = "Divide";
        printErrorStatement(str);
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
        
    //Addition w/ negative number - Should reroute to subtract
    int e = 10;
    int f = -2; 
    printf("\nPassing test, 10 + (-2) = %i", add(e,f));

    //Addition w/ positives - Should have overflow
    int a = 2147483646;
    int b = 10; 
    printf("\nFailing test, 2147483646 + 10 != %i", add(a,b));

    //Addition w/ positives large numbers - Should have overflow
    int c = 147483646;
    int d = 2000000002; 
    printf("\nFailing test, 147483646 + 2000000002 != %i", add(c,d));

    printf("\n-----------------------------------------\n");

    /************************************************/

    //Subtract w/ positive & positive - should pass
    int g = 5;
    int h = 15;
    printf("\nPassing test, 5 - 15 = %i", subtract(g,h));

    printf("\n-----------------------------------------\n");

     /************************************************/

}