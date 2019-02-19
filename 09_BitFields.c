#include <stdio.h>
#include <string.h>

struct {
   unsigned int age : 3;
} Age;
/* The above structure definition instructs the C compiler that the age variable is going to use only 3 bits to store the value.
   If you try to use more than 3 bits, then it will not allow you to do so*/
void main() {

    Age.age = 4;
    printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
    printf( "Age.age : %d\n", Age.age );

    Age.age = 7;
    printf( "Age.age : %d\n", Age.age );

    Age.age = 8;
    printf( "Age.age : %d\n", Age.age );

}
