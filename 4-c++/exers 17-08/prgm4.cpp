#include <stdio.h>
#include <conio.h>
#include <locale.h>
main ()
{
	setlocale(LC_ALL,"");
	float salario, valor;
	printf ("coloque o valor bruto do seu sal�rio: ");
	scanf ("%f", & salario);
	printf ("coloque o valor das presta��es: ");
	scanf ("%f", &valor);
	if (valor< salario)
	{
		valor= (30* salario)/100;
		printf ("O empr�stimo pode ser concedido!!!");
	}
	else if (valor> salario)
	{
		valor= (30* salario)/100;
		printf ("O empr�stimo n�o pode ser concedido!!! ");
	}
	getch();
}

