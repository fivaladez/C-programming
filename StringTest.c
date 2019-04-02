#include <stdio.h>
#include <string.h>

void main()
{
    char first_name[12] = "";
    char last_name[12]  = "";
    char complete_name[25] = "";

    printf("\n\n    Introduce your FIRST name: ");
    fflush(stdin);
	gets(first_name);

    printf("\n\n    Introduce your LAST name: ");
    fflush(stdin);
	gets(last_name);

    strcpy( complete_name, first_name);
    strcat( complete_name, " ");
    strcat( complete_name, last_name);

    printf("\n\n    Your COMPLETE name is: %s", complete_name);

    printf("\n\n    Your COMPLETE length name is: %d", strlen( complete_name ) );

    printf("\n\n    Is 'Valadez' in your COMPLETE name?" );

    if( NULL != strstr( complete_name, "Valadez" ) )
    {
        printf("\n    Yes, it is \n");
    }else
    {
        printf("\n    No, it isn't\n");
    }

    printf( "\n\n This the content of the variable before clean it: %s", complete_name );
    strcpy( complete_name, " ");
    printf( "\n\n This is the content of the variable now: %s", complete_name );



    getchar();//pause



}
