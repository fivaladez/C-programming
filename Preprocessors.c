/*
A C Preprocessor is just a text substitution tool and it instructs the compiler
to do required pre-processing before the actual compilation.

Directives:
#define     - Substitutes a preprocessor macro.
#include    - Inserts a particular header from another file.
#undef      - Undefines a preprocessor macro.
#ifdef      - Returns true if this macro is defined.
#ifndef     - Returns true if this macro is not defined.
#if         - Tests if a compile time condition is true.
#else       - The alternative for #if.
#elif       - #else and #if in one statement.
#endif      - Ends preprocessor conditional.
#error      - Prints error message on stderr.
#pragma     - Issues special commands to the compiler, using a standardized method.

Examples:
- #include <stdio.h>        - get stdio.h from System Libraries
- #include "myheader.h"     - get myheader.h from the local directory
- Include guard:
#ifndef MESSAGE
    #define MESSAGE "You wish!"
#endif

Predefined Macros:
__DATE__        - The current date as a character literal in "MMM DD YYYY" format.
__TIME__        - The current time as a character literal in "HH:MM:SS" format.
__FILE__        - This contains the current filename as a string literal.
__LINE__        - This contains the current line number as a decimal constant.
__STDC__        - Defined as 1 when the compiler complies with the ANSI standard.

*/

#include <stdio.h>

/* Preprocessor Operators:
   - The Macro Continuation (\) Operator -> is used to continue a macro that is too long for a single line
   - The Stringize (#) Operator -> when used within a macro definition, converts a macro parameter into a string constant
    */
#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")

#ifndef MESSAGE
    #define MESSAGE "You wish!"
#endif

#define MAX(x,y) ((x) > (y) ? (x) : (y)) /* NOTE: Similar to a Lambda expression in Python*/

void main() {
    /* Predefined Macros */
   printf("File :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );

   message_for(Carole, Debra);

   printf("Here is the message: %s\n", MESSAGE);

   printf("Max between 20 and 10 is %d\n", MAX(10, 20));

}
