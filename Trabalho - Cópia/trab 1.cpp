#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<conio.h>
#include<time.h>
#include <windows.h>
#include "MyBibTrab.h"

struct cadastroF{
	char nome[100], cpf[12], telefone[16];
	int id, pontos, status, idade;
};

	////////////////////// FUNÇOES ////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	void cadastroFidelidade(struct cadastroF cf[], int contF){
		contF = contF - 1;
		
		cf[contF].id = contF+1;
		cf[contF].status = 1;
		cf[contF].pontos = 0;
		
		printf("\n\tInforme o nome: ");
		gets(cf[contF].nome);
		varrer();		
		
		printf("\nInforme o CPF: ");
		gets(cf[contF].cpf);
		varrer();
		
		printf("\nInforme o telefone: ");
		gets(cf[contF].telefone);
		varrer();
		
		printf("\nInforme a idade: ");
		scanf("%d", &cf[contF].idade);
		varrer();
	}
	
	void listarClientes(struct cadastroF cf[], int contF){
		int i;
		
		for(i = 0; i < contF; i++){
			linha();
			printf("Cliente\t      ID: %i\n", cf[i].id);
			printf("\t    NOME: %s\n", cf[i].nome);
			printf("\t     CPF: %s\n", cf[i].cpf);
			printf("\tTELEFONE: %s\n", cf[i].telefone);
			printf("\t   IDADE: %i\n", cf[i].idade);
			printf("\t  PONTOS: %i\n", cf[i].pontos);
			printf("\t  STATUS: %i", cf[i].status);
		}
		
		linha();
		system("pause");
	}
	
	int buscarAtivos(struct cadastroF cf[], int cont){
		limpar();
		int j = 0;
		for(int i = 0; i < cont; i++){
			if(cf[i].status == 1){
				linha();
				printf("Cliente\t      ID: %i\n", cf[i].id);
				printf("\t    NOME: %s\n", cf[i].nome);
				printf("\t     CPF: %s\n", cf[i].cpf);
				printf("\tTELEFONE: %s\n", cf[i].telefone);
				printf("\t   IDADE: %i\n", cf[i].idade);
				printf("\t  PONTOS: %i\n", cf[i].pontos);
				printf("\t  STATUS: %i", cf[i].status);
				j = 1;
			}
		}
		if(j == 0){
			printf("\nNão há cadastros ativos!\n");
		}else{
			linha();
		}
		return j;
	}
	
	int buscarInativos(struct cadastroF cf[], int cont){
		limpar();
		int j = 0;
		for(int i = 0; i < cont; i++){
			if(cf[i].status == 0){
				linha();
				printf("Cliente\t      ID: %i\n", cf[i].id);
				printf("\t    NOME: %s\n", cf[i].nome);
				printf("\t     CPF: %s\n", cf[i].cpf);
				printf("\tTELEFONE: %s\n", cf[i].telefone);
				printf("\t   IDADE: %i\n", cf[i].idade);
				printf("\t  PONTOS: %i\n", cf[i].pontos);
				printf("\t  STATUS: %i", cf[i].status);
				j = 1;
			}
		}
		if(j == 0){
			printf("\nNão há cadastros inativos!\n");
		}else{
			linha();
		}
		return j;
	}
	
	buscaCPF(struct cadastroF cf[], int cont){
		
		char cpf[12];
		
		printf("\nInforme o CPF para buscar cadastro: ");
		gets(cpf);
		varrer();
		
		for(int i = 0; i < cont; i++){
			if(strcmp(cf[i].cpf, cpf) == 0){
				printf("\n\nCliente\t      ID: %i\n", cf[i].id);
				printf("\t    NOME: %s\n", cf[i].nome);
				printf("\t     CPF: %s\n", cf[i].cpf);
				printf("\tTELEFONE: %s\n", cf[i].telefone);
				printf("\t   IDADE: %i\n", cf[i].idade);
				printf("\t  PONTOS: %i\n", cf[i].pontos);
				printf("\t  STATUS: %i", cf[i].status);	
			}
		}
		pausar();
	}
	
	////////////////////// FUNÇOES ////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    SetConsoleOutputCP (28591); // leitura da tabela Latina (escrita) 
    SetConsoleCP(28591);//Acentuação para funções (leitura) funções na bib windows
    
    ////////////////////// VARIAVEIS ////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int opEdicao;
    
    // cinema / ingressos
    int qntdIngressos, sala[4];
	char confirmar;
	
	// fidelidade
	int contFidelidade; // tamanho do vetor(vetor dinamico)
	struct cadastroF cf[contFidelidade];
	
	// busca 
	int opBusca;
	

    // vars escolhas / switch
    int escolhaMenu, escolhaSessao;
    
    // vars de verificação
    int verificaSessao, verificaBusca;
    
    ////////////////////// VARIAVEIS ////////////////////////////////////////////////////////////////////////////////////////////////////////

	// alimentar as salas com o valor 50
    for(int i = 0; i < 4; i++){
    	sala[i] = 50;
	}
    
    strcpy(cf[contFidelidade].nome, "Bruno");
	strcpy(cf[contFidelidade].cpf, "11259285901");
	strcpy(cf[contFidelidade].telefone, "(41)98846-6530");
	cf[contFidelidade].idade = 22;
	cf[contFidelidade].id = 1;
	cf[contFidelidade].status = 0;
	cf[contFidelidade].pontos = 0;
	contFidelidade = 1;
	
	strcpy(cf[contFidelidade].nome, "Jessica");
	strcpy(cf[contFidelidade].cpf, "123456789");
	strcpy(cf[contFidelidade].telefone, "(41)98846-6530");
	cf[contFidelidade].idade = 22;
	cf[contFidelidade].id = 2;
	cf[contFidelidade].status = 1;
	cf[contFidelidade].pontos = 0;
	
	contFidelidade = 2;
    
    do{
    	limpar();
		// printar o menu principal
	    menuPrincipal();
	    // receber a resposta
	    scanf("%d", &escolhaMenu); 
	    varrer(); // limpa o lixo do teclado 
	    limpar(); // limpa a tela
	    
	    switch(escolhaMenu){
	    	case 0:
	    		// case 0 apenas para evitar que o switch caia no default
	    	break;
	    	
	    	case 1:
	    		// Case 1 - Comprar ingresso
	    		// usuario devera escolher uma sessao que exista, caso contrario ele entra em um looping
	    		// enquanto verificaSessao for == 0, programa não continua, entra no loop de escolher a sessao
	    		do{
	    			verificaSessao = 0;
					printf("\n\tCOMPRA DE INGRESSOS");
					
					menuFilmes();
					printf("\n\n\tSessão escolhida: ");
					scanf("%d", &escolhaSessao);
					varrer();
					// printar e receber o numero da sessao como retorno/ caso informe um valor invalido, retorno = 0
					verificaSessao = sessaoEscolhida(escolhaSessao);
					
				}while( verificaSessao == 0);
				
				// verificar se há cadeiras na sessao-1(posição no vetor) escolhida
				if(sala[verificaSessao-1] > 0){
					do{
						limpar();
						// printar na tela a sessao escolhida
						sessaoEscolhida(verificaSessao);
						
						printf(" - Ingressos Restantes: %d\n", sala[verificaSessao-1]);
						printf("\n\tInforme a quantidade de ingressos?\n\t");
						scanf("%d", &qntdIngressos);
						varrer();
						
						// caso seja informado um valor negativo, mostra erro.
						if(qntdIngressos < 0){
							printf("\n\tFavor informar um valor valido!\n");
							Sleep(800);
						}else{
							// verificar se a quantidade de cadeiras restantes - qntd de ingressos informados, sao maiores ou igual a 0
							// ex: 4 cadeiras restantes - 6 ingressos a serem comprados = nao entra no if, pois a sessao nao possui 6 cadeiras restantes	
							if(sala[verificaSessao-1] - qntdIngressos >= 0){
								printf("Confirmar Compra?");
								scanf("%c", &confirmar);
								varrer();
								if(confirmar == 'S' || confirmar == 's'){
									sala[verificaSessao-1] = sala[verificaSessao-1] - qntdIngressos;
								}
							}else{
								qntdIngressos = -1;
								printf("Quantidade de ingressos indisponivel. Restam apenas %d", sala[verificaSessao-1]);
								pausar();
							}
						}						
					// verificar, caso entre com numero negativo ou entrar com um numero maior que o numero de cadeiras total da sessao, entra em um loop	
					}while(qntdIngressos < 0);
				}
			break;
			
			case 2:
				limpar();
				printf("\nCadastro Cliente Fidelidade!\n");
				
				// sempre ir aumentando o tamanho do vetor dinamicamente
				contFidelidade = contFidelidade + 1;
				
				// chama a funcao para cadastrar, passa cf(struct) e contFidelidade(tamanho do vetor)
				cadastroFidelidade(cf, contFidelidade);
				
			break;
			
			case 3:
				
				if(contFidelidade > 0){
				
					limpar();
					printf("\n\tLista de clientes cadastrados\n\n");
					printf("Total de clientes: %d", contFidelidade);
					
					listarClientes(cf, contFidelidade);
				}
			break;
			
			case 4:
				do{
					limpar();
					printf("\n\tBUSCA / EDIÇÃO\n\n");
					menuBusca();
					printf("Informe a opção de busca: ");
					scanf("%d", &opBusca);
					varrer();
					
					switch(opBusca){
						case 0:
							printf("\nSaindo");
							Sleep(300);
							printf(".");
							Sleep(300);
							printf(".");
							Sleep(300);
							printf(".");
							Sleep(300);
						break;
						case 1:
							printf("\tCADASTROS ATIVOS\n");
							verificaBusca = buscarAtivos(cf, contFidelidade);
							
						break;
						case 2:
							printf("\tCADASTROS INATIVOS\n");
							verificaBusca = buscarInativos(cf, contFidelidade);
							
						break;
						default:
							printOpInva();
							opBusca = -1;
						break;
						
					}
					
					if((opBusca == 1 || opBusca == 2 || opBusca == 3) && verificaBusca == 1){
						printf("Para EDITAR digite 1 / Para SAIR digite 0\n");
						scanf("%i", &opEdicao);
						varrer();
						
						if(opEdicao == 1){
							buscaCPF(cf, contFidelidade);
						}
					}
					
				}while(opBusca == -1);
			break;
			
			case 5:
				for(int i = 0; i < 4; i++){
    				printf("Sessao %d - Status: %d cadeiras restantes.\n", i+1, sala[i]);
				}
				printf("\n\n");
				system("pause");
			break;
			
			default:
				printOpInva();
			break;
		}
	    
    }while(escolhaMenu != 0);
    
    
    system("pause");
    return 0;
}
