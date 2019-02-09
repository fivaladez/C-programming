#include <stdio.h>
/* FILE *fopen( const char * filename, const char * mode ); */
/* MODES:
- r -> Opens an existing text file for reading purpose.
- w -> Opens a text file for writing. If it does not exist, then a new file is created.
- a -> Opens a text file for writing in appending mode. If it does not exist, then a new file is created.
- r+ -> Opens a text file for both reading and writing.
- w+ -> Opens a text file for both reading and writing. It first truncates the file to zero
        length if it exists, otherwise creates a file if it does not exist.
- a+ -> Opens a text file for both reading and writing. It creates the file if it does not exist.
        The reading will start from the beginning but writing can only be appended.
- Binary files: add a letter "b" -> "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
*/
/* int fclose( FILE *fp ); function returns zero on success, or EOF if there is an error in closing the file */
void main(){
    FILE *fp;

    fp = fopen("test.txt", "w+");/*Open or create a file*/
    /* int fprintf(FILE *fp,const char *format, ...) */
    fprintf(fp, "This is testing for fprintf...\n");/*write a string into a file*/
    /* int fputs( const char *s, FILE *fp ); */
    fputs("This is testing for fputs...\n", fp); /* wr ites the string s to the output stream referenced by fp */
    /* int fputc( int c, FILE *fp ); */
    fputc( 'a', fp ); /* writes the character value of the argument c to the output stream referenced by fp */
    /* size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) */
    fwrite("\nThis is testing for fwrite...\n", sizeof(char), 30, fp);
    fclose(fp);

    char buff[255];
    fp = fopen("test.txt", "r");

    fscanf(fp, "%s", buff);
    printf("1 : %s\n", buff );

    /* char *fgets( char *buf, int n, FILE *fp ); */
    fgets(buff, 255, (FILE*)fp); /* reads up to n-1 characters from the input stream referenced by fp.
    It copies the read string into the buffer buf, appending a null character to terminate the string.*/
    printf("2: %s\n", buff );

    fgets(buff, 255, (FILE*)fp);/* Reads next line */
    printf("3: %s\n", buff );

    char c;
    /* int fgetc( FILE * fp ); */
    c = fgetc( fp );
    printf("4: %c\n", c );

    char buff2[255] = {0};
    /* size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) */
    fread(buff, sizeof(char), 255, fp);
    printf("5: %s\n", buff );

    fclose(fp);
}
