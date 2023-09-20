/*
*       Name: Zachary Osborn 
*       Student ID: 9083623414
*
*
*  General overflow. 
*  Can happen during calculation errors. Since the Integers we are using are 32-bits signed integer, overflow happens when 
*   our Integer gets larger then 2,147,483,647 (MAX_INT) or smaller then -2,147,483,648 (MIN_INT).
* 
*       a. For addition: 
*             Overflow use cases:
*                   1. the result is 0, when x != (-y)
*                   2. result is negative when both inputs are positive, If (+) + (+) != (+)
*                   3. result is positive when both inputs are negative, If (-) + (-) != (-)
*                   4. x > Max_Int - y, result would be larger then MAX_INT, if not false. 
*
*       b. For subtraction: 
*             Overflow use cases:
*                   1. the result is 0, when x != y
*                   2. result is negative when x is positive but y is negative, If (+) - (-) != (+)
*                   3. result is positive when x is negative but y is positive, If (-) - (+) != (-)
*                   4. x > MIN_Int + y, result would be smaller then MIN_INT, if not false. 
*
*       c. For Multiplication: This is harder since the product is a lot larger then the input values. 
*           Results can get very large quickly and can be hard to check the overflow value.  
*               Overflow use cases: 
*                   1. if both are positive number => result will be positive 
*                   2. if both are negative number => result will be positive 
*                   3. if one is a negative number => result will be negative
*                   4. x does not equal the result divided by y. 
*       d. For division: 
*               Overflow use cases:
*                   1.The only over flow to check of is if x == MIN_Int and y == -1, the result would be MAX_INT+1
*/

#include <stdio.h>

/******Constents, headers for functions, and helper functions.******/
int MAX_INT = 2147483647;
int MIN_INT = -2147483648;

//make printing errors easier
void printErrorStatement(char* functionName) {
    printf("\n\n******Error: Overflow with %s******", functionName);
    return;
}
/********************************************************************/

/*
*   Addition function
*   @param int x and int y
*   @return result, if no integer overflow, else return Error statement and -1
*/
int add(int x, int y) {
    int result = x + y;
    //Check for overflow
    if ((result == 0 && (x != (-y))) //Checks for a.1. from above
        || (x > 0 && y > 0 && result < 0 ) //Checks for a.2. from above
        || (x < 0 && y < 0 && result > 0 ) //Checks for a.3. from above
        || (x > MAX_INT - y) //Checks for a.4. from above
        ) {
            char str[] = "Addition";
            printErrorStatement(str);
            return -1;
    }
    return result;
}

/*
*   Subtract function
*   @param int x and int y
*   @return result, if no integer overflow, else return Error statement and -1
*/
int subtract(int x, int y) {
    int result = x - y;
    //Check for overflow
    if ((result == 0 && (x != y)) //Checks for b.1. from above
        || (x > 0 && y < 0 && result < 0) //Checks for b.2. from above
        || (x < 0 && y < 0 && result > 0) //Checks for b.3. from above
        || (x < MIN_INT + y) //Checks for b.4. from above
        ) {
            char str[] = "Subtraction";
            printErrorStatement(str);
            return -1;
    }
    return result;
}

/*
*   Multiply function
*   @param int x and int y
*   @return result, if no integer overflow, else return Error statement and -1
*/
int multiply(int x, int y) {
    int result = x * y;
    //Returns 0 if either of the inputs are zero
    if (x == 0 ||y == 0){
        return 0;
    }
    //Check for overflow cases
    else if ((x < 0 && y > 0 && result > 0) //Checks for c.1. from above
        || (x > 0 && y < 0 && result < 0) //Checks for c.2. from above
        || (x > 0 && y > 0 && result < 0) //Checks for c.3. from above
        || (x != result / y)   //Checks for c.4. from above
        ) {
            char str[] = "Multiply";
            printErrorStatement(str);
            return -1;
    }
    return result;
}

/*
*   Divide function
*   @param int x and int y
*   @return result, if no integer overflow, else return Error statement and -1
*/
int divide(int x, int y) {
    //Only use case for division
    if (x == MIN_INT && y == -1) { // Checks for d.1 from above
        char str[] = "Division";
        printErrorStatement(str);
        return -1;
    }
    else if (y == 0) {
        char str[] = "Divide";
        printErrorStatement(str);
        return -1;
    }
    int result = x/y;
    return result;
}

int main() {
    printf("\n-----------------Addition------------------------");
    //Tests add with small inputs - should pass
    int x = 5;
    int y = 15;
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Tests inputs that are inverses - should pass
    x = 0;
    y = 0;
    x = -10;
    y = 10; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Tests positive overflow - should fail 
    x = 0;
    y = 0;
    x = 2147483646;
    y = 10; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Tests negative overflow - should fail
    x = 0;
    y = 0;
    x = -147483646;
    y = -2000000002; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    //Tests result as zero but from overflow - should fail
    x = 0;
    y = 0;
    x = 2147483647;
    y = 1; 
    printf("\n%i + %i = %i", x, y, add(x,y));

    /************************************************/

     printf("\n\n-------------------Subtraction----------------------");

    //Tests subtract with small inputs - should pass
    int a = 5;
    int b = 15;
    printf("\n%i - %i = %i", a, b, subtract(a,b));

    //Tests inputs that are same - should pass
    a = 0;
    b = 0;
    a = 10;
    b = 10; 
    printf("\n%i + %i = %i", a, b, subtract(a,b));

    //Tests negative overflow - should fail 
    a = 0;
    b = 0;
    a = -2147483648;
    b = 15;
    printf("\n%i - %i = %i", a, b, subtract(a,b));

    //Test positive overflow - should fail
    a = 0;
    b = 0;
    a = 2;
    b = -2147483647;
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
    
    //Subtract w/ positive larger numbers - Should have overflow
    i = 0;
    j = 0;
    i = 47000;
    j = 47000;
    printf("\n%i * %i = %i", i, j, multiply(i,j));

    /************************************************/

    printf("\n\n-------------------Divide----------------------");

    //Divide with small numbers - should pass
    int e = 5;
    int f = 15;
    printf("\n%i * %i = %i", e, f, divide(e,f));

    //Divide with use case numbers - should fail 
    e = 0;
    f = 0;
    e = MIN_INT;
    f = -1;
    printf("\n%i * %i = %i", e, f, divide(e,f));

    printf("\n-----------------------------------------\n");

}