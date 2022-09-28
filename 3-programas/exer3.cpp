 #include <stdio.h>
#include <conio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	//variáveis
	int idd;
	//entrada de dados
	printf("Qual a sua idade: ");
	scanf("%d", &idd);
	//desvio condicional
	if(idd<18){
		printf("\n\nMenor de idade");
	}
	else if(idd>65){
		printf("\n\nAcima dos 65 anos");
	}
	else{
		printf("\n\nMAaior de idade!");
	}
	//fim
	getch();
}
