#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
//#include <ctype.h>
#include <string.h>

#define MESSAGE_TO(a,b) \
    printf("    Hello " #a " and " #b ", have a great day!!\n")

#define MAX_NUM(x,y) ( x>y ? x : y)

typedef struct students{
    char name[50];
    int age;
    float grade;

}student;

void initStruct( student * myStruct);
void getInfo( student * myStruct);

void main(){

    //clrscr();/* Clean the terminal */
    system("cls");/* Clean the terminal */

    student Ivan;
    student Aaron;
    initStruct( &Ivan);
    initStruct( &Aaron);

    getInfo( &Ivan );
    getInfo( &Aaron );

    printf("%s\n", Ivan.name);
    MESSAGE_TO( Ivan , Aaron );
    printf("    The max grade between Aaron and Ivan is: %.2f\n", MAX_NUM( Ivan.grade, Aaron.grade ));

    getchar();/* Pause */
    system("pause");/* Pause */
}

void initStruct( student * myStruct){

    strcpy(myStruct->name, "Francisco Valadez");
    myStruct->age = 12;
    myStruct->grade = 9.0;

    printf("    The default name is: %s\n", myStruct->name);
    printf("    The default age is: %d\n", myStruct->age);
    printf("    The default grade is: %d\n", myStruct->grade);
    printf("    =====   \n\n");
}

void getInfo( student * myStruct){
    /*printf("\n    Intoduce your first name: ");
    scanf("%s", myStruct->name);
    char temporaryName[50];
    printf("\n    Intoduce your last name: ");
    scanf("%s", temporaryName);
    strcat( myStruct->name, " ");
    strcat( myStruct->name, temporaryName);*/
    printf("\n    Intoduce your first and last name: ");
    fflush(stdin);/*Use this ALWAYS to erase buffer in console before use function gets()*/
    gets( myStruct->name );

    printf("    Hello  %s\n", myStruct->name );

    printf("\n    Intoduce your age: ");
    scanf("%i", &myStruct->age);
    printf("    Your age is %i\n", myStruct->age );

    printf("\n    Intoduce your grade: ");
    scanf("%f", &myStruct->grade);
    printf("    Your grade is %.2f\n", myStruct->grade );
}
