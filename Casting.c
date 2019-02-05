/* is a way to convert a variable from one data type to another data type */

#include <stdio.h>

void main() {

   int sum = 17, count = 5;
   double mean;

   mean = (double) sum / count;
   printf("Value of mean : %f\n", mean );

   int  i = 17;
   char c = 'c'; /* ascii value is 99 */
   int sum2;
   /* float sum2; */

   sum2 = i + c;
   printf("Value of sum : %d\n", sum2 );
}
