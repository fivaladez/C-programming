#include <stdio.h>      //Francisco Ivan Valadez Ruiz      No.2680741 
#include <conio.h>      //Ing.Mecatronica  2° cuatrimestre
#include <stdlib.h>      
#include <ctype.h>            //AGENDA
#include <string.h>

struct agenda  //Estructura de la agenda
{ 
	char nombre[30], direccion[30], grupo[15];
	int tel_fijo;
	int tel_movil;
	
}control;


FILE *fp,*ft;   //Apuntadores para guardar los datos en archivos
void agregar_contacto(void);
void buscar_contacto(void);
void eliminar_contacto(void);       //Prototipos de funciones
void imprimir_contactos(void);

main()
{
 int opcion;	  //Variable de control
	do
	{
		clrscr();
		printf("                 MENU     \n ");  //Despliegue de menu
		printf("        1.  Agregar contacto     \n ");
		printf("        2.  Buscar contacto     \n ");
		printf("        3.  Eliminar contacto     \n ");
		printf("        4.  Imprimir lista completa     \n ");
		printf("        5.  Salir     \n ");
		printf("  \n\n    Ingrese la opcion que desea realizar    ");
		scanf("%i", &opcion);
		
		switch(opcion)   //Llamado de funciones
		{
			case 1: agregar_contacto();
			       break;
			case 2: buscar_contacto();
			       break;
			case 3: eliminar_contacto();
			       break;
			case 4: imprimir_contactos();
			       break;
			   
		}    
		
	if(opcion > 5 )
	printf("\n La opcion no fue valida");
    getch();
		
	}while(opcion != 5); //Se saldra del programa una vez que la variable de control sea 5
	

return 0;
}

void agregar_contacto(void)  //Cuerpo de funcion
{
    clrscr();
    printf("\n Ingrese el nombre:   ");	
    fflush(stdin);
    gets(control.nombre);
	
	printf("\n Ingrese la direccion:  ");
	fflush(stdin);
	gets(control.direccion);
	
	printf("\n Ingrese el numero telefonico fijo:   ");
	fflush(stdin);
	scanf("%i",&control.tel_fijo);
	
    printf("\n Ingrese el numero telefnico movil:   "); //NOTA: Solo puede almacenar hasta 9 numeros, ni uno mas ya que despues se almacenan numeros erroneos
	fflush(stdin);
	scanf("%i",&control.tel_movil);
	
	printf("\n Ingrese el grupo al que pertenece:   ");
	fflush(stdin);
	gets(control.grupo);
	
	fp = fopen("principal.txt","a");  //Se abre archivo en modo 'a' añadir
	fwrite(&control,1,sizeof(control),fp);  //Se pasa la informacion a un archivo fuera del programa
	fclose(fp); //Se cierra archivo
	
	return ;
}


void buscar_contacto(void)
{
	char buscar_nombre[30];
	int manejo = 1;
	
	clrscr();
	printf("   \n\n Ingrese el nombre que desea encontrar :     ");
	fflush(stdin);
	gets(buscar_nombre); //Se lee el nombre
	fp = fopen("principal.txt","r");//Se abre el archivo en modo lectura
	while(fread(&control,sizeof(control),1,fp))
	{
		if(strcmp(buscar_nombre,control.nombre) == 0) //Si el nombre coincide se regresa un valor igual a 0 y por lo tanto se imprime lo siguiente
		{
			clrscr();
			printf("\n    Nombre:     ");
			printf("      %s \n",control.nombre);
			printf("\n    Direccion: ");
			printf("      %s \n",control.direccion);
			printf("\n    Telefono fijo:");
			printf("      %i \n",control.tel_fijo);
			printf("\n    Telefono movil:");
			printf("      %i \n",control.tel_movil);
			printf("\n    Grupo:   ");
			printf("      %s \n",control.grupo);
			manejo = 0;   //Se vuelve a asignar un valor a la variable manejo
		}
	}
	if(manejo == 1) //Si la variable aun tiene el valor de 1 significa que no se ejecuto el ciclo anterior y por lo tanto no existe
	{
		clrscr();
		printf("  \n  El contacto no existe  \n");
	}
	fclose(fp); //Se cierra el archivo
	getch();
	
	return ;
}



void eliminar_contacto(void)
{
	char eliminar_nombre[30];
	clrscr();
	fflush(stdin);
	printf("       \n\n Ingrese el contacto a eliminar:   ");
	gets(eliminar_nombre);
	fp = fopen("principal.txt", "r"); //Se abre el archivo en modo lectura
	ft = fopen("secundario.txt","w");  //Se abre el archivo en modo escribir
	while(fread(&control,sizeof(control),1,fp)!=0)  //Si encuentra un dato devuelve 1 y se ejecuta el ciclo
		if (strcmp(eliminar_nombre,control.nombre)!=0) 
		fwrite(&control,sizeof(control),1,ft);
		fclose(fp);
		fclose(ft);
		remove("principal.txt");   //Elimina el contacto 
		rename("secundario.txt","principal.txt");
	
	return ;
}



void imprimir_contactos(void)
{
	clrscr();
		
		fp=fopen("principal.txt","r");   //se abre el archivo en modo lectura
		fflush(stdin);
		
		while(fread(&control,sizeof(control),1,fp)==1)  //Mientras pueda leer algo regresara1 y se cumplira la condicion
		{
           printf("Nombre:         %s \n", control.nombre);   //Se imprimiran todos los datos de todos los contactos
		   printf("Direccion:      %s \n", control.direccion);
		   printf("Telefono fijo:  %i \n", control.tel_fijo);   //NOTA: al haber ingresado muchos contactos en ocasiones se imprimen de manera contrapuesta
		   printf("Telefono movil: %i \n", control.tel_movil);          //pero si son pocos, no hay ningun problema
		   printf("Grupo:          %s \n\n", control.grupo);
		}
		fclose(fp); //Cierre del archivo
	
	getch();
	
	return ;
}
