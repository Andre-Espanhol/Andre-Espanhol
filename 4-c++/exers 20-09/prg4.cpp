#include <conio.h>
#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int contador=5;
	int par=0;
	
	while (contador<=500)
	{
		printf ("\n %d",contador);
		contador=contador+5;
		
		if (contador%2==0)
		{
			
		}

	}
	
	
	getch();
}

