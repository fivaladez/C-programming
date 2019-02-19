#include <stdio.h>

void delay(unsigned long time);

void main( ) {

    int c;
    printf( " Enter a value : ");
    c = getchar( ); /* This function reads only single character at a time */

    printf( "\n You entered: ");
    putchar( c ); /* This function puts only single character at a time.  */

    delay(900000000);
    printf("\n  ======  \n");

    char str[100];
    printf( "Enter a value : ");
    gets( str ); /* reads a line from stdin into the buffer pointed to by s until either
                    a terminating newline or EOF (End of File). */

    printf( "\nYou entered: ");
    puts( str ); /* writes the string 's' and 'a' trailing newline to stdout. */

    char str2[100];
    int i;
    printf( "Enter a value :");
    scanf("%s %d", str2, &i); /* reads the input from the standard input stream stdin and
                                 scans that input according to the format provided. */

    printf( "\nYou entered: %s %d ", str2, i); /* writes the output to the standard output stream
                                stdout and produces the output according to the format provided. */
}

void delay(unsigned long time){
    while(time--);
}
