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
    printf("\n%i and %i\n", (result + y), x);
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
    printf("\n%i - %i = %i", x, y, add(x,y));
        
    //Addition w/ negative number - Should reroute to subtract
    x = 0;
    y = 0;
    x = 10;
    y = -2; 
    printf("\n%i - %i = %i", x, y, add(x,y));

    //Addition w/ positives - Should have overflow
    x = 0;
    y = 0;
    x = 2147483646;
    y = 10; 
    printf("\n%i - %i = %i", x, y, add(x,y));

    //Addition w/ positives large numbers - Should have overflow
    x = 0;
    y = 0;
    x = 147483646;
    y = 2000000002; 
    printf("\n%i - %i = %i", x, y, add(x,y));

    printf("\n-----------------------------------------\n");

    /************************************************/

    //Subtract w/ positive & positive - should pass
    int a = 5;
    int b = 15;
    printf("\n%i - %i = %i", a, b, subtract(a,b));
    
    //Subtract w/ positive & negative - Should reroute to add
    a = 0;
    b = 0;
    a = 5;
    b = -15;
    printf("\n%i - %i = %i", a, b, subtract(a,b));

    //Subtract w/ large negative - Should have overflow
    a = 0;
    b = 0;
    a = -3147483646;
    b = 15;
    printf("\n%i - %i = %i", a, b, subtract(a,b));

    printf("\n-----------------------------------------\n");

     /************************************************/

}