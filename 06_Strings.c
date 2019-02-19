#include <stdio.h>
#include <string.h>
/* Strings are actually one-dimensional array of characters terminated by a null character '\0'. */
/*
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greeting[] = "Hello";
*/
void main(){
    char str1[12] = "Hello ";
    char str2[12] = "World ";
    char str3[12];
    int  len ;

    /* copy str1 into str3 */
    strcpy(str3, str1);
    printf("strcpy( str3, str1) :  %s\n", str3 );

    /* concatenates str1 and str2 */
    strcat( str1, str2);
    printf("strcat( str1, str2):   %s\n", str1 );

    /* total lenghth of str1 after concatenation */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len );

    /* void *memcpy(void *str1, const void *str2, size_t n) */
    memcpy( str2, str1, strlen(str1) + 1 );
    printf("memcpy( str1, str2):   %s\n", str2 );

    /* strcmp(s1, s2);
    Returns 0 if s1 and s2 are the same;
    less than 0 if s1<s2; greater than 0 if s1>s2. */
    printf("strcmp( str1, str2 ): %i\n", strcmp( str1, str2 ));

    /* char *strchr(const char *str, int c)
    Returns a pointer to the first occurrence of character ch in string s1. */
    printf("strchr( str1, ch ): %s\n", strchr( str1, 'H' ));

    /* char *strstr(const char *s1, const char *s2);
    Returns a pointer to the first occurrence of string s2 in string s1.  */
    printf("strstr( str1, str2 ): %s\n", strstr( str1, "World" ));

}
