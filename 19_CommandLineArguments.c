/*
The command line arguments are handled using main() function arguments where argc refers to the number
 of arguments passed, and argv[] is a pointer array which points to each argument passed to the program.
*/

#include <stdio.h>

int main( int argc, char *argv[] )  {

   printf("Program name %s\n", argv[0]);

   if( argc == 2 ) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }
}
/*
It should be noted that argv[0] holds the name of the program itself and argv[1] is a pointer to
the first command line argument supplied, and *argv[n] is the last argument.
If no arguments are supplied, argc will be one, and if you pass one argument then argc is set at 2.
*/
