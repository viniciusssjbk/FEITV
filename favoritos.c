/*BIBLIOTECAS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*FUN??O PARA PEGAR O NOME DA LISTA DO USUARIO*/
  void pegar_nome_lista(int indice_usuario, int indice_atual){
 	FILE* arquivo;
 	/*PEGANDO O NOME DO USUARIO*/
 	arquivo = fopen("arquivos/usuario.txt", "r");
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
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]);
		indice = indice + 1;
	}
	fclose(arquivo);
	/*PEGANDO O ARQUIVO DESEJADO DO USUARIO*/
	char escolhendo_arq[200];
	char numero_arq[10];
	char nome_arquivo[100];
	sprintf(numero_arq,"%d",indice_atual);
 	sprintf(escolhendo_arq,"arquivos/favoritos/%s_lista_%s.txt",lista_usuario[indice_usuario][0], numero_arq);
 	arquivo = fopen(escolhendo_arq, "r");
 	fscanf(arquivo,"%s", nome_arquivo);
 	fclose(arquivo);
 	/*PRINTANDO O NOME DA LISTA DO USUARIO*/
 	printf("%s\n",nome_arquivo);
 }




/*FU??O DE FAVORITOS DO USUARIO*/
 int verifica_favoritos_quant(int indice_usuario){


	system("cls");
	FILE *arquivo;

	/*PEGANDO O NOME DO USUARIO*/
	arquivo = fopen("arquivos/usuario.txt", "r");
	int total_usuarios = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_usuarios++;
	}
	fclose(arquivo);
	arquivo = fopen("arquivos/usuario.txt", "r");
	const int total_users = total_usuarios;
	/*Essa ? a unica lista de usuario que pega todos os valores pois nessa parte pega o ultimo conteudo da lista que ? referente a o numeros de favoritos que o usuario possui */
	char lista_usuario[total_users][4][100];
	int indice = 0;
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]);
		indice = indice + 1;
	}
	fclose(arquivo);


	/*convertendo para inteiro*/
	int quant_lista_fav = atoi(lista_usuario[indice_usuario][3]);
	if(quant_lista_fav==0){

		return 0;
	}

	int p =0;
	printf("-------------------------------\n");
	for(p=1;p<=quant_lista_fav;p++){

		printf("%d -",p);
		pegar_nome_lista(indice_usuario, p);

	}
	printf("-------------------------------\n");
	printf("o que deseja fazer?\n");
	/*VERIFICA SE O USUARIO CHEGOU NO LIMITE DE CRIA??O DE LISTAS*/
	if(quant_lista_fav==5){
			printf("____________________________________________________\n");
			printf("..  Nao e possivel adicionar mais uma lista  ..\n");
			printf("1. Remover uma lista\n");
			printf("2. Editar uma lista\n");
			printf("3. Sair\n");
			printf("____________________________________________________\n");
			int selecao_lista;
			selecao_lista = 0;
			scanf("%d",&selecao_lista);
			//para nao quebrar o valor do retorno para o menu
			selecao_lista = selecao_lista+1;
			int barreira =1;
			while(barreira>0){
				if(selecao_lista==2){
					return 2;
				}
				if(selecao_lista==3){
					return 3;
				}
				if(selecao_lista==4){
					return 4;
				}
				else{
					printf("Selecione uma op??o correta");
				}
			}
	}
	else{

			printf("____________________________________________________\n");
			printf("1. Adicionar mais uma lista (limite maximo: 5)\n");
			printf("2. Remover uma lista\n");
			printf("3. Editar uma lista\n");
			printf("4. Sair\n");
			printf("____________________________________________________\n");
			int selecao_lista;
			selecao_lista = 0;
			scanf("%d",&selecao_lista);
			int barreira =1;
			while(barreira>0){
				if(selecao_lista==1){
					return 1;
				}
				if(selecao_lista==2){
					return 2;
				}
				if(selecao_lista==3){
					return 3;
				}
				if(selecao_lista==4){
					return 4;
				}
				else{
					printf("Selecione uma op??o correta");
				}
			}
	}



 }



