#include <stdio.h>
#include <string.h>

struct Books/*tag*/ {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
/*Bit Fields*/
struct packed_struct {
   unsigned int f1:1;
   unsigned int f2:1;
   unsigned int f3:1;
   unsigned int f4:1;
   unsigned int type:4;
   unsigned int my_int:9;
} pack;
/* function declaration */
void printBook( struct Books book );
/* function declaration */
void printBookPtr( struct Books *book );

int main( ) {

    struct Books Book1;        /* Declare Book1 of type Book */
    struct Books Book2;        /* Declare Book2 of type Book */

    /* book 1 specification */
    strcpy( Book1.title, "C Programming");
    strcpy( Book1.author, "Nuha Ali");
    strcpy( Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* book 2 specification */
    strcpy( Book2.title, "Telecom Billing");
    strcpy( Book2.author, "Zara Ali");
    strcpy( Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    /* print Book1 info */
    printBook( Book1 );
    /* Print Book2 info */
    printBook( Book2 );
    printf(" ===== \n");
    /* print Book1 info by passing address of Book1 */
    printBookPtr( &Book1 );
    /* print Book2 info by passing address of Book2 */
    printBookPtr( &Book2 );

}

void printBook( struct Books book ) {

    printf( "Book title : %s\n", book.title);
    printf( "Book author : %s\n", book.author);
    printf( "Book subject : %s\n", book.subject);
    printf( "Book book_id : %d\n", book.book_id);
}
void printBookPtr( struct Books *book ){
    printf( "Book title : %s\n", book->title);
    printf( "Book author : %s\n", book->author);
    printf( "Book subject : %s\n", book->subject);
    printf( "Book book_id : %d\n", book->book_id);
}
