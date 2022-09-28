#include <conio.h>
#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	int contador=1;
	
	
	while (contador<=50)
	{
		printf ("\n %d",contador);
		contador++;
	}
	
	printf ("\n\n a quantidade de numeros nesse intervalo de 10 à 20 é de:\n10 \n11 \n12 \n13 \n14 \n15 \n16 \n17 \n18 \n19 \n20");
	
	getch();
}