/*CRIA??O DE LISTA DE FAVORITOS*/
 void criar_favoritos(int indice_usuario){
 	system("cls");
 	//primeiro usuario digita o nome para sua lista
    printf("Digite o nome da sua lista:\n");
 	char nome_digitado[100];
	scanf("%s",nome_digitado);



	/*PEGANDO O NOME DO USUARIO*/
	FILE *arquivo;
	arquivo = fopen("arquivos/usuario.txt", "r");
	int total_usuarios = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_usuarios++;
	}
	fclose(arquivo);
	arquivo = fopen("arquivos/usuario.txt", "r");
	const int total_users = total_usuarios;
	/*Essa ? a unica lista de usuario que pega todos os valores pois nessa parte pega o ultimo conteudo da lista que ? referente a o numeros de favoritos que o usuario possui */
	char lista_usuario[total_users][4][100];
	int indice = 0;
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]);
		indice = indice + 1;
	}
	fclose(arquivo);


	/*adiciona mais 1 na lista dos usuarios*/
	int listagem_fav = (atoi(lista_usuario[indice_usuario][3]) + 1);

	sprintf(lista_usuario[indice_usuario][3], "%d", listagem_fav);
	/*SALVANDO O ARQUIVO ATUALIZADO*/
	arquivo = fopen("arquivos/usuario.txt", "w");
	int k =0;
	for(k=0;k<total_users;k++){
		if(k==indice_usuario){
			fprintf(arquivo, "%s %s %s %s\n", lista_usuario[k][0],lista_usuario[k][1],lista_usuario[k][2],lista_usuario[k][3]);
		}
		else{
			fprintf(arquivo, "%s %s %s %s\n",  lista_usuario[k][0],lista_usuario[k][1],lista_usuario[k][2],lista_usuario[k][3]);
		}

	}
	fclose(arquivo);

	/*criando o arquivo_favoritos*/
	char nome_arquivo[200];
	char numero_arq[10];
	sprintf(numero_arq,"%d",listagem_fav);
	sprintf(nome_arquivo,"arquivos/favoritos/%s_lista_%s.txt",lista_usuario[indice_usuario][0],numero_arq);
	arquivo = fopen(nome_arquivo, "a+");

	if (arquivo == NULL) {
	    printf("Erro ao abrir/criar arquivo\n");
	    system("pause");
	    system("cls");
	}
	else {
	    fprintf(arquivo,"%s\n",nome_digitado);
	    fclose(arquivo);

	}
	system("cls");

 }


void remover_lista(int indice_usuario){
	system("cls");
	/*PEGANDO O NOME DO USUARIO*/
	FILE *arquivo;
	arquivo = fopen("arquivos/usuario.txt", "r");
	int total_usuarios = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_usuarios++;
	}
	fclose(arquivo);
	arquivo = fopen("arquivos/usuario.txt", "r");
	const int total_users = total_usuarios;
	/*Essa ? a unica lista de usuario que pega todos os valores pois nessa parte pega o ultimo conteudo da lista que ? referente a o numeros de favoritos que o usuario possui */
	char lista_usuario[total_users][4][100];
	int indice = 0;
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]);
		indice = indice + 1;
	}
	fclose(arquivo);

	int indice_atual =0;
	int selecao_fav;
	int quant_fav = atoi(lista_usuario[indice_usuario][3]);

	for(indice_atual=1;indice_atual<=quant_fav;indice_atual++){

		printf("%d -",indice_atual);
		pegar_nome_lista(indice_usuario,indice_atual);

	}

	int brecagem=1;
	while(brecagem>0){

		printf("Digite o numero da lista que quer remover:\n");
		scanf("%d",&selecao_fav);
		if(selecao_fav>0 && selecao_fav<=quant_fav){
			brecagem=0;
		}
	}

	char arquivo_fav_user[200];
	char arquivo_fav_user_novo[200];
	sprintf(arquivo_fav_user,"arquivos/favoritos/%s_lista_%d.txt",lista_usuario[indice_usuario][0],selecao_fav);
	remove(arquivo_fav_user);
	int l;
	/*a lista ? removida e a posterior a ela, toma a posi??o dela. exemplo: removido a lista 3, a 4 se torna a 3 e a 5 se torna a 4*/
	for(l=selecao_fav;l<quant_fav;l++){
		sprintf(arquivo_fav_user,"arquivos/favoritos/%s_lista_%d.txt",lista_usuario[indice_usuario][0],l+1);
		sprintf(arquivo_fav_user_novo,"arquivos/favoritos/%s_lista_%d.txt",lista_usuario[indice_usuario][0],l);
		rename(arquivo_fav_user,arquivo_fav_user_novo);

	}
	quant_fav = quant_fav-1;
	sprintf(lista_usuario[indice_usuario][3],"%d",quant_fav);



	arquivo = fopen("arquivos/usuario.txt", "w");
	int k =0;
	for(k=0;k<total_users;k++){
		/*atualiza o valor da quantidade de listas do usuario*/
		if(k==indice_usuario){
			fprintf(arquivo, "%s %s %s %s\n",lista_usuario[k][0],lista_usuario[k][1],lista_usuario[k][2],lista_usuario[k][3]);
		}
		else{
			fprintf(arquivo, "%s %s %s %s\n",lista_usuario[k][0],lista_usuario[k][1],lista_usuario[k][2],lista_usuario[k][3]);
		}

	}
	fclose(arquivo);

}


