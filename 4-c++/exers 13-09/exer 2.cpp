#include <conio.h>
#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int contador=1;
	
	while (contador<=100)
	{
		printf ("\n %d",contador);
		contador++;
		
		if (contador%10==0)
		{
			printf ("\n O numero: %d ",contador);
			printf(" é multiplo de 10");
		}

	}
	
	
	getch();
}

