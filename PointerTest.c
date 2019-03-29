#include <stdio.h>

void main()
{
    short int a = 0;
    short int *ptr;
    ptr = &a;

    printf("\n\n    The addres of a is: %x", &a);
    printf("\n\n    The addres pinted for ptr is: %x", ptr);

    *ptr++; //Aumont of memory direction
    //*ptr = *ptr + 1;

    printf("\n\n    The addres of a is: %x", a);
    printf("\n\n    The addres pinted for ptr is: %x", ptr);

    printf("\n\n    The value of a is: %i", a);
    printf("\n\n    The value of *ptr is: %d", *ptr);
}
