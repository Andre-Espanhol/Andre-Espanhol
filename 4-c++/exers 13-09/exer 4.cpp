#include <conio.h>
#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int contador=1;
	int soma=0;
	
	while (contador<=100)
	{
		printf ("\n %d",contador);
		
		
		if (contador%3==0)
		{
			soma=soma+contador;
		}
		contador=contador+1;
	}
	
	
	getch();
}

