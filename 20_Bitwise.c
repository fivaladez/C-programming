#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    unsigned int a = 60;	/* 60 = 0011 1100 */
    unsigned int b = 13;	/* 13 = 0000 1101 */
    int c = 0;

    c = a & b;       /* 12 = 0000 1100 */
    printf("Line 1 - Value of c is %d\n", c );

    c = a | b;       /* 61 = 0011 1101 */
    printf("Line 2 - Value of c is %d\n", c );

    c = a ^ b;       /* 49 = 0011 0001 */
    printf("Line 3 - Value of c is %d\n", c );

    c = ~a;          /*-61 = 1100 0011 */
    printf("Line 4 - Value of c is %d\n", c );

    c = a << 2;     /* 240 = 1111 0000 */
    printf("Line 5 - Value of c is %d\n", c );
    /*
    Binary Left Shift Operator <<
    The left operands value is moved left by the number of bits specified by the right operand.
    */
    c = a >> 2;     /* 15 = 0000 1111 */
    printf("Line 6 - Value of c is %d\n", c );
    /*
    Binary Right Shift Operator >>
    The left operands value is moved right by the number of bits specified by the right operand.
    */
    c = a << 1;/* Divide a by 2; c = 120*/
    printf("Line 7 - Value of c is %d\n", c );
    c = a >> 1;/* Multiply a by 2; c = 30*/
    printf("Line 8 - Value of c is %d\n", c );


}
