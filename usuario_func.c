#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*CADASTRO*/
void cadastro(){
    FILE *arquivo;
	char nome[100],email[100],senha[100],comsenha[100];

	arquivo = fopen("arquivos/usuario.txt", "a");

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

/*ENTRAR*/
int entrar(int* ponto){

	FILE *arquivo;
	arquivo = fopen("arquivos/usuario.txt", "r");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo!\n");
		return 1;
	}

	/*QUANTIDADE DE USUARIOS */
	int total_usuarios = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_usuarios++;
	}
	fclose(arquivo);
	arquivo = fopen("arquivos/usuario.txt", "r");
	const int total = total_usuarios;
	char lista_usuario[total][3][100];
	int indice = 0;

	/*COLOCANDO OS DADOS NA MATRIZ */
	while(!feof(arquivo)){

		fscanf(arquivo, "%s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2]); indice = indice + 1;
	}

	fclose(arquivo);
	char dados[2][100];
	int entrou = 0;
	printf("Digite seu email:\n");
	scanf("%s", dados[0]);

	printf("Digite sua senha:\n");
	scanf("%s", dados[1]);
    int i;
	for(i=0; i < total; i++){
		if(strcmp(lista_usuario[i][1], dados[0]) == 0 && strcmp(lista_usuario[i][2], dados[1]) == 0){
			entrou = 1;
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

/*ESCCOLHER*/

int escolher(){
    char opcao[100];
    int opcao_valida = 0;
    while(!opcao_valida){
	    printf("Digite '1' para ENTRAR ou '2' para fazer o CADASTRO:\n");
	    scanf("%s", &opcao);
	   if(strcmp(opcao,"1")==0){
        return 0; // entrar
    }
       if(strcmp(opcao,"2")==0){
        return 1; // cadastro

	}


   	}

}
