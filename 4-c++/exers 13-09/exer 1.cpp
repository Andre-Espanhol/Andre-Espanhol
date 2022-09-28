#include <conio.h>
#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int contador=1;
	int soma=0;
	
	while (contador<=50)
	{
		printf ("\n %d",contador);
		soma=soma+contador;
		contador++;
	}
	
	printf ("\n\n a soma dos numeros é: %d",soma);
	
	getch();
}
