/*
|***********************************|
|Autor: Vinicius Santos de Oliveira |
|Projeto: FEItv                     |
|***********************************|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "func.h"
/*LOGO*/
void logo(){
	int i =0;
	for(i = 0;i<=20;i++){
		printf("*");
	}
	printf("\n   %10s","SEJA BEM VINDO");
	printf("\n    %10s\n","AO FEITV");
	for(i = 0;i<=20;i++){
		printf("*");
	}
	printf("\n");
}


int main() {
	system("chcp 65001");
	setlocale(LC_ALL, "pt_BR.UTF-8");
	system("color 02");
	int indice = 0;
	logo();
	int logado =0,x;
	while(logado==0){
		x=escolher();
		printf("\n");
		if(x){
			cadastro();
			
		}
		else{
			logado = entrar(&indice);
			
		}
	}
	menu(indice);
	system("pause");
	return 0;
}
