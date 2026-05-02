/*
|***********************************|
|Autor: Vinicius Santos de Oliveira |
|Projeto: FEItv                     |
|***********************************|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*CADASTRO*/
void cadastro(){
    FILE *arquivo;
	char conta[5];
	char nome[100],email[100],senha[100],comsenha[100];
	arquivo = fopen("usuario.txt", "w");
	printf("Digite o nome de usuario: ");
	scanf("%s",&nome);
	printf("Digite o email: ");
	scanf("%s",&email);
	int saiu = 0;
	while(saiu==0){
        printf("Digite a senha: ");
		scanf("%s",&senha);
		printf("confirme sua senha: ");
		scanf("%s", &comsenha);
		if(strcmp(senha,comsenha)==0){
			saiu = 1;
		}
		else{
			printf("as senhas nao correspondem\n");
			system("pause");
			
		}
	}

	fclose(arquivo);
	printf("Dados gravados com sucesso!\n");


}
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
/*MENU*/
void menu(char* usuario){

	}

int main() {
	system("color 02");
	const int total =1;
	char* lista_usuario[total][3];
	lista_usuario[0][0] = "ADM";
	lista_usuario[0][1] = "adm123";
	lista_usuario[0][2]= "vinijr";
	int indice =0;
	int logado = 0;
	logo();
	
	
    while(logado==0){
        char cad;
		int *ponteiro = &indice;
		printf("Digite '1' para ENTRAR ou '2' para fazer o CADASTRO:\n");
		scanf("%s",&cad);
		if(cad=='2'){
			cadastro();
		}
		else if(cad=='1'){
			char dados[2][50];
			int entrou = 0,i;
			printf("Digite seu email:\n");
			scanf("%s",dados[0]);
			printf("Digite sua senha:\n");
			scanf("%s",dados[1]);
			for(i=0;i<total;i++){
				if(strcmp(lista_usuario[i][0],dados[0])==0 && strcmp(lista_usuario[i][1],dados[1])==0){
					entrou = 1;
					*ponteiro = i;
					logado = 1;
				}else{
               		i = i+1;
            	}
			}
			if(entrou){
				printf("Seja bem vindo %s\n",lista_usuario[indice][2]);
				
			}
			else{
				printf("Usuario nao encontrado\n");
				}
		}
		else{
			printf("Selecione 1 ou 2...\n");
		}
	}
	menu(&lista_usuario[indice]);
	system("pause");
	return 0;
}
