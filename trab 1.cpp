#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<conio.h>
#include<time.h>
#include <windows.h>
#include "MyBibTrab.h"

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    SetConsoleOutputCP (28591); // leitura da tabela Latina (escrita) 
    SetConsoleCP(28591);//Acentuação para funções (leitura) funções na bib windows
    
    // cinema / ingressos
    int qntdIngressos, sala[4];
	char confirmar;
	
    // vars escolhas / switch
    int escolhaMenu, escolhaSessao;
    
    // vars de verificação
    int verificaSessao;
    
	// alimentar as salas com o valor 50
    for(int i = 0; i < 4; i++){
    	sala[i] = 50;
	}
    
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
	    		// enquanto verificaSessao for == 0, programa não continua
	    		do{
	    			verificaSessao = -1;
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
