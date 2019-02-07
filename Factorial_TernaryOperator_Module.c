#include <stdio.h>

long int getFactorial(int x);
/*
    Macros are not stored in memory anywhere in the final program
    but instead the code for the macro is repeated whenever it occurs.
    As far as the actual compiler is concerned they don't even exist,
    they've been replaced by the preprocessor before they get that far.
*/
#define MACRO_COMPARATION(a,b)   (a>b ? a : b)

int main()
{
    /*=====================================================*/
    int a = 10;
    int b = 15;
    int c = 0;
    printf(" The value a is: %i \n", a);
    printf(" The value b is: %i \n", b);

	/* Ternary Operator */
    /* Condition ? True : False */
    //c = a>b ? a : b;
    c = MACRO_COMPARATION(a,b);
    printf(" The greater value is: %i \n", c);

	/*
	This is for exchange two values
	b ends with the initial value of a*
	and a ends with the initial value of b

	NOTE: b must be greater than a to works correctly.
	Also, you can change the positions of b with a and a with b

	b = b - a; // 15-10 = 5
	a = a - b; // 10-5  = 10
	b = b + a; // 5+10  = 15
	*/

    /*=====================================================*/
    int n = 4;
    printf("\n Factorial of %d is: %ld \n", n, getFactorial(n));
    /*=====================================================*/
    int d = 13;
    printf("\n The value d is: %i \n", d);

    if ( d % 2 == 0 )
    {
        printf( " The value d is: EVEN \n " );/*Par*/
    }
    else
    {
        printf( " The value d is: ODD \n " );/*Impar*/
    }
    /*=====================================================*/


    return 0;
}

/* Recursive function */
long int getFactorial(int x)
{
    /* Control condition */
    if(x >= 1)
    {
        /* Calls itself */
        return getFactorial(x-1) * x;
    }
    else /* Break condition */
    {
        return 1;
    }

}
