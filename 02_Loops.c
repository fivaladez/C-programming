#include <stdio.h>

void main(){
    /*Initialization of variables*/
    int a = 0;
    char b = '\0';
    float c = 0;
    double d = 0;
    int* p = NULL;
    /* ====================== */
    int index;
    printf("\n");
    for(index = 0; index < 10; index++){
        if( 5 < index){
            printf("\n\tNow index is %i", index);
            break;/*It stops the loop*/
        }else if( 3 == index ){
            printf("\n\tNow index is %i and the rest of the loop will be skiped", index);
            continue;/*Stops the current iteration and starts the next one*/
        }else if( 30 == index ){
            LABEL:printf("\n\tArrive here is IMPOSIBLE unless you use goto label");
        }else if( 2 == index ){
            goto LABEL;/*Jumps to the defined label in code*/
        }
        printf("  %i\n", index);
    }
}
