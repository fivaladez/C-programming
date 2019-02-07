#include <stdio.h>

void vfMessage( char * pcName, int x);
void vfDelay(int long Time);

int main()
{
    int x = 5;
	vfMessage("Hola d %d",x);

    return 0;
}

void vfMessage( char * pcName, int x )
{
    int Index = 0;

    for( Index = 0 ; *(pcName + Index) != 0 ; Index++)
    {
        if( *(pcName + Index) == 0x25)/* Look for "%" */
        {
            if( *(pcName + Index + 1) == 0x64)/* Look for "d" */
            {
                printf("%x ", x);
                Index++;/*For not showing next value (d)*/
            }else printf("%x ", *(pcName + Index));

        }else printf("%x ", *(pcName + Index));
    }

}

void vfDelay(int long Time)
{
    while(Time--);
}
