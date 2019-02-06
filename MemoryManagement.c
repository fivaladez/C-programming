/*
The C programming language provides several functions for memory allocation and management.
These functions can be found in the <stdlib.h> header file.

    - void *calloc(int num, int size);
    This function allocates an array of num elements each of which size in bytes will be size.

    - void free(void *address);
    This function releases a block of memory block specified by address.

    - void *malloc(int num);
    This function allocates an array of num bytes and leave them uninitialized.

    - void *realloc(void *address, int newsize);
    This function re-allocates memory extending it upto newsize.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

   char name[100];
   char *description;

   strcpy(name, "Zara Ali");

   /* allocate memory dynamically */
   description = malloc( 200 * sizeof(char) );

   if( description == NULL ) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   } else {
      strcpy( description, "Zara ali a DPS student in class 10th");
   }

   printf("Name = %s\n", name );
   printf("Description: %s\n", description );

   char *str;

   /* Initial memory allocation */
   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);

   free(str);
}
