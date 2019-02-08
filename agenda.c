#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct agenda {
	char nom[15];
	int t_f;
	int t_m;
	char dir[30], email[40], grupos[12];
} control[100];
int cont=0;

void agregar();
void buscar();
void contactos();

main(){
	int opc;

	do{
		system("cls");

		printf("MENU\n");
		printf("1.Agregar\n");
		printf("2.Buscar\n");
		printf("3.Ver todos los contactos\n");
		printf("4.Salir\n");

		scanf("%d", &opc);

		switch(opc){
		case 1:
			agregar();
			system("pause");
			break;

		case 2:
			buscar();
			system("pause");
			break;

		case 3:
			contactos();
			system("pause");
			break;
		}
	}while(opc!=4);

	return 0;
}

void agregar(){
	system("cls");

	fflush(stdin);
	printf("\n%d.Nombre de contacto:", (cont+1));
	gets(control[cont].nom);

	fflush(stdin);
	printf("\nTel\202fono fijo:");
	scanf("%d", &control[cont].t_f);

	fflush(stdin);
	printf("\nTel\202fono m\242vil:");
	scanf("%d", &control[cont].t_m);

	fflush(stdin);
	printf("\nDirecci\242n:");
	gets(control[cont].dir);

	fflush(stdin);
	printf("\nE-mail:");
	gets(control[cont].email);

	fflush(stdin);
	printf("\nGrupo:");
	gets(control[cont].grupos);

	cont++;

}

void buscar(){
	char busca[15];
	int i;

	system("cls");

	fflush(stdin);
	printf("\nBuscar contacto\nIngrese el nombre del contacto:");
	gets(busca);

	for(i=0;i<cont;i++){
		if(strcmpi(busca,control[i].nom)==0){
			printf("\nNombre: %s\n", control[i].nom);
			printf("Tel\202fono fijo: %d\n", control[i].t_f);
			printf("Tel\202fono m\242vil: %d\n", control[i].t_m);
			printf("Direcci\242n: %s\n", control[i].dir);
			printf("E-mail: %s\n", control[i].email);
			printf("Grupo: %s\n", control[i].grupos);
		}
	}

}

void contactos(){
	int aux, i, j;
	char auxc[50];

	system("cls");

	for(i=0;i<cont-1;i++){
		for(j=0;j<cont-1-i;j++){
			if(strcmp(control[j].nom,control[j+1].nom)>0){
				
				strcpy(auxc,control[j].nom);
				strcpy(control[j].nom,control[j+1].nom);
				strcpy(control[j+1].nom,auxc);

				aux = control[j].t_f;
				control[j].t_f = control[j+1].t_f;
				control[j+1].t_f = aux;

				aux = control[j].t_m;
				control[j].t_m = control[j+1].t_m;
				control[j+1].t_m = aux;

				strcpy(auxc,control[j].dir);
				strcpy(control[j].dir,control[j+1].dir);
				strcpy(control[j+1].dir,auxc);

				strcpy(auxc,control[j].email);
				strcpy(control[j].email,control[j+1].email);
				strcpy(control[j+1].email,auxc);

				strcpy(auxc,control[j].grupos);
				strcpy(control[j].grupos,control[j+1].grupos);
				strcpy(control[j+1].grupos,auxc);
			}
		}
	}

	printf("\nAgenda.\n");

	for(i=0;i<cont;i++){
		printf("\n%d.Nombre: %s\n",(i+1), control[i].nom);
		printf("Tel\202fono fijo: %d\n", control[i].t_f);
		printf("Tel\202fono m\242vil: %d\n", control[i].t_m);
		printf("Direcci\242n: %s\n", control[i].dir);
		printf("E-mail: %s\n", control[i].email);
		printf("Grupo: %s\n", control[i].grupos);
	}

}
