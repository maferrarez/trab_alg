#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "MyBibTrab.h" 

struct pessoa{
	char nome[100], cpf[12], telefone[20];
	int idade, pontos, id, status;
};

void cadastrarPessoa(struct pessoa p[], int n){
	n = n - 1;
	printf("Informe seu nome: ");
	gets(p[n].nome);
	varrer();
	printf("\n\nInforme seu cpf: ");
	gets(p[n].cpf);
	varrer();
	printf("\n\nInforme seu telefone: ");
	gets(p[n].telefone);
	varrer();
	printf("\n\nInforme sua idade: ");
	scanf("%d", &p[n].idade);
	varrer();
	p[n].id = n;
	p[n].status = 1;
	p[n].pontos = 0;
}

void mostrarCadastros(struct pessoa p[], int n){
	printf("%d pessoas cadastradas.\n", n);
	for(int i = 0; i < n; i++){
		printf("\nNome: %s", p[i].nome);
		printf("\nCPF: %s", p[i].cpf);
		printf("\nTelefone: %s", p[i].telefone);
		printf("\nIdade: %d", p[i].idade);
		printf("\nId: %d", p[i].id);
		printf("\nStatus: %d", p[i].status);
		printf("\nPontos: %d\n", p[i].pontos);
	}
}

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    SetConsoleOutputCP (28591); // leitura da tabela Latina (escrita) 
    SetConsoleCP(28591);//Acentuação para funções (leitura) funções na bib windows
    
    int i, escolha, n = 0;
    struct pessoa p[n];

    do{
	
	    printf("Escolha: ");
	    scanf("%d", &escolha);
	    varrer();
	    limpar();
	    switch(escolha){
	    	case 1:
	    		printf("\nTodos os Cadastros:\n\n");
	    		if(n > 0){
	    			mostrarCadastros(p, n);
	    			pausar();
	    		}
	    	break;
	    	
	    	case 2:
	    		n = n + 1;
	    		cadastrarPessoa(p,n);
	    	break;
	    	limpar();
	    	pausar();
		}
    }while(escolha != 0);
    
    system("pause");
    return 0;
}
