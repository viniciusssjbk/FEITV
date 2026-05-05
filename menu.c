#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*LOGO DO MENU*/
void logo_menu(){
	int i =0;
	for(i=0;i<=10;i++){
		printf("/-");
	}
	printf("\n");
	printf("  1. Buscar filmes\n");
	printf("  2. Gerenciar seus favoritos\n");
	printf("  3. Sair\n");
	printf("\n");
	for(i=0;i<=10;i++){
		printf("/-");
	}
	printf("\n");
}

/*TELA_FAVORITOS*/
int tela_favoritos(int indice_usuario){
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
	char lista_usuario[total_users][3][100];
	int indice = 0;
	while(!feof(arquivo)){ 
		fscanf(arquivo, "%s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2]); 
		indice = indice + 1; 
	}
	fclose(arquivo);
	
	/*PEGANDO O ARQUIVO DE FAVORITOS DO USUARIO*/
	char arquivo_favorito[100];
	sprintf(arquivo_favorito, "arquivos/favoritos/%s_favoritos.txt", lista_usuario[indice_usuario][0]);
	arquivo = fopen(arquivo_favorito, "r");
	if(arquivo==NULL){
		
		printf("Você ainda não possui nenhum filme nos favoritos\n");
		system("pause");
		return 1;
		
	}else{
		int total_filmes = 0;
		char linha[200];
		while (fgets(linha, sizeof(linha), arquivo) != NULL) {
			total_filmes++;
		}
		fclose(arquivo);
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
		printf("____________________________________________\n");
		printf("|   ID  |          FILME                   |\n");
		for(i=0;i<total;i++){
			id = id+1;
			printf("| %3d   | %-33s|\n",id,lista_filmes[i]);
		}
		printf("____________________________________________\n");
		return 0;
		
		
	
	}

	
}



/*FAVORITAR*/
void favoritos(int indice_filme_favoritar, int total, int indice_usuario){
	FILE* arquivo;
	arquivo = fopen("arquivos/filmes.txt", "r");
	char lista_filmes[total][100];
	int indice_filme = 0;
	while (fgets(lista_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	
	
	arquivo = fopen("arquivos/usuario.txt", "r");
	int total_usuarios = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_usuarios++;
	}
	fclose(arquivo);
	arquivo = fopen("arquivos/usuario.txt", "r");
	const int total_users = total_usuarios;
	char lista_usuario[total_users][3][100];
	int indice = 0;
	while(!feof(arquivo)){ 
		fscanf(arquivo, "%s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2]); 
		indice = indice + 1; 
	}
	fclose(arquivo);
	char arquivo_favorito[100];
	sprintf(arquivo_favorito, "arquivos/favoritos/%s_favoritos.txt", lista_usuario[indice_usuario][0]);
	arquivo = fopen(arquivo_favorito,"a+");
	if (arquivo == NULL) {
		fprintf(arquivo, "%s", lista_filmes[indice_filme_favoritar]);
	}
	else{
		char lista_favoritos[total][100];
		int indice_favoritos = 0;
		int possui =0;
		while (fgets(lista_favoritos[indice_favoritos], 100, arquivo) != NULL) {
		    if(strcmp(lista_favoritos[indice_favoritos],lista_filmes[indice_filme_favoritar])==0){
		    	possui=1;
			}
			indice_favoritos++;
		}
		if(!possui){
			fprintf(arquivo, "%s", lista_filmes[indice_filme_favoritar]);
		}
		
	}
	
	fclose(arquivo);
}

/*EXCLUIR*/
void excluir(int indice_usuario){
	int selecao_id;
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
	char lista_usuario[total_users][3][100];
	int indice = 0;
	while(!feof(arquivo)){ 
		fscanf(arquivo, "%s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2]); 
		indice = indice + 1; 
	}
	fclose(arquivo);
	
	/*PEGANDO O ARQUIVO DE FAVORITOS DO USUARIO*/
	char arquivo_favorito[100];
	sprintf(arquivo_favorito, "arquivos/favoritos/%s_favoritos.txt", lista_usuario[indice_usuario][0]);
	arquivo = fopen(arquivo_favorito, "r");
	int total_filmes = 0;
	char linha_filmes[200];
	while (fgets(linha_filmes, sizeof(linha_filmes), arquivo) != NULL) {
		total_filmes++;
	}
	fclose(arquivo);
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
	int excluir;
	excluir=0;
	while(!excluir){
		printf("Digite o ID do filme que sera excluido:\n");
		scanf("%d",&selecao_id);
		selecao_id= selecao_id-1;
		if(selecao_id>0 && selecao_id<total){
			excluir=1;
		}
	}
	system("cls");
	int indice_comeco;
	int seguinte;
	/*O SISTEMA VAI SUBSTITUIR O VALOR DO INDICE ATUAL COM O PROXIMO FAZENDO QUE NO FINAL
	O PENULTIMO E O ULTIMO FIQUEM COM O MESMO VALOR POREM O ULTIMO INDICE NAO VAI PARA O 
	ARQUIVO VAI ATE O PENULTIMO*/
	for(indice_comeco=selecao_id;indice_comeco<total-1;indice_comeco++){
		seguinte= indice_comeco+1;
		strcpy(lista_filmes[indice_comeco],lista_filmes[seguinte]);
		
	}
	
	arquivo = fopen(arquivo_favorito, "w");
	for(indice_comeco=0;indice_comeco<total-1;indice_comeco++){
		fprintf(arquivo,"%s\n",lista_filmes[indice_comeco]);
	}
	fclose(arquivo);
	printf("Excluido com sucesso..\n");
	system("pause");
	system("color03");
	
	
}

/*CURTIR*/
void curtir(int indice_curtida_filme,int total){
	
	FILE *arquivo;
	arquivo = fopen("arquivos/curtidas_filme.txt", "r");
	char curtidas_filmes[total][100];
	int indice_filme = 0;

	while (fgets(curtidas_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	
	/*AUMENTANDO O NUMERO DE CURTIDAS*/
	int curtida = (atoi(curtidas_filmes[indice_curtida_filme]) + 1);
	
	sprintf(curtidas_filmes[indice_curtida_filme], "%d", curtida);
	/*SALVANDO O ARQUIVO ATUALIZADO*/
	arquivo = fopen("arquivos/curtidas_filme.txt", "w");
	int k =0;
	for(k=0;k<total;k++){
		if(k==indice_curtida_filme){
			fprintf(arquivo, "%s\n", curtidas_filmes[k]);
		}
		else{
			fprintf(arquivo, "%s", curtidas_filmes[k]);
		}
			
	}
	fclose(arquivo);
}

/*PAINEL DE FILMES*/
void painel_filmes(){
	system("cls");
	FILE *arquivo;
	arquivo = fopen("arquivos/filmes.txt", "r");
	/*QUANTIDADE DE FILMES */
	int total_filmes = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_filmes++;
	}
	fclose(arquivo);
	
	arquivo = fopen("arquivos/filmes.txt", "r");
	const int total = total_filmes;
	char lista_filmes[total][100];
	int indice_filme = 0;

	/*COLOCANDO OS DADOS NA MATRIZ */
	/* LENDO LINHA COMPLETA */
	while (fgets(lista_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	/*COLOCANDO AS INFORMAÇÔES DOS FILMES EM ORDEM*/
	arquivo = fopen("arquivos/info_filme.txt", "r");
	char info_filmes[total][900];
	indice_filme = 0;

	while (fgets(info_filmes[indice_filme], 900, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	/*COLOCANDO AS CURTIDAS DOS FILMES EM ORDEM*/
	arquivo = fopen("arquivos/curtidas_filme.txt", "r");
	char curtidas_filmes[total][100];
	indice_filme = 0;

	while (fgets(curtidas_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	int remover_n =0;
	for(remover_n=0;remover_n<total;remover_n++){
	lista_filmes[remover_n][strcspn(lista_filmes[remover_n], "\n")] = '\0';
	info_filmes[remover_n][strcspn(info_filmes[remover_n], "\n")] = '\0';
	curtidas_filmes[remover_n][strcspn(curtidas_filmes[remover_n], "\n")] = '\0';
	
	}
	int i =0;
	int id =0;
	printf("___________________________________________________________\n");
	printf("|   ID  |          FILME                   |  CURTIDAS    |\n");
	for(i=0;i<total;i++){
		id = id+1;
		printf("| %3d   | %-33s|   %-10s |\n",id,lista_filmes[i],curtidas_filmes[i]);
	}
	printf("___________________________________________________________\n");
}

/*BUSCAR*/
void buscar(int indice_usuario){
	system("cls");
	FILE *arquivo;
	arquivo = fopen("arquivos/filmes.txt", "r");
	/*QUANTIDADE DE FILMES */
	int total_filmes = 0;
	char linha[200];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		total_filmes++;
	}
	fclose(arquivo);
	
	arquivo = fopen("arquivos/filmes.txt", "r");
	const int total = total_filmes;
	char lista_filmes[total][100];
	int indice_filme = 0;

	/*COLOCANDO OS DADOS NA MATRIZ */
	/* LENDO LINHA COMPLETA */
	while (fgets(lista_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	/*COLOCANDO AS INFORMAÇÔES DOS FILMES EM ORDEM*/
	arquivo = fopen("arquivos/info_filme.txt", "r");
	char info_filmes[total][900];
	indice_filme = 0;

	while (fgets(info_filmes[indice_filme], 900, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	/*COLOCANDO AS CURTIDAS DOS FILMES EM ORDEM*/
	arquivo = fopen("arquivos/curtidas_filme.txt", "r");
	char curtidas_filmes[total][100];
	indice_filme = 0;

	while (fgets(curtidas_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	int remover_n =0;
	for(remover_n=0;remover_n<total;remover_n++){
	lista_filmes[remover_n][strcspn(lista_filmes[remover_n], "\n")] = '\0';
	info_filmes[remover_n][strcspn(info_filmes[remover_n], "\n")] = '\0';
	curtidas_filmes[remover_n][strcspn(curtidas_filmes[remover_n], "\n")] = '\0';
	
	}
	
	
	int buscando;
	int verifica_filme=0;
	int buscando_verifica= 0;
	char escolhendo_filmes[100];
	while(!buscando_verifica){
		painel_filmes();
		verifica_filme=0;
		printf("Digite o id do filme:(para sair digite 0)\n");
		scanf("%d",&buscando);
		if(buscando==0){
			buscando_verifica = 1;
		}
		else if(buscando>0 && buscando<=total){
			while(!verifica_filme){
				system("cls");
				printf("|NOME: %-15s|\n",lista_filmes[buscando-1]);
				printf("|curtidas: %-11s|\n",curtidas_filmes[buscando-1]);
				printf("INFO:\n %s\n",info_filmes[buscando-1]);
				printf("\nO que deseja fazer?\n\n");
				printf("/-/-/-/-/-/-/-/-/-/-/-/\n");
				printf("1. Continuar pesquisando\n");
				printf("2. Favoritar esse filme\n");
				printf("3. Curtir o filme\n");
				printf("/-/-/-/-/-/-/-/-/-/-/-/\n");
				scanf("%s",escolhendo_filmes);
				if(strcmp(escolhendo_filmes,"1")==0){
					verifica_filme=1;
					system("cls");
				}
				if(strcmp(escolhendo_filmes,"2")==0){
					favoritos(buscando-1,total,indice_usuario);
					printf("Esta na sua lista de favoritos..\n");
					verifica_filme=1;
					system("pause");
				}
				if(strcmp(escolhendo_filmes,"3")==0){
					curtir(buscando-1,total);
					printf("curtido..\n");
					verifica_filme=1;
					system("pause");
				}
			}
			
		}
		else{
			printf("ID invalido...");
			system("pause");
		}
	}
}

/*MENU*/
void menu(int indice){
	system("cls");
	system("color 06");
	char escolha[100];
	int voltar_menu;
	int sair = 0;
	char selecao[100];
	while(!sair){
		logo_menu();
		printf("\n");
		scanf("%s",escolha);
		if(strcmp(escolha,"1") == 0){
			buscar(indice);
		}
		else if(strcmp(escolha,"2") ==0){
			voltar_menu=0;
			while(!voltar_menu){
				voltar_menu = tela_favoritos(indice);
				if(!voltar_menu){
					
				printf("\n\nO que deseja fazer?\n");
				printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");
				printf("1. Adicionar um filme na lista de favoritos\n");
				printf("2. Tirar um filme da lista de favoritos\n");
				printf("3. sair\n");
				printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");
				scanf("%s",selecao);
				if(strcmp(selecao,"1")==0){
					buscar(indice);
				}
				if(strcmp(selecao,"2")==0){
					excluir(indice);
				}
				if(strcmp(selecao,"3")==0){
					voltar_menu=1;
				}	
				}
			}
		}
		else if(strcmp(escolha,"3") == 0){
			sair=1;
		}
	}
	
}

