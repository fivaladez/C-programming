#include <stdio.h>

/*Declaration of functions*/
void myFunction1( int* param, int size );
void myFunction2( int param[5] );
void myFunction3( int param[], int size );

int * myFunction();

void main () {
/*One dimensional Array*/
 int myArray[5] = {0,1,2,3,4};
 /*Two dimensional Array where: first bracket = rows, second bracket = colums*/
 int myBiArray[3][2] = {
     {0,1},
     {2,3},
     {4,5}
 };
int i, j;

for( i = 0; 5 > i; i++ ){
    printf("myArray[%d] = %d\n", i, myArray[i] );
}

for ( i = 0; 3 > i; i++ ) {
     for ( j = 0; 2 > j; j++ ) {
        printf("a[%d][%d] = %d\n", i,j, myBiArray[i][j] );
     }
  }

/* === Passing Arrays as function parameters === */
/*
    There are 3 ways:
    - As a pointer:     void myFunction(int *param, int size){}
    - As sized array:   void myFunction(int param[5]){}
    - As unsized array: void myFunction(int param[], int size){}
*/
myFunction1( &myArray[0], 5 );
myFunction2( myArray );
myFunction3( myArray , 5);
/* === Return Arrays from functions === */
/*
    There are only one way to do it:
    - Return a pointer to the array: int * myFunction() {}
     Also, the arrays MUST be STATIC to have a defined memory alocation to pass
*/
int *p;
p = myFunction();
for ( i = 0; i < 3; i++ ) {
     printf( "*(p + %d) : %d\n", i, *(p + i));
}
}

/*Definition of functions*/
void myFunction1( int* param, int size ){
    int i;
    for( i = 0; size > i; i++ ){
        printf("    In function 1 the array[%i] is %i\n", i, *(param + i) );
    }
    printf("    ======    \n");
}
void myFunction2( int param[5] ){
    int i;
    for( i = 0; 5 > i; i++ ){
        printf("    In function 2 the array[%i] is %i\n", i, param[i] );
    }
    printf("    ======    \n");
}
void myFunction3( int param[], int size ){
    int i;
    for( i = 0; size > i; i++ ){
        printf("    In function 3 the array[%i] is %i\n", i, param[i] );
    }
    printf("    ======    \n");
}
int * myFunction() {
    static int myArrayReturn[3] = {5,7,9};
    return myArrayReturn;/*Returns the memory direction of the array*/
}
