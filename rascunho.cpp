#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<conio.h>
#include<time.h>

struct cinema{
	int sala[4][50];
};

struct fidelidade{
	int id, status, n_dependentes;
	char nome[30], cpf[11];
};

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	struct cinema c;
	struct fidelidade f[200];
	char cpfBusca[11];
	
	int escolha = 0, cont = 0, i = 0, escolhaFilme = 0, sessao = 0, contCadeiras[4], busca = 0;
	
	for(i = 0; i < 4; i++){
		contCadeiras[i] = 0;
	}
	
	for(i = 0; i < 43; i++){
		c.sala[0][i] = 1;
	}
	for(i = 0; i < 37; i++){
		c.sala[1][i] = 1;
	}
	for(i = 0; i < 17; i++){
		c.sala[2][i] = 1;
	}
	for(i = 0; i < 9; i++){
		c.sala[3][i] = 1;
	}
	
	for(int j = 0; j < 200; j++){
		f[j].id = 0; 
		f[j].n_dependentes = 0;
		f[j].status = 0;
	}
	
	do{
		system("cls");
		
		printf(	"1 - Comprar Ingresso\n"
				"2 - Cadastro Fidelidade\n"
				"3 - Listar cadastrados\n"
				"4 - Buscar\n"
				"\n0 - Sair\n\n");
		scanf("%d", &escolha);
		fflush(stdin);
		
		system("cls");
		
		switch(escolha){
			case 1:
				
				printf("Informe o filme:\n\n");
				printf("1 - Star Wars Episódio 9 - A Ascensão Skywalker\n\n");
				printf("2 - Harry Potter 27\n");
				scanf("%d", &escolhaFilme);
				fflush(stdin);
				system("cls");
				switch(escolhaFilme){
					case 1:
						printf("\nStar Wars Episódio 9 - A Ascensão Skywalker\n");
						printf("\n\tEscolha a sessão: ");
						printf("\n\n\tSessão 1: 12:30 - SALA 1\tSessão 2: 15:00 - SALA 2\n\n");
						scanf("%d", &sessao);
						switch(sessao){
							case 1:
								for(i = 0; i < 50; i++){
									contCadeiras[0] = contCadeiras[0] + c.sala[0][i];
								}
								printf("Numero de cadeiras restantes é %d", 50 - contCadeiras[0]);
							break;
							case 2:
								for(i = 0; i < 50; i++){
									contCadeiras[1] = contCadeiras[1] + c.sala[1][i];
								}
								printf("Numero de cadeiras restantes é %d", 50 - contCadeiras[1]);
							break;
						}
					break;
					case 2:
						printf("\nHarry Potter 27\n");
						printf("\n\tEscolha a sessão: ");
						printf("\n\n\tSessão 1: 12:30 - SALA 3\tSessão 2: 15:00 - SALA 4\n\n");
						scanf("%d", &sessao);
						switch(sessao){
							case 1:
								for(i = 0; i < 50; i++){
									contCadeiras[2] = contCadeiras[2] + c.sala[2][i];
								}
								printf("Numero de cadeiras restantes é %d", 50 - contCadeiras[2]);
							break;
							case 2:
								for(i = 0; i < 50; i++){
									contCadeiras[3] = contCadeiras[3] + c.sala[3][i];
								}
								printf("Numero de cadeiras restantes é %d", 50 - contCadeiras[3]);
							break;
						}
					break;
				}
				getch();
				
			break;
			case 2:
				printf("\nCadastro Fidelidade\n");
				printf("\nInforme o nome: \n");
				gets(f[cont].nome);
				fflush(stdin);
				
				printf("\nInforme o cpf (sem pontos e traço): \n");
				gets(f[cont].cpf);
				fflush(stdin);
				
				do{
					printf("\nInforme quantos dependentes (maximo 2): \n");
					scanf("%d", &f[cont].n_dependentes);
					fflush(stdin);
				}while(f[cont].n_dependentes < 0 || f[cont].n_dependentes > 2);
				
				f[cont].status = 1;
				
				f[cont].id = cont + 1;
				
				cont++;
				system("cls");
			break;
			case 3:
				if(cont > 0){
					for(i = 0; i < cont; i++){
						if(f[i].id > 0){
							printf("\nID: %d\nNome: %s\nCPF: %s\nNumero de dependentes: %d\nStatus: %d\n", f[i].id, f[i].nome, f[i].cpf, f[i].n_dependentes, f[i].status);
							printf("\n\n");
						}
					}
					getch();
				}
			break;	
			case 4:
				////////////////////////////////////// arrumar
				if(cont > 0){
					printf("Infome o cpf para busca: ");
					gets(cpfBusca);
					fflush(stdin);
					system("cls");
					for(i = 0; i < cont; i++){
						if(f[i].id > 0){
							system("cls");
							if(strcmp(f[i].cpf, cpfBusca) == 0){
								busca = i;
								i = cont;				
							}//else{
//								printf("Não existe um cadastro com este cpf!");
//								printf("\n\n");
//								
//								i = 0;
//
//								printf("Infome novamente o cpf para busca: ");
//								gets(cpfBusca);
//								fflush(stdin);
//								system("cls");
//							}
						}
					}
					system("cls");
					printf("\nID: %d\nNome: %s\nCPF: %s\nNumero de dependentes: %d\nStatus: %d\n", f[busca].id, f[busca].nome, f[busca].cpf, f[busca].n_dependentes, f[busca].status);
					printf("\n\n");
					getch();
					
					busca = 0;
				}
				
			break;	
		}
	}while(escolha != 0);
	
	printf("\n\n");
	system("pause");
	return 0;
}


