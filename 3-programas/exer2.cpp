#include <stdio.h>
#include <conio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	
	float altura, peso;
	int sexo;
	
	printf("Digite 1 para homem, e para mulher digite 2: ");
	scanf("%d", &sexo);
	printf("Digite sua altura: ");
	scanf("%f", &altura);
	
	if(sexo = 1){
		peso = (72.7 * altura) - 58;
		printf("Seu peso ideal é de: %.2f", peso, "kg");
	}
	else{
		peso = (62.1 * altura) - 44.7;
		printf("Seu peso ideal é de: %.2f", peso, "kg");
	}
	getch();
}
