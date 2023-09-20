#include <stdio.h>

/*
*  General overflow. 
*  Can happen during calculation errors. Since the Integers we are using are 32-bits, overflow happens when 
*   our Integer gets larger then (2^32)+1 [4294967297] or -(2^32)-1 [-4294967297]. 
*       - For addition: 
*           x + y > 4294967297 => buffer overflow 
*               so if 4294967297 - x > y => no buffer overflow. 
*       - For subtraction: 
*           x - y < -4294967297 => buffer overflow
*/