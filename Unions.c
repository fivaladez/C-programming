#include <stdio.h>
#include <string.h>
/* A union is a special data type available in C that allows to store different data types in the same memory location. */

union Data {
    int i;
    float f;
    char str[20];
};
void main(){
    union Data data;
    printf( "Memory size occupied by data : %d\n", sizeof(data));

    data.i = 10;
    printf( "data.i : %d\n", data.i);

    data.f = 220.5;
    printf( "data.f : %f\n", data.f);
    
    strcpy( data.str, "C Programming");
    printf( "data.str : %s\n", data.str);
}
