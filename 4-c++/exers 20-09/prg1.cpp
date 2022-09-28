#include <conio.h>
#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int contador=2;
	int par=0;
	
	while (contador<=1000)
	{
		printf ("\n %d",contador);
		contador=contador+2;
		
		if (contador%2==0)
		{
			
		}

	}
	
	
	getch();
}

