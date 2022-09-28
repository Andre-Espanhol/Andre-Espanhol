#include <stdio.h>
#include <conio.h>
#include <locale.h>
main()
{
	setlocale (LC_ALL,"");
	float imc;
	int peso, alt;
	printf ("coloque o valor do seu peso: ");
	scanf ("%d", &peso);
	printf ("coloque a sua altura: ");
	scanf ("%d", &alt);
	if (imc<=20)
	{
		imc= (peso)/ alt * alt;
		printf ("abaixo do peso");
	}
	else if (25>=imc>=20)
	{
		imc= (peso)/ alt * alt;
		printf ("peso normal");
	}
	else if (imc>25<30)
	{
		imc= (peso)/ alt * alt;
		printf ("sobre peso");
	}
	else if (imc>30<35)
	{
		imc= (peso)/ alt * alt;
		printf ("obeso");
	}
	else
	{
		imc= (peso)/ alt * alt;
		printf ("Obeso mórbido!");
	}
	getch();
}

