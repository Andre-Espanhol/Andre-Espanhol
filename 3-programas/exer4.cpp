#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int val, num, num1, resu1, resu2, resu3;
	float resu4, resu5;
	printf("\n 1 - soma\n 2 - subtra��o\n 3 - multiplica��o\n 4 - divis�o\n 5 - m�dia\n\nDigite um numero das op��es para o c�lculo desejado: ");
	scanf("%d", &val);
	printf("\nAgora digite um n�mero: ");
	scanf("%d", &num);
	printf("\nDigite mais um n�mero: ");
	scanf("%d", &num1);
	if(val==1)
	{
		resu1=num + num1;
		printf("\nO resultado dessa soma �: %d", resu1);
	}
	else if(val==2)
	{
		resu2=num - num1;
		printf("\nO resultado dessa subttra��o �: %d", resu2);
	}
	else if(val==3)
	{
		resu3=num * num1;
		printf("\nO resultado dessa subttra��o �: %d", resu3);
	}
	else if(val==4)
	{
		resu4=num / num1;
		printf("\nO resultado dessa subttra��o �: %.2f", resu4);
	}
	else if(val==5)
	{
		resu5=(num + num1)/2;
		printf("\nO resultado dessa subttra��o �: %.2f", resu5);
	}
	else
	{
		printf("\nValor errado. Programa encerrado sem c�lculos!");
	}
	getch();
}

