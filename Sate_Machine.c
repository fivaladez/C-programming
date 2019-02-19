#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void geen_sate_function( int *ptr );
void yellow_sate_function( int *ptr );
void red_sate_function( int *ptr );

void (*state_machine[3])( int *ptr ) =
{
    geen_sate_function,
    yellow_sate_function,
    red_sate_function
};

enum
{
    eGREEN_STATE = 0,
    eYELLOW_STATE = 1,
    eRED_STATE = 2
};

int state = eGREEN_STATE;

void vfDelay(int long Time);

void main()
{
    for(;;)
    {
        (state_machine[state])( &state );
    }
}

void vfDelay(int long Time)
{
    while(Time--);
}

void geen_sate_function( int * ptr )
{
    printf("\n\n    You are in green state: %d", *ptr);
    vfDelay(100000);
    *ptr = eYELLOW_STATE;
}
void yellow_sate_function( int * ptr )
{
    printf("\n\n    You are in yellow state: %d", *ptr);
    vfDelay(100000);
    *ptr = eRED_STATE;
}
void red_sate_function( int * ptr )
{
    printf("\n\n    You are in red state: %d", *ptr);
    vfDelay(100000);
    *ptr = eGREEN_STATE;
}