/*TELA DE EDI??O DAS LISTAS*/
int tela_favoritos(int indice_usuario, int selecao){
	system("cls");
	FILE *arquivo;

	/*PEGANDO O NOME DO USUARIO*/
	arquivo = fopen("arquivos/usuario.txt", "r");
	int total_usuarios = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_usuarios++;
	}
	fclose(arquivo);
	arquivo = fopen("arquivos/usuario.txt", "r");
	const int total_users = total_usuarios;
	char lista_usuario[total_users][1][100];
	int indice = 0;
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]);
		indice = indice + 1;
	}
	fclose(arquivo);

	/*PEGANDO O ARQUIVO DE FAVORITOS DO USUARIO*/
	char arquivo_favorito[100];
	sprintf(arquivo_favorito, "arquivos/favoritos/%s_lista_%d.txt", lista_usuario[indice_usuario][0],selecao);
	arquivo = fopen(arquivo_favorito, "r");
	if(arquivo==NULL){

		printf("Voce ainda nao possui nenhum lista nos favoritos\n");
		system("pause");
		return 0;

	}else{
		int total_filmes = 0;
		char linha[200];
		while (fgets(linha, sizeof(linha), arquivo) != NULL) {
			total_filmes++;
		}
		fclose(arquivo);
		if(total_filmes==1){
			/*verifica se o usuario tem filme na sua lista de favoritos*/
			printf("Voce ainda nao possui nenhum filme nos favoritos\n");
			system("pause");
			char x[3];
			printf("Deseja colocar um filme na lista?'sim' ou 'nao'\n");
			scanf("%s",&x);
			if(strcmp(x,"sim")==0){
				selecao= selecao+10;
				return selecao;
			}
			else{
				return 0;
			}
		}
		else{

				arquivo = fopen(arquivo_favorito, "r");
				const int total = total_filmes;
				char lista_filmes[total][100];
				int indice_filme = 0;
				while (fgets(lista_filmes[indice_filme], 100, arquivo) != NULL) {
			    	indice_filme++;
				}
				fclose(arquivo);
				int remover_n =0;
				for(remover_n=0;remover_n<total;remover_n++){

					lista_filmes[remover_n][strcspn(lista_filmes[remover_n], "\n")] = '\0';
				}
				int i =0;
				int id =0;
				/*painel dos filmes*/
				printf("____________________________________________\n");
				printf("|   ID  |          FILME                   |\n");
				for(i=1;i<total;i++){
					id = id+1;
					printf("| %3d   | %-33s|\n",id,lista_filmes[i]);
				}
				printf("____________________________________________\n");
				return selecao;
		}


	}


}
/*SELECIONANDO UMA LISTA PARA EDITAR*/
int editar_lista(int indice_usuario){
	system("cls");
	/*PEGANDO O NOME DO USUARIO*/
	FILE *arquivo;
	arquivo = fopen("arquivos/usuario.txt", "r");
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
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]);
		indice = indice + 1;
	}
	fclose(arquivo);

	int indice_atual =0;
	int selecao_fav;

	int quant_fav = atoi(lista_usuario[indice_usuario][3]);

	for(indice_atual=1;indice_atual<=quant_fav;indice_atual++){

		printf("%d -",indice_atual);
		pegar_nome_lista(indice_usuario,indice_atual);

	}

	int brecagem=1;
	while(brecagem>0){

		printf("Digite o numero da lista:\n");
		scanf("%d",&selecao_fav);
		if(selecao_fav>0 && selecao_fav<=quant_fav){
			brecagem=0;
		}
	}
	int tela_selecao;
	tela_selecao = tela_favoritos(indice_usuario,selecao_fav);
	return tela_selecao;


}

