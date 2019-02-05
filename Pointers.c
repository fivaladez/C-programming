#include <stdio.h>

void main(){
    int  var = 20;   /* actual variable declaration */
    int  *ip;        /* pointer variable declaration */

    ip = &var;  /* store address of var in pointer variable*/
    printf("Address of var variable: %x\n", &var  );
    /* address stored in pointer variable */
    printf("Address stored in ip variable: %x\n", ip );
    /* access the value using the pointer */
    printf("Value of *ip variable: %d\n", *ip );
    /* Null pointers*/
    int  *ptr = NULL;
    printf("The value of ptr is : %x\n", ptr  );
    /*Check for a NULL pointer*/
    /*
        - if(ptr)     succeeds if p is not null
        - if(!ptr)    succeeds if p is null
    */

    int  var2[] = {10, 100, 200};
    int  i, *ptr2, *ptr3[3];
    /* let us have array address in pointer */
    ptr2 = var2;
    for ( i = 0; i < 3; i++) {
       printf("Address of var[%d] = %x\n", i, ptr2 );
       printf("Value of var[%d] = %d\n", i, *ptr2 );
       /* move to the next location */
       ptr2++;
    }
    for ( i = 0; i < MAX; i++) {
       ptr[i] = &var[i]; /* assign the address of integer. */
    }
    for ( i = 0; i < MAX; i++) {
       printf("Value of var[%d] = %d\n", i, *ptr[i] );
    }

    int **pptr, *ptr4;
    int var3 = 3000;
    /* take the address of var */
    ptr = &var;

    /* take the address of ptr using address of operator & */
   pptr = &ptr;

    /* take the value using pptr */
    printf("Value of var = %d\n", var );
    printf("Value available at *ptr = %d\n", *ptr );
    printf("Value available at **pptr = %d\n", **pptr);

    /* To see more info about pointers, see Arrays.c file */

}
