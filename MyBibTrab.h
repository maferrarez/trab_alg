#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<conio.h>
#include<time.h>
#include <windows.h>

void limpar(){
	system("cls");
}

void varrer(){
	fflush(stdin);
}

void pausar(){
	getch();
}

void printOpInva(){
	printf("\n\tOp��o inv�lida! Tente novamente");
	Sleep(1000);
	limpar();
}

void menuPrincipal(){
	printf(	"1 - Comprar Ingresso\n"
			"2 - Cadastro Fidelidade\n"
			"3 - Listar cadastrados\n"
			"4 - Buscar por CPF\n"
			"5 - Status das sess�es\n"
			"\n0 - Sair\n\n");
}

void menuFilmes(){
	printf("\n\n\tSESS�O 01 - SALA 01 - HORARIO 12:00 - Star Wars Epis�dio 9 - A Ascens�o Skywalker\n");
	printf("\tSESS�O 02 - SALA 01 - HORARIO 15:00 - Star Wars Epis�dio 9 - A Ascens�o Skywalker\n\n");
	printf("\tSESS�O 03 - SALA 02 - HORARIO 12:00 - Harry Poket - E a Ordem do F�lix\n");
	printf("\tSESS�O 04 - SALA 02 - HORARIO 15:00 - Harry Poket - E a Ordem do F�lix\n");
}

int sessaoEscolhida(int escolha){
	
	int resposta;
	int qntdIngressos;
		
	switch(escolha){
		case 1:
			resposta = 1;
			limpar();
			printf("\n\n\tStar Wars Epis�dio 9 - A Ascens�o Skywalker\n\n\tSESS�O 01 - SALA 01 - HORARIO 12:00");
		break;
		case 2:
			resposta = 2;
			limpar();
			printf("\n\n\tStar Wars Epis�dio 9 - A Ascens�o Skywalker\n\n\tSESS�O 02 - SALA 01 - HORARIO 15:00");
		break;
		case 3:
			resposta = 3;
			limpar();
			printf("\n\n\tHarry Poket - E a Ordem do F�lix\n\n\tSESS�O 03 - SALA 02 - HORARIO 12:00");
		break;
		case 4:
			resposta = 4;
			limpar();
			printf("\n\n\tHarry Poket - E a Ordem do F�lix\n\n\tSESS�O 04 - SALA 02 - HORARIO 15:00");
		break;
		default:
			printOpInva();
			resposta = 0;
		break;
	}
	
	return resposta;
	
}







