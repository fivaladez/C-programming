#include <stdio.h>

void imprimiendo_hola(int x)
{
   printf( "[*HOLA__] Hola número %d\n", x);
}

void imprimiendo_adios(int x, void (*ptr_func)())
{
   printf( "[*ADIOS_] Adios número %d\n", x);
   if(ptr_func!=NULL)
   {
     ptr_func();  //Usando el puntero para retrollamar
   }
}

void func_call_back()
{
   printf( "[*RETRO_] Retrollamada llamada\n");
}

void main()
{   // Definimos dos punteros a funciones
   void (*ptr_func_1)(int)=NULL;
   void (*ptr_func_2)(int, void (*call_back_func)() )=NULL;

   //Usamos el primero
   ptr_func_1 = imprimiendo_hola;
   printf("[*MAIN__] La dirección del primer puntero is %p\n",ptr_func_1);
   ptr_func_1(3);
   
   //Usamos el segundo
   ptr_func_2 = imprimiendo_adios;
   printf("[*MAIN__] Using a callback función \n",ptr_func_2);
   ptr_func_2(3,func_call_back);

}
