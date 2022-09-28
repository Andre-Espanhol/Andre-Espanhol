#include <stdio.h>

int main(void) {
	int j1, j2;
	
	printf("Por favor, informe as jogadas\n");
	scanf("%d %d", &j1, &j2);
	
	if (j1 >=1 && j1 <=3 && j2 >=1 && j2 <=3) {
		
		if (j1 != j2) {
			
			if (j1 == 1 && j2 == 3 || (j1 == 2  && j2 == 1) || (j1 == 3 && j2 == 2) ) {
				printf ("jogador 1 vendeu\n");
			}
			else {
			printf ("jogador 2 venceu\n");
			}
			
		}else {
			printf ("Empate!\n");
		}
		
	}else {
		printf ("Dados invalidos\n");
	}
}
