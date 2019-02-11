#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Agenda{

    char complete_name[25];
    char cellphone_number[15];

}agenda;

void add_contact(void);
void lookfor_contact(void);
void eliminate_contact(void);
void erase_agenda(void);

FILE *fp,*ft;

void main()
{
    int control = 0;
    for(;;)
    {
        system("cls");

        printf("        === MENU ===\n");
        printf("    1 - Add new contact \n");
        printf("    2 - Loof for a contact\n");
        printf("    3 - Eliminate a contact\n");
        printf("    4 - Erase 'agenda'\n");
        printf("    5 - Exit\n\n");

        printf("    Introduce the option desired: ");
        fflush(stdin);
        scanf("%d", &control);

        switch(control)
        {
            case 1: add_contact();
                break;
            case 2: lookfor_contact();
                break;
            case 3: eliminate_contact();
                break;
            case 4: erase_agenda();
                break;
            case 5: exit(0);
                break;
            default: printf("\n\n   '%d' is not an option. Try again.", control);
                break;
        }
        printf("\n\n");
        system("pause");
    }
}

void add_contact(void)
{
    ADD_CONTACT:system("cls");
    printf("\n\n    ===== Add a contact =====\n\n");

    printf("\n    Introuce the first and last name: ");
    fflush(stdin);
	gets( agenda.complete_name );

    /*printf("\n    Introuce the e-mail: ");
    fflush(stdin);
	gets(agenda.e_mail);

    printf("\n    Introuce the addess: ");
    fflush(stdin);
	gets(agenda.address);*/

    printf("\n    Introuce the cellphone number: ");
    fflush(stdin);
	gets(agenda.cellphone_number);

    /*printf("\n    Introuce the telephone number: ");
    fflush(stdin);
	scanf("%d", &agenda.telephone_number);*/

    fp = fopen("MyAgendaTest.txt", "a+");
    if( fp == NULL ){

		system("cls");
        printf("\n\n    There was an ERROR opening or creating your file");
        getchar();
		exit(1);

	}else{

        fwrite(&agenda,sizeof(agenda),1,fp);
        fclose( fp );

    }

    char again = ' ';
    printf("\n  Do you want yo add another contact (y/n)? ");
    fflush(stdin);
    again = getchar();
    if( 'y' == again ){
        goto ADD_CONTACT;
    }

}
void lookfor_contact(void)
{
    char look_for_name[50];
    system("cls");
    printf("\n\n    ===== Loof for name =====\n\n");

    printf("\n    Introuce the first and last name to look for: ");
    fflush(stdin);
	gets(look_for_name);

    fp = fopen("MyAgendaTest.txt", "r+");
    if( fp == NULL )
    {

		system("cls");
        printf("\n\n    There was an ERROR opening your file");
        getchar();
		exit(1);

	}else
    {
        unsigned int control_var = 0;
        while( fread(&agenda, sizeof(agenda), 1, fp) )
    	{
    		if(strcmp( agenda.complete_name, look_for_name )==0)
    		{
                printf("\n    The name that you are looking for is: %s", agenda.complete_name);
                printf("\n    The cellphone that you are looking for is: %s", agenda.cellphone_number);
                control_var = 1;
                break;
            }
    	}
        fclose( fp );
        if( 0 == control_var)
        {
            printf("\n\n    The contact doesn´t exist");
        }

    }


}
void eliminate_contact(void)
{
    char name_to_eliminate[30];
    system("cls");
    printf("\n\n    ===== Eliminate contact =====\n\n");

    printf("\n    Introuce the first and last name to eliminate: ");
    fflush(stdin);
	gets(name_to_eliminate);

    fp = fopen("MyAgendaTest.txt", "r");
    ft = fopen("MyAgendaTest_temporary.txt", "w+");
    if( fp == NULL )
    {

		system("cls");
        printf("\n\n    There was an ERROR opening your file");
        getchar();
		exit(1);

	}else
    {
        unsigned int control_var = 0;
        while( fread(&agenda,sizeof(agenda),1,fp) )
    	{
    		if(strcmp( agenda.complete_name, name_to_eliminate )==0)
    		{
                control_var = 1;
            }else
            {
                fwrite(&agenda, sizeof(agenda),1,ft);
            }
    	}
        fclose(fp);
		fclose(ft);
        if( 0 == control_var)
        {
            printf("\n\n    The contact doesn´t exist");
        }else
        {
            remove("MyAgendaTest.txt");
    		rename("MyAgendaTest_temporary.txt","MyAgendaTest.txt");
        }
    }
}
void erase_agenda(void)
{

    int index = 0;

    remove("MyAgendaTest.txt");

    for(index = 0; 25 > index; index++)
    {
        agenda.complete_name[index] = ' ';
    }

    for(index = 0; 15 > index; index++)
    {
        agenda.cellphone_number[index] = ' ';
    }

}
