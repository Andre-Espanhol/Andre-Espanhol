#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int val, num, num1, resu1, resu2, resu3;
	float resu4, resu5;
	printf("\n 1 - soma\n 2 - subtração\n 3 - multiplicação\n 4 - divisão\n 5 - média\n\nDigite um numero das opções para o cálculo desejado: ");
	scanf("%d", &val);
	printf("\nAgora digite um número: ");
	scanf("%d", &num);
	printf("\nDigite mais um número: ");
	scanf("%d", &num1);
	if(val==1)
	{
		resu1=num + num1;
		printf("\nO resultado dessa soma é: %d", resu1);
	}
	else if(val==2)
	{
		resu2=num - num1;
		printf("\nO resultado dessa subttração é: %d", resu2);
	}
	else if(val==3)
	{
		resu3=num * num1;
		printf("\nO resultado dessa subttração é: %d", resu3);
	}
	else if(val==4)
	{
		resu4=num / num1;
		printf("\nO resultado dessa subttração é: %.2f", resu4);
	}
	else if(val==5)
	{
		resu5=(num + num1)/2;
		printf("\nO resultado dessa subttração é: %.2f", resu5);
	}
	else
	{
		printf("\nValor errado. Programa encerrado sem cálculos!");
	}
	getch();
}

