#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "func.h"

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



/*FUNCAO FAVORITAR FILME DA LISTA*/
void favoritos(int indice_filme_favoritar, int total, int indice_usuario, int selecao){
	FILE* arquivo;
	/*listas dos filmes*/
	/*? NECESSARIO TER ESSA LISTA PARA FUNCIONAMENTO DO CODIGO*/
	arquivo = fopen("arquivos/filmes.txt", "r");
	char lista_filmes[total][100];
	int indice_filme = 0;
	/*pega todos os filmes e coloca eles dentro da variavel 'lista_filmes'*/
	while (fgets(lista_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	
	/*pegando todos os usarios da lista*/
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
	/*pegando todas as informa??es nome/email/senha/quantidade_favoritos */
	while(!feof(arquivo)){ 
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]); 
		indice = indice + 1; 
	}
	fclose(arquivo);
	system("cls");
	/*pegando apenas a quantidade de favoritos do usuario logado*/
	int quant_fav = atoi(lista_usuario[indice_usuario][3]);
	if(quant_fav==0){
		printf("voce nao possui nenhuma lista.");
		system("pause");
		system("cls");
	}
	else{
	
			int indice_atual =0;
			
			int selecao_fav;
			/*verifica se a selecao da lista ja foi feita antes no codigo caso nao o usuario ter? que falar qual lista ele quer colocar o filme*/
			if(selecao==0){
			
				for(indice_atual=1;indice_atual<=quant_fav;indice_atual++){
				
					printf("%d -",indice_atual);
					pegar_nome_lista(indice_usuario,indice_atual);
				
				}
			}
			int brecagem=1;
			while(brecagem>0){
				if(selecao==0){
				
				printf("Digite o numero da lista que deixara salvo o filme:\n");
				scanf("%d",&selecao_fav);
				}
				else{
					selecao_fav = selecao;
				}
				/*verifica se o ID escrito ? valido*/
				if(selecao_fav>0 && selecao_fav<=quant_fav){
					brecagem=0;
				}
			}
			char arquivo_favorito[200];
			/*ele vai atualizar a lista desejada*/
			sprintf(arquivo_favorito, "arquivos/favoritos/%s_lista_%d.txt", lista_usuario[indice_usuario][0],selecao_fav);
			arquivo = fopen(arquivo_favorito,"a+");
		
			char lista_favoritos[total][100];
			int indice_favoritos = 0;
			int possui =0;
			/*verifica se dentro da lista j? possui esse filme para nao ter duplicadas*/
			while (fgets(lista_favoritos[indice_favoritos], 100, arquivo) != NULL) {
			    if(strcmp(lista_favoritos[indice_favoritos],lista_filmes[indice_filme_favoritar])==0){
			    	possui=1;
				}
				indice_favoritos++;
			}
			/*se nao possui ele coloca o filme*/
			if(!possui){
				fprintf(arquivo, "%s", lista_filmes[indice_filme_favoritar]);
			}
				
			fclose(arquivo);
			printf("Esta na sua lista de favoritos..\n");
	}
}

