#include <stdio.h>
#include <conio.h>
#include <locale.h>
main()
{
	setlocale (LC_ALL,"");
	int RJ, SP, MG, outros, std;
	printf ("Digite a sigla do seu estado. \n1- Rio de janeiro; \n2- S�o Paulo; \n3- Minas Gerais.: ");
	scanf ("%d", &std);
	if (std==1)
	{
		printf ("Voc� � carioca!!");
	}
	else if (std ==2)
	{
		printf ("Voc� � paulista!!");
	}
	else if (std ==3)
	{
		printf ("Voc� � mineiro!!");
	}
	else 
	{
		printf ("Outros estados do pa�s!!");
	}
	getch();
}

