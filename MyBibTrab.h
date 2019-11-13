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
	printf("\n\tOpção inválida! Tente novamente");
	Sleep(1000);
	limpar();
}

void menuPrincipal(){
	printf(	"1 - Comprar Ingresso\n"
			"2 - Cadastro Fidelidade\n"
			"3 - Listar cadastrados\n"
			"4 - Buscar por CPF\n"
			"5 - Status das sessões\n"
			"\n0 - Sair\n\n");
}

void menuFilmes(){
	printf("\n\n\tSESSÃO 01 - SALA 01 - HORARIO 12:00 - Star Wars Episódio 9 - A Ascensão Skywalker\n");
	printf("\tSESSÃO 02 - SALA 01 - HORARIO 15:00 - Star Wars Episódio 9 - A Ascensão Skywalker\n\n");
	printf("\tSESSÃO 03 - SALA 02 - HORARIO 12:00 - Harry Poket - E a Ordem do Félix\n");
	printf("\tSESSÃO 04 - SALA 02 - HORARIO 15:00 - Harry Poket - E a Ordem do Félix\n");
}

int sessaoEscolhida(int escolha){
	
	int resposta;
	int qntdIngressos;
		
	switch(escolha){
		case 1:
			resposta = 1;
			limpar();
			printf("\n\n\tStar Wars Episódio 9 - A Ascensão Skywalker\n\n\tSESSÃO 01 - SALA 01 - HORARIO 12:00");
		break;
		case 2:
			resposta = 2;
			limpar();
			printf("\n\n\tStar Wars Episódio 9 - A Ascensão Skywalker\n\n\tSESSÃO 02 - SALA 01 - HORARIO 15:00");
		break;
		case 3:
			resposta = 3;
			limpar();
			printf("\n\n\tHarry Poket - E a Ordem do Félix\n\n\tSESSÃO 03 - SALA 02 - HORARIO 12:00");
		break;
		case 4:
			resposta = 4;
			limpar();
			printf("\n\n\tHarry Poket - E a Ordem do Félix\n\n\tSESSÃO 04 - SALA 02 - HORARIO 15:00");
		break;
		default:
			printOpInva();
			resposta = 0;
		break;
	}
	
	return resposta;
	
}







