#include <stdio.h>
#include <conio.h>
#include <locale.h>
main ()
{
	setlocale (LC_ALL,"");
	float dr, total, dia;
	printf ("Informe o número de dias: ");
	scanf ("%f", &dia);
	if (dr<15)
	{total= 300*dia+20;
		printf ("O total a pagar é R$: %f", total);
	}
	else if (dr ==15)
	{total= 300*dia+14;
		printf ("O total a pagar é R$: %f", total);
	}
	else if (dr >15)
	{total= 300*dia+12;
		printf ("O total a pagar é R$: %f", total);
	}
	getch();
}

