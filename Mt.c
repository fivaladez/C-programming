#include <stdio.h>
#include <string.h>

unsigned char a = 5;

#define MACRO1  1u
#define MACRO2  a

int main()
{
    //printf("\n Espacio de memoria de MACRO1: %p",  &MACRO1);
    printf("\n Espacio de memoria de MACRO2: %p",  &MACRO2);
    printf("\n Espacio de memoria de a:      %p",  &a);

    printf("\n\n Espacio ucupado por MACRO1: %i",  sizeof(MACRO1) );
    printf("\n Espacio ucupado por MACRO2: %i",  sizeof(MACRO2) );
    printf("\n Espacio ucupado por a:      %i",  sizeof(a) );

    char str[50] = {0};
    strcpy(str,"This is string.h library function");
    puts(str);

    memset(str, MACRO1 ,7);
    puts(str);

    strcpy(str,"This is string.h library function 2");
    puts(str);

    //memcpy(str, &MACRO1, 1);
    memcpy(str, &MACRO2, 1);
    puts(str);

    return 0;
}
