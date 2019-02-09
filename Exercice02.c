/* This will be a calculator using a state machine */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char control = 0u;
int first_number = 0;
int second_number = 0;
long int result = 0;

void add(void);
void sub(void);
void multi(void);
void divi(void);

void main(){

    for(;;){
        system("cls");

        printf("        === MENU ===\n");
        printf("    1 - Addition\n");
        printf("    2 - Substraction\n");
        printf("    3 - Multiplication\n");
        printf("    4 - Division\n");
        printf("    5 - Exit\n\n");

        printf("    Introduce the option desired: ");
        fflush(stdin);
        scanf("%d", &control);

        switch(control){
            case 1: add();
                break;
            case 2: sub();
                break;
            case 3: multi();
                break;
            case 4: divi();
                break;
            case 5: exit(0);
                break;
            default: printf("\n\n   %d is not an option. Try again.", control);
                break;
        }
        system("pause");
    }
}

void add(void){

    printf("    Introduce the first number: ");
    fflush(stdin);
    scanf("%d", &first_number);

    printf("    Introduce the second number: ");
    fflush(stdin);
    scanf("%d", &second_number);

    result = first_number + second_number;
    printf("   The result is: %d\n", result);

}
void sub(void){

    printf("    Introduce the first number: ");
    fflush(stdin);
    scanf("%d", &first_number);

    printf("    Introduce the second number: ");
    fflush(stdin);
    scanf("%d", &second_number);

    result = first_number - second_number;
    printf("   The result is: %d\n", result);
}
void multi(void){

    printf("    Introduce the first number: ");
    fflush(stdin);
    scanf("%d", &first_number);

    printf("    Introduce the second number: ");
    fflush(stdin);
    scanf("%d", &second_number);

    result = first_number * second_number;
    printf("   The result is: %d\n", result);
}
void divi(void){

    printf("    Introduce the first number: ");
    fflush(stdin);
    scanf("%d", &first_number);

    printf("    Introduce the second number: ");
    fflush(stdin);
    scanf("%d", &second_number);

    result = first_number / second_number;
    printf("   The result is: %d\n", result);
}
