#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Eduardo Gamboa ing. mecatrónica, 2° cuatrimestre
//Agenda para manejar contactos y diferentes datos de estos

struct  agenda
	{
		char nombre[30];
		char correo[30];
		int numero;
	}contacto;//estructura con los datos de cada contacto

FILE *fp,*ft;//apuntadores para la creacion de archivos
void agregar(void); 
void eliminar(void);
void buscar(void);
void lista(void);
void datos(void);

int main()//inicio de main donde solo se mandara llamar la funcion que se elija
{ 
int opcion;
	clrscr();
	marcador://inicio del marcador
	clrscr();
	      /* Despliega el menu principal */
	gotoxy(22,8);
	printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xbb\n");
	gotoxy(22,9);
	printf("\xBA BIENVENIDO A SU LISTA DE CONTACTOS \xBA");  
	gotoxy(22,10);
    printf("\xBA 1.AGREGAR UN CONTACTO              \xBA");
	gotoxy(22,11);
    printf("\xBA 2.ELIMINAR UN CONTACTO             \xBA");
	gotoxy(22,12);
    printf("\xBA 3.BUSCAR UN CONTACTO               \xBA");
	gotoxy(22,13);
    printf("\xBA 4.DESPLEGAR LA LISTA DE CONTACTOS  \xBA");
	gotoxy(22,14);
    printf("\xBA 5.SALIR                            \xBA");
	gotoxy(22,15);
	printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(22,16);
	printf("opci\xA2n: ");
	scanf("%i", &opcion);		  
	switch(opcion)/*Ejecuta la función de acuerdo a la opcion seleccionada */
	{
		case 1: agregar();
				break;
		case 2: eliminar();
				break;
		case 3: buscar();
				break;
  		case 4: lista();
				break;
		case 5: clrscr();
				gotoxy(36,18);
				printf("ADIOS...\n");
				exit(1);
				break;
		default:clrscr();
				gotoxy(24,8);
				printf("Opci\xA2n invalida\n");
				gotoxy(24,9);
				printf("Reingrese su opci\xA2n");
				getch();
				goto marcador;
	}
	goto marcador;//se regresa al principio
}
	
	
void agregar(void)//inicio de la funcion para agregar contactos
{
char opc;
	clrscr();
	marcador:
	clrscr();
	gotoxy(23,8);
	printf("CREAR UN CONTACTO");
	gotoxy(23,10);
	printf("NOMBRE: ");
	fflush(stdin);
	gets(contacto.nombre);//se guarda el nombre del contacto en la estructura
	fflush(stdin);
	gotoxy(23,12);
	printf("N\xE9MERO: ");
	scanf("%i", &contacto.numero);
	fflush(stdin);
	gotoxy(23,14);
	printf("CORREO ELECTRONICO: ");
	scanf("%s", &contacto.correo);
	if((fp=fopen("archivo","ab+"))==NULL)//se abre el archivo y se verifica que no haya error
	{
		clrscr();
		gotoxy(23,15);
		printf("El archivo no se pudo leer o abrir\n");
		getch();
		exit(1);
	}	
	fwrite(&contacto,sizeof(contacto),1,fp);
	fclose(fp);//se cierra el archivo que se estaba editando
	clrscr();
	gotoxy(23,8);
	printf("Agregar otro contacto(y/n): ");
	opc = getch(); 
	if(opc == 'y')
		goto marcador;
}
	
void eliminar(void)//inicio de la funcion para eliminar contactos
{
char nombre_eliminar[30];
	fflush(stdin);
	clrscr();
	gotoxy(23,8);
	printf("nombre: ");
	scanf("%[^\n]",&nombre_eliminar);
	fp=fopen("archivo","r");//se abren los archivos
	ft=fopen("temporal","w");
	while(fread(&contacto,sizeof(contacto),1,fp)!=0)
		if (strcmp(nombre_eliminar,contacto.nombre)!=0)
		fwrite(&contacto,sizeof(contacto),1,ft);
		fclose(fp);
		fclose(ft);
		remove("archivo");//se elimina el contacto 
		rename("temporal","archivo");
}

	
void buscar(void)
{
char nombre_recibido[30];
int centinela;
	clrscr();
	gotoxy(23,8);		
	printf("NOMBRE: ");
	fflush(stdin);
	scanf("%[^\n]",nombre_recibido);
	if((fp=fopen("archivo","rb+"))==NULL)
	{
		clrscr();
		gotoxy(23,15);
		printf("El archivo no se pudo leer o abrir\n");
		getch();
		exit(1);
	}
	centinela=1;
	while(fread(&contacto,sizeof(contacto),1,fp))
	{
		if(strcmp(contacto.nombre,nombre_recibido)==0)//si coincide el nombre con uno que exista se manda llamar la funcion datos
		{
			datos();
			centinela=0;
			break;
        }
	}
	if(centinela == 1)
	{
		clrscr();
		gotoxy(25,15);
		printf("El contacto no existe");
	}	
	fclose(fp);
	getch();
}

	
void lista(void)//funcion para imprimir todos los contactos en el archivo
{
int i;
	clrscr();
	gotoxy(16,7);
	printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
	gotoxy(25,8);
	printf("NOMBRE  \xB3   N\xE9MERO\n");
	for(i=50;i<=120;i=i+1)
		{
		fp=fopen("archivo","r");//se abre el archivo en modo lectura
		fflush(stdin);
		while(fread(&contacto,sizeof(contacto),1,fp)==1)
		{
			if(contacto.nombre[0] == i || contacto.nombre[0] == i-32)
			{
				printf("%30s  \xB3   %-12i   \n",contacto.nombre, contacto.numero);//se imprime todos los contactos 
			}
		}
		fclose(fp);
 	}
	getch();
}


void datos(void)//funcion para solo imprimir los datos de cada contacto
{
	clrscr();
	gotoxy(15,8);
	printf("NOMBRE: ");
	printf("%s", contacto.nombre);
	gotoxy(15,10);
	printf("N\xE9MERO: ");
	printf("%i", contacto.numero);
	gotoxy(15,12);
	printf("CORREO: ");
	printf("%s",contacto.correo);
}