/*BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*CADASTRO*/
void cadastro(){
    FILE *arquivo;
    /*VARIAVEIS*/
	char nome[100],email[100],senha[100],comsenha[100];
	/*ARQUIVO DOS USUARIOS GERAL*/
	arquivo = fopen("arquivos/usuario.txt", "a");
	//OBS: para funcionamento do codigo ? necessario criar esse arquivo antes, caso nao tenha o codigo criar? um arquivo
	
	printf("Digite o nome de usuario: ");
	scanf("%s",&nome);
	int saiu_email =0;
	
	/*VERIFICA??O DO EMAIL*/
	while(saiu_email==0)
	{
		printf("Digite o email: ");
		scanf("%s",&email);
		int i=0;
		/*PERCORRE TODA A VARIAVEL EM BUSCA DO @*/
		for(i=1;i<100;i++){
			if(email[i]=='@'){
				saiu_email=1;
			}
		}
		if(saiu_email!=1){
			printf("Falta o @, email invalido\n");
		}
	}

	int saiu = 0;
	/*VERIFICA??O DA SENHA*/
	while(saiu==0){
        printf("Digite a senha: ");
		scanf("%s",&senha);
		printf("confirme sua senha: ");
		scanf("%s", &comsenha);
		if(strcmp(senha,comsenha)==0){
			saiu = 1;
			/*esse 0 mostra indica a quantidade de listas de favoritos*/
			fprintf(arquivo, "%s %s %s 0\n", nome,email,senha);
		}
		else{
			printf("as senhas nao correspondem\n");
			system("pause");

		}
	}

	fclose(arquivo);
	printf("Dados gravados com sucesso!\n");


}

/*FUN??O PARA ENTRAR*/
int entrar(int* ponto){

	FILE *arquivo;
	/*ARQUIVOS DOS USUARIOS GERAIS*/
	arquivo = fopen("arquivos/usuario.txt", "r");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo!\n");
		return 1;
	}
	int total_usuarios = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_usuarios++;
	}
	fclose(arquivo);
	arquivo = fopen("arquivos/usuario.txt", "r");
	const int total_users = total_usuarios;
	char lista_usuario[total_users][4][100];
	int indice = 0;
	/*pegando todas as informa??es nome/email/senha/quantidade_favoritos */
	while(!feof(arquivo)){ 
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]); 
		indice = indice + 1; 
	}
	fclose(arquivo);
	char dados[2][100];
	int entrou = 0;
	/*usuario ira digitar seu email*/
	printf("Digite seu email:\n");
	scanf("%s", dados[0]);
	/*usuario ira digitar sua senha*/
	printf("Digite sua senha:\n");
	scanf("%s", dados[1]);
    int i;
	for(i=0; i <= total_users; i++){

		/*verifica se h? alguma correspondencia de email e senha na lista*/
		if(strcmp(lista_usuario[i][1], dados[0]) == 0 && strcmp(lista_usuario[i][2], dados[1]) == 0){
			entrou = 1;
			/*muda a variavel indice para o sistema sempre guardar o indice do usuario no sistema*/
			
			*ponto = i;
			system("cls");
			printf("Seja bem vindo %s\n\n\n", lista_usuario[i][0]);
			system("pause");
			return 1;
		}
	}

	if(!entrou){
		printf("Usuario nao encontrado\n");
		return 0;
	}
}

/*FUN??O ESCCOLHER*/

int escolher(){
    char opcao[100];
    int opcao_valida = 0;
    while(!opcao_valida){
	    printf("Digite 1 para fazer CADASTRO \nDigite 2 para ENTRAR\n\n");
	    scanf("%s", &opcao);
	   if(strcmp(opcao,"1")==0){
        return 0; // cadastro
    }
       if(strcmp(opcao,"2")==0){
        return 1; // entrar

	}


   	}

}

