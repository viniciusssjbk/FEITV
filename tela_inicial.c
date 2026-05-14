/*
|***********************************|
|Autor: Vinicius Santos de Oliveira |
|Projeto: FEItv                     |
|***********************************|
*/
/*BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "func.h"
/*FUN??O LOGO*/
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

/*FU??O PRINCIPAL*/
int main() {
	/*PERMITIR CARACTER ESPECIAL*/
	system("chcp 65001");
	setlocale(LC_ALL, "pt_BR.UTF-8");
	/*MUDANDO A COR DO TERMINAL*/
	system("color 02");
	int indice = 0;
	logo();
	int logado =0,x;
	/*S? IR? SAIR DO LOOPING QUANDO O USUARIO 'ENTRAR'*/
	while(logado==0){
		x=escolher();
		printf("\n");
		if(!x){
			/*CHAMANDO A FUN??O CADASTRO*/
			cadastro();
			
		}
		else{
			/*VERIFICANDO SE O EMAIL E A SENHA DIGITADOS PELO USUARIO EST? CADASTRADO NO SISTEMA*/
			logado = entrar(&indice);
			
		}
	}
	/*FUN??O DO MENU*/
	menu(indice);
	system("pause");
	/*FIM DO CODIGO*/
	return 0;
}

