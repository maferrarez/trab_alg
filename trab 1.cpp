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
    
    // cinema
    int qntdIngressos, sala[4];

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
	    	break;
	    	
	    	case 1:
	    		
	    		do{
	    			verificaSessao = -1;
					printf("\n\tCOMPRA DE INGRESSOS");
					
					menuFilmes();
					printf("\n\n\tSessão escolhida: ");
					scanf("%d", &escolhaSessao);
					varrer();
					
					verificaSessao = sessaoEscolhida(escolhaSessao);
					
				}while( verificaSessao == 0);
				
				if(sala[verificaSessao-1] > 0){
					do{
						limpar();
						sessaoEscolhida(verificaSessao);
						
						printf(" - Ingressos Restantes: %d\n", sala[verificaSessao-1]);
						printf("\n\tInforme a quantidade de ingressos?\n\t");
						scanf("%d", &qntdIngressos);
						if(sala[verificaSessao-1] - qntdIngressos >= 0){
							
							sala[verificaSessao-1] = sala[verificaSessao-1] - qntdIngressos;
								
						}else{
							qntdIngressos = -1;
							printf("Quantidade de ingressos indisponivel. Restam apenas %d", sala[verificaSessao-1]);
							pausar();
						}
						
					}while(qntdIngressos < 0);
				}
			break;
			
			default:
				printOpInva();
			break;
		}
	    
    }while(escolhaMenu != 0);
    
    
    system("pause");
    return 0;
}