/*FUNCAO EXCLUIR FILME DA LISTA*/
void excluir(int indice_usuario, int selecao){
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
	char lista_usuario[total_users][4][100];
	int indice = 0;
	while(!feof(arquivo)){ 
		fscanf(arquivo, "%s %s %s %s", lista_usuario[indice][0],lista_usuario[indice][1],lista_usuario[indice][2],lista_usuario[indice][3]); 
		indice = indice + 1; 
	}
	fclose(arquivo);
	
	/*PEGANDO O ARQUIVO DE FAVORITOS DO USUARIO*/
	char arquivo_favorito[100];
	sprintf(arquivo_favorito, "arquivos/favoritos/%s_lista_%d.txt", lista_usuario[indice_usuario][0],selecao);
	/*PRIMEIRO PEGANDO A QUANTIDADE TOTAL DE FILMES ARMAZENADAS*/
	arquivo = fopen(arquivo_favorito, "r");
	int total_filmes = 0;
	char linha_filmes[200];
	while (fgets(linha_filmes, sizeof(linha_filmes), arquivo) != NULL) {
		total_filmes++;
	}
	fclose(arquivo);
	/*PEGANDO TODOS OS FILMES*/
	arquivo = fopen(arquivo_favorito, "r");
	const int total = total_filmes;
	char lista_filmes[total][100];
	int indice_filme = 0;
	while (fgets(lista_filmes[indice_filme], 100, arquivo) != NULL) {
    	indice_filme++;
	}
	fclose(arquivo);
	/*REMOVENDO O /n PARA N?O ATRAPALHAR DEPOIS NA VISUALIZA??O*/		
	int remover_n =0;
	for(remover_n=0;remover_n<total;remover_n++){
	
		lista_filmes[remover_n][strcspn(lista_filmes[remover_n], "\n")] = '\0';	
	}
	int excluir;
	excluir=0;
	while(!excluir){
		/*AQUI O USUARIO DIGITA O ID DO FILME QUE SER? EXCLUIDO*/
		printf("Digite o ID do filme que sera excluido:\n");
		scanf("%d",&selecao_id);
		if(selecao_id>0 && selecao_id<=total){
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
	/*ATUALIZANDO O ARQUIVO COMPLETO*/
	arquivo = fopen(arquivo_favorito, "w");
	for(indice_comeco=0;indice_comeco<total-1;indice_comeco++){
		fprintf(arquivo,"%s\n",lista_filmes[indice_comeco]);
	}
	fclose(arquivo);
	printf("Excluido com sucesso..\n");
	system("pause");
	system("color03");
	
	
}



/*FUNCAO CURTIR OU DESCURTIR O FILME*/
void curtir(int indice_curtida_filme,int total,int curtir_dcurtir){
	/*PEGANDO O ARQUIVO DE CURTIDAS*/
	FILE *arquivo;
	arquivo = fopen("arquivos/curtidas_filme.txt", "r");
	/*para funcionamento do codigo ? necessario ter esse arquivo criado*/
	if(arquivo==NULL){
		printf("n?o ? possivel abrir esse documento");
		return;
	}
	char curtidas_filmes[total][100];
	int indice_filme = 0;

	while (fgets(curtidas_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	int curtida;
	/*AUMENTANDO OU DIMINUINDO O NUMERO DE CURTIDAS E VERIFICANDO SE CHEGOU NO LIMITE MINIMO E MAXIMO*/
	if(curtir_dcurtir==1){
		
	 	curtida= (atoi(curtidas_filmes[indice_curtida_filme]) - 1);
	 	if(curtida<0){
			 printf("N?o ? possivel descurtir esse filme");
			 curtida = curtida+1;
		 }
	}
	else{
		
		curtida = (atoi(curtidas_filmes[indice_curtida_filme]) + 1);
		if(curtida>900){
			 printf("N?o ? possivel curtir esse filme");
			 curtida = curtida-1;
		 }
	}
	
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
	/*COLOCANDO AS INFORMA??ES DOS FILMES EM ORDEM*/
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
void buscar(int indice_usuario,int selecao){
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

	/* LENDO LINHA COMPLETA */
	while (fgets(lista_filmes[indice_filme], 100, arquivo) != NULL) {
	    indice_filme++;
	}
	fclose(arquivo);
	/*COLOCANDO AS INFORMA??ES DOS FILMES EM ORDEM*/
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
	/*REMOVENDO OS \n */
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
		/*USUARIO S? IRA SAIR DO LOOP SE DIGITAR '0' */
		printf("Digite o id do filme:(para sair digite 0)\n");
		scanf("%d",&buscando);
		if(buscando==0){
			buscando_verifica = 1;
		}
		else if(buscando>0 && buscando<=total){
			while(!verifica_filme){
				system("cls");
				printf("|NOME: %-15s|\n",lista_filmes[buscando-1]);
				printf("|CURTIDAS: %-11s|\n",curtidas_filmes[buscando-1]);
				printf("INFO:\n %s\n",info_filmes[buscando-1]);
				printf("\n O que deseja fazer?\n\n");
				printf("/-/-/-/-/-/-/-/-/-/-/-/\n");
				printf("1. Continuar pesquisando\n");
				printf("2. Favoritar esse filme\n");
				printf("3. Curtir o filme\n");
				printf("4. Descurtir o filme\n");
				printf("/-/-/-/-/-/-/-/-/-/-/-/\n");
				if(selecao==0){
				scanf("%s",escolhendo_filmes);
				}
				else{
					strcpy(escolhendo_filmes, "2");
				}
				if(strcmp(escolhendo_filmes,"1")==0){
					verifica_filme=1;
					system("cls");
				}
				if(strcmp(escolhendo_filmes,"2")==0){
					/*VERIFICA SE O USUARIO JA TINHA SELECIONADO UMA LISTA ANTES*/
					if(selecao==0){
					
						favoritos(buscando-1,total,indice_usuario,0);
	
					}
					else{
						favoritos(buscando-1,total,indice_usuario,selecao);	
						verifica_filme=1;
					}
					
					verifica_filme=1;
					system("pause");
				}
				if(strcmp(escolhendo_filmes,"3")==0){
					curtir(buscando-1,total,0);
					printf("curtido..\n");
					verifica_filme=1;
					system("pause");
				}
				if(strcmp(escolhendo_filmes,"4")==0){
					curtir(buscando-1,total,1);
					printf("descurtido..\n");
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

/*FUNCAO DO MENU*/
void menu(int indice){
	/*MENU PRINCIPAL*/
	system("cls");
	system("color 06");
	char escolha[100];
	int voltar_menu;
	int sair = 0;
	char selecao[100];
	int verifica;
	while(!sair){
		system("cls");
		logo_menu();
		printf("\n");
		scanf("%s",escolha);
		if(strcmp(escolha,"1") == 0){
			/*CHAMANDO A FUN??O BUSCAR FILME*/
			buscar(indice,0);
		}
		if(strcmp(escolha,"2") ==0){
			voltar_menu=0;
			
			
			/*MENU DO GERENCIAMENTOS DOS FAVORITOS*/
			while(!voltar_menu){
				system("cls");
				verifica = verifica_favoritos_quant(indice);
				/*VERIFICA SE O USUARIO TEM UMA LISTA E SE QUER CRIAR UMA LISTA */
				if(verifica==0){
					system("cls");
					char x[3];
					
					printf("voce ainda nao possui uma lista\n");
					printf("deseja criar: 'sim' ou 'nao' \n");
					scanf("%s",&x);
					if(strcmp(x,"sim")==0){
						criar_favoritos(indice);
						voltar_menu =1;
					}
					else{
						printf("Digite uma op??o valida\n");	
					}	
				}
				if(verifica==1){
					criar_favoritos(indice);
				}
				
				if(verifica==2){
					remover_lista(indice);
				}
				if(verifica==3){
					/*ENTRANDO NA TELA DE EDI??O DE UMA LISTA*/
					int tela_selecao;
					tela_selecao = editar_lista(indice);
					if(tela_selecao>10){
						tela_selecao= tela_selecao-10;
						buscar(indice,tela_selecao);
						tela_selecao=0;
					}
					if(tela_selecao>0 && tela_selecao<=4){
							printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");
							printf("1. Adicionar um filme na lista de favoritos\n");
							printf("2. Tirar um filme da lista de favoritos\n");
							printf("3. Sair\n");
							printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");
							printf("\n\nO que deseja fazer?\n");
							scanf("%s",selecao);
							if(strcmp(selecao,"1")==0){
								buscar(indice,tela_selecao);
							}
							if(strcmp(selecao,"2")==0){
								excluir(indice,tela_selecao);
							}
							if(strcmp(selecao,"3")==0){
								tela_selecao=1;
							}	
						}
				}
				if(verifica==4){
					voltar_menu=1;
				}
				
				
			}
		}
		if(strcmp(escolha,"3") == 0){
			sair=1;
		}
	}
	
}

