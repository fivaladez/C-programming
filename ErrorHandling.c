#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno ;

void main () {

   FILE * pf;
   int errnum;
   pf = fopen ("unexist.txt", "rb");

   if (pf == NULL) {

      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno);
      perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
   } else {

      fclose (pf);
   }
   /* =================================== */

   int dividend = 20;
   int divisor = 0;
   int quotient;

   if( divisor == 0){
      fprintf(stderr, "Division by zero! Exiting...\n");
      exit(-1);/*exit(EXIT_FAILURE);*/
   }

   quotient = dividend / divisor;
   fprintf(stderr, "Value of quotient : %d\n", quotient );

   exit(0);/*exit(EXIT_SUCCESS);*/

   /*
   It is a common practice to exit with a value of EXIT_SUCCESS in case of program coming out after
   a successful operation. Here, EXIT_SUCCESS is a macro and it is defined as 0.

   If you have an error condition in your program and you are coming out then you should exit
   with a status EXIT_FAILURE which is defined as -1.
   */
}
