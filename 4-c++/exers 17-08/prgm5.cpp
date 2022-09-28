#include <stdio.h>
#include <conio.h>
#include <locale.h>
main()
{
	setlocale (LC_ALL,"");
	int A, B, C, D;
	printf ("coloque o valore de A: ");
	scanf ("%d", &A);
	printf ("coloque o valor de B: ");
	scanf ("%d", &B);
	printf ("coloque o valor de C: ");
	scanf ("%d", &C);
	printf ("coloque o valor de D: ");
	scanf ("%d", &D);
	if (A>B)
	{
		printf ("\n%d é valor maior! %d", A);
		printf ("\n%d é valor menor! %d", B);
	}
	else if (C>D)
	{
		printf ("\n%d é valor maior! %d", C);
		printf ("\n%d é valor menor! %d", D);
	}
	else if (C>A)
	{
		printf ("\n%d é valor maior! %d", C);
		printf ("\n%d é valor menor! %d", A);
	}
	else if (C>B)
	{
		printf ("\n%d é valor maior! %d", C);
		printf ("\n%d é valor menor! %d", B);
	}
	else if (A>C)
	{
		printf ("\n%d é valor maior! %d", A);
		printf ("\n%d é valor menor! %d", C);
	}
	else if (A>D)
	{
		printf ("\n%d é valor maior! %d", A);
		printf ("\n%d é valor menor! %d", D);
	}
	else if (B>A)
	{
		printf ("\n%d é valor maior! %d", B);
		printf ("\n%d é valor menor! %d", A);
	}
	else if (B>C)
	{
		printf ("\n%d é valor maior! %d", B);
		printf ("\n%d é valor menor! %d", C);
	}
	else if (B>D)
	{
		printf ("\n%d é valor maior! %d", B);
		printf ("\n%d é valor menor! %d", D);
	}
	else if (D>A)
	{
		printf ("\n%d é valor maior! %d", D);
		printf ("\n%d é valor menor! %d", A);
	}
	else if (D>B)
	{
		printf ("\n%d é valor maior! %d", D);
		printf ("\n%d é valor menor or! %d", B);
	}
	else
	{
		printf ("\n%d é valor maior! %d", D);
		printf ("\n%d é valor menor! %d", C);
	}
	getch();
}

