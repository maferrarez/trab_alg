#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
/////////////////// struct de 4 posiçoes
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int N = 0, num, cont = 0;
	int numeros[N], linha, coluna, ingressos;
	int escolha = 1;
	int l, c, verificaCadeira;
	char matrix[5][10];
	
	
	for(l = 0; l < 5; l++){
		for(c = 0; c < 10; c++){
			matrix[l][c] = ' ';
		}
	}
	
	do{
	
		printf("Sair = 0 | Cadastrar novo numero = 1 | Mostrar array = 2\n");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				N = N + 1;
				printf("Infome um numero: ");
				scanf("%d", &numeros[cont]);	
				cont = cont + 1;
			break;
			case 2:
				for(int i = 0; i < cont; i++){
					printf("%d\n", numeros[i]);
				}
				getch();
			break;
			
			case 3:
				system("cls");
				for(l = 0; l < 5; l++){
					printf("\n\t   ._______________________________________.");
					printf("\n\t   |   |   |   |   |   |   |   |   |   |   |\n");
					printf("\t%d  | ", l+1);
					for(c = 0; c < 10; c++){
						printf("%c | ", matrix[l][c]);
					}	
				}
				printf("\n\n\nInforme o numero de ingressos: ");
				scanf("%d", &ingressos);
				int seg = ingressos;
				if(seg > 0){
					do{
						system("cls");
						printf("\n\n\t    ");
						for(c = 0; c < 10; c++){
							printf(" %d  ", c+1);
						}
						for(l = 0; l < 5; l++){
							printf("\n\t   ._______________________________________.");
							printf("\n\t   |   |   |   |   |   |   |   |   |   |   |\n");
							printf("\t%d  | ", l+1);
							for(c = 0; c < 10; c++){
								printf("%c | ", matrix[l][c]);
							}
							
						}
						printf("\n\n\n\t\t\t     TELA");
						printf("\n         \\___________________________________________/");
		
						printf("\n\n\nInforme a linha: ");
						scanf("%d", &linha);
						printf("\n\nInforme a coluna: ");
						scanf("%d", &coluna);
						if(matrix[linha-1][coluna-1] == ' '){
							matrix[linha-1][coluna-1] = 'X';
							verificaCadeira = 1;
							seg = seg - 1;
						}else{
							verificaCadeira = 0;
							printf("\nCadeira já ocupada!\n");
							Sleep(800);
						}
					}while(verificaCadeira == 0 || seg > 0);
				}
			break;
		}
		
		system("cls");
	
	}while(escolha != 0);
	
	
	system("pause");
	return 0;
}


