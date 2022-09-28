#include <stdio.h>
#include <conio.h>
#include <locale.h>
main ()
{
	setlocale(LC_ALL,"");
	float salario, valor;
	printf ("coloque o valor bruto do seu salário: ");
	scanf ("%f", & salario);
	printf ("coloque o valor das prestações: ");
	scanf ("%f", &valor);
	if (valor< salario)
	{
		valor= (30* salario)/100;
		printf ("O empréstimo pode ser concedido!!!");
	}
	else if (valor> salario)
	{
		valor= (30* salario)/100;
		printf ("O empréstimo não pode ser concedido!!! ");
	}
	getch();
}

