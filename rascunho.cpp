#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

struct cinema{
	int sala[4];
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
	int verifica;
	int sessaoVerifica=0;
	int qntdIngressos = 0;
	char confirmarCompra;
	int escolha = 0, cont = 0, i = 0, escolhaFilme = 0, sessao = 0, contCadeiras[4], busca = 0;
	
	for(i = 0; i < 4; i++){
		contCadeiras[i] = 50;
		c.sala[i] = 0;
	}
	
	for(int j = 0; j < 200; j++){
		f[j].id = 0; 
		f[j].n_dependentes = 0;
		f[j].status = 0;
	}
	// CADASTRANDO 2 FIDELIDADE ///////////////////////////////////////////////////////////////////////////////////////
	f[0].id = 1; 
	f[0].n_dependentes = 1;
	f[0].status = 1;
	strcpy(f[0].nome, "Bruno");
	strcpy(f[0].cpf, "11259285901");
	
	f[1].id = 2; 
	f[1].n_dependentes = 2;
	f[1].status = 1;
	strcpy(f[1].nome, "Marina");
	strcpy(f[1].cpf, "123456789");
	cont = 2;
	// CADASTRANDO 2 FIDELIDADE ///////////////////////////////////////////////////////////////////////////////////////
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
						do{
							printf("\nStar Wars Episódio 9 - A Ascensão Skywalker\n");
							printf("\n\tEscolha a sessão: ");
							printf("\n\n\tSessão 1: 12:30 - SALA 1 | %d cadeiras restantes\n\tSessão 2: 15:00 - SALA 2 | %d cadeiras restantes\n\n\t", contCadeiras[0], contCadeiras[1]);
							scanf("%d", &sessao);
							switch(sessao){
								case 1:
									if(contCadeiras[0] > 0){
										printf("Numero de cadeiras restantes é %d\n\n", contCadeiras[0]);
										
										do{
											printf("Informe a quantidade de ingressos: ");
											scanf("%d", &qntdIngressos);
											int reserva = qntdIngressos;
											if(reserva >= 0){
												printf("Deseja confirmar a compra? S | N\n");
												scanf("%s", &confirmarCompra);
											
												if(confirmarCompra == 'S' || confirmarCompra == 's'){
													if(contCadeiras[0] - reserva < 0){
														verifica = -1;
														printf("\nNão há cadeiras suficientes\n");
													}else{
														verifica = 0;
														contCadeiras[0] = contCadeiras[0] - reserva;
														c.sala[0] = c.sala[0] + reserva;
														
														printf("\nNumero de cadeiras restantes é %d\n\n" , contCadeiras[0]);
														getch();
													}
												}
											}else{
												verifica = -1;
												printf("\nValor informado é inválido!\n");
												Sleep(500);
											}
											sessaoVerifica = 1;
										}while(verifica == -1);
									}else{
										system("cls");
										printf("Sessão lotada\n");
										system("pause");
										sessaoVerifica = -1;
									}
								break;
								case 2:
									if(contCadeiras[1] > 0){
										printf("Numero de cadeiras restantes é %d\n\n", contCadeiras[1]);
										
										do{
											printf("Informe a quantidade de ingressos: ");
											scanf("%d", &qntdIngressos);
											int reserva = qntdIngressos;
											
											printf("Deseja confirmar a compra? S | N\n");
											scanf("%s", &confirmarCompra);
											
											if(confirmarCompra == 'S' || confirmarCompra == 's'){
												if(contCadeiras[1] - reserva < 0){
													verifica = -1;
													printf("\nNão há cadeiras suficientes\n");
												}else{
													verifica = 0;
													contCadeiras[1] = contCadeiras[1] - reserva;
													c.sala[1] = c.sala[1] + reserva;
													
													printf("\nNumero de cadeiras restantes é %d\n\n" , contCadeiras[1]);
													getch();
												}
											}
											sessaoVerifica = 1;
										}while(verifica == -1);
									}else{
										system("cls");
										printf("Sessão lotada\n");
										system("pause");
										sessaoVerifica = -1;
									}
								break;
							}
						}while(sessaoVerifica == -1);
					break;
					case 2:
						do{
						printf("\nHarry Potter 27\n");
						printf("\n\tEscolha a sessão: ");
						printf("\n\n\tSessão 1: 12:30 - SALA 3\tSessão 2: 15:00 - SALA 4\n\n");
						scanf("%d", &sessao);
							switch(sessao){
								case 1:
									if(contCadeiras[2] > 0){
										printf("Numero de cadeiras restantes é %d\n\n", contCadeiras[2]);
										
										do{
											printf("Informe a quantidade de ingressos: ");
											scanf("%d", &qntdIngressos);
											int reserva = qntdIngressos;
											
											printf("Deseja confirmar a compra? S | N\n");
											scanf("%s", &confirmarCompra);
											
											if(confirmarCompra == 'S' || confirmarCompra == 's'){
												if(contCadeiras[2] - reserva < 0){
													verifica = -1;
													printf("\nNão há cadeiras suficientes\n");
												}else{
													verifica = 0;
													contCadeiras[2] = contCadeiras[2] - reserva;
													c.sala[2] = c.sala[2] + reserva;
													
													printf("\nNumero de cadeiras restantes é %d\n\n" , contCadeiras[2]);
													getch();
												}
											}
											sessaoVerifica = 1;
										}while(verifica == -1);
									}else{
										system("cls");
										printf("Sessão lotada\n");
										system("pause");
										sessaoVerifica = -1;
									}
								break;
								case 2:
									if(contCadeiras[3] > 0){
										printf("Numero de cadeiras restantes é %d\n\n", contCadeiras[3]);
										
										do{
											printf("Informe a quantidade de ingressos: ");
											scanf("%d", &qntdIngressos);
											int reserva = qntdIngressos;
											
											printf("Deseja confirmar a compra? S | N\n");
											scanf("%s", &confirmarCompra);
											
											if(confirmarCompra == 'S' || confirmarCompra == 's'){
												if(contCadeiras[3] - reserva < 0){
													verifica = -1;
													printf("\nNão há cadeiras suficientes\n");
												}else{
													verifica = 0;
													contCadeiras[3] = contCadeiras[3] - reserva;
													c.sala[3] = c.sala[3] + reserva;
													
													printf("\nNumero de cadeiras restantes é %d\n\n" , contCadeiras[3]);
													getch();
												}
											}
											sessaoVerifica = 1;
										}while(verifica == -1);
									}else{
										system("cls");
										printf("Sessão lotada\n");
										system("pause");
										sessaoVerifica = -1;
									}
								break;
							}
						}while(sessaoVerifica == -1);
					break;
				}
			
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
				if(cont > 0){
					do{
						printf("Infome o cpf para busca: ");
						gets(cpfBusca);
						fflush(stdin);
						system("cls");
						busca = -1;
						for(i = 0; i < cont; i++){
							if(f[i].id > 0){
								system("cls");
								if(strcmp(f[i].cpf, cpfBusca) == 0){
									busca = i;
									i = cont;				
								}
							}
						}
						if(busca == -1){
							printf("Não existe um cadastro com este cpf!");
							printf("\n\n");
						}
					}while(busca < 0);
					system("cls");
					printf("\nID: %d\nNome: %s\nCPF: %s\nNumero de dependentes: %d\nStatus: %d\n", f[busca].id, f[busca].nome, f[busca].cpf, f[busca].n_dependentes, f[busca].status);
					printf("\n\n");
					getch();
					
					busca = 0;
				}
			break;
			case 0:
			
			break;
				
			default:
				printf("opção invalida!\n");	
				Sleep(1000);
			break;
		}
	}while(escolha != 0);
	
	printf("\n\n");
	system("pause");
	return 0;
}


