#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL,"");
	int num1,num2;
	printf("digite o primeiro numero:");
	scanf("%d",&num1);
	printf("\nDigite o segundo numero:");
	scanf("%d",&num2);
	if(num1>num2){
		printf("\n\n O maior numero é: %d",num1);
	
	}
	
else{
		printf("\n\n O maior numero é:%d",num2);
	}
	
}
