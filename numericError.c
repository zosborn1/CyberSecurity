/*
*       Name: Zachary Osborn 
*       Student ID: 9083623414
*
*
*  General overflow. 
*  Can happen during calculation errors. Since the Integers we are using are 32-bits signed integer, overflow happens when 
*   our Integer gets larger then 2,147,483,647 or smaller then -2,147,483,648. 
*       - For addition: 
*             Checking for overflow can come from making sure:
*                   - the result isnt 0, when x != (-y)
*                   - the result is larger then one input. 
*       - For subtraction: 
*             Checking for overflow can come from making sure:
*                   - the result isnt 0, when x != (-y)
*                   - result is not larger then the first input, unless one input is negative.
*       - For Multiplication: 
*             Checking for overflow can come from making sure:
*                   - The inputs do not equal 0
*                   - the reverce of the multiplication cant happen
*                   - if both are positive number => result will be positive 
*                   - if one is a negative number => result will be negative
*       - For division: 
*             Since the numbers are intergers and not floats, there will be no overflows. Only check would be that y is not 0. 
*/

#include <stdio.h>

/******Constents, headers for functions, and helper functions.******/
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
/********************************************************************/

int add(int x, int y) {
    //Check to make sure y is possitive, if not, send to subtract
    if (y < 0) {
        printf("\n\n******Add reroute: second value was negative, going to subtract() ******");
        y = y * -1;
        return subtract(x, y);
    }
    //Since y is positive the addition will take place
    int result = x + y;
    //Throw error 
    if ((result < x) 
        || (result == 0 && (x != (-y)))) {
            char str[] = "Addition";
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
    if ((result > x) 
        || (result == 0 && (x != (-y)))) {
            char str[] = "Subtraction";
            printErrorStatement(str);
            return -1;
    }
    return result;
}

int multiply(int x, int y) {
    int result = x * y;
    if (x == 0 
        || y == 0 
        || (x != result / y) 
        || (x < 0 && y > 0 && result > 0)
        || (x > 0 && y < 0 && result > 0)
        || (x > 0 && y > 0 && result < 0)) 
        {
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
    return result;
}

int main() {
    printf("\n-----------------Addition------------------------");
    //Addition w/ positives - Should pass 
    int x = 5;
    int y = 15;
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Addition that comes to 0 - Should not overflow
    x = 0;
    y = 0;
    x = -10;
    y = 10; 
    printf("\n%i + %i = %i", x, y, add(x,y));
        
    //Addition w/ negative number - Should reroute to subtract
    x = 0;
    y = 0;
    x = 10;
    y = -2; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Addition w/ positives - Should have overflow
    x = 0;
    y = 0;
    x = 2147483646;
    y = 10; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Addition w/ positives large numbers - Should have overflow
    x = 0;
    y = 0;
    x = 147483646;
    y = 2000000002; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Addition that comes to 0 - Should have overflow
    x = 0;
    y = 0;
    x = 2147483647;
    y = 1; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    /************************************************/

     printf("\n\n-------------------Subtraction----------------------");

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
    a = -2147483648;
    b = 15;
    printf("\n%i - %i = %i", a, b, subtract(a,b));

    //Subtract w/ small negative and large number - Should have overflow
    a = 0;
    b = 0;
    a = -2;
    b = 2147483647;
    printf("\n%i - %i = %i", a, b, subtract(a,b));

    /************************************************/

     printf("\n\n-------------------Multiply----------------------");

    //Multiply with small numbers - should pass
    int i = 5;
    int j = 15;
    printf("\n%i * %i = %i", i, j, multiply(i,j));
    
    //Subtract w/ positive large and negative small - Should  pass
    i = 0;
    j = 0;
    i = -500;
    j = 47000;
    printf("\n%i * %i = %i", i, j, multiply(i,j));

    //Subtract w/ large positive but small negative - Should pass
    i = 0;
    j = 0;
    i = 1073741824;
    j = -2;
    printf("\n%i * %i = %i", i, j, multiply(i,j));

    //Subtract w/ two negative but gives too large possitive - Should have overflow
    i = 0;
    j = 0;
    i = -1073741824;
    j = -2;
    printf("\n%i * %i = %i", i, j, multiply(i,j));

    //Subtract w/ negative large and positive small - Should pass
    i = 0;
    j = 0;
    i = 500;
    j = -47000;
    printf("\n%i * %i = %i", i, j, multiply(i,j));
    
    //Subtract w/ positive larger numbers - Should have overflow
    i = 0;
    j = 0;
    i = 47000;
    j = 47000;
    printf("\n%i * %i = %i", i, j, multiply(i,j));

    printf("\n-----------------------------------------\n");

}