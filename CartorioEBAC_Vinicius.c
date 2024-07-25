#include <stdio.h>  //Bibliotea que exibe texto ao usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o
#include <locale.h> //Biblioteca de aloca��o da localiza��o do texto
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o para registrar os nomes
{
	char cpf[40];
	char nome[40];												
	char sobrenome[40]; //Definindo vari�veis
	char cargo [40];											
	char arquivo[40];
	char resp; 
	
	printf ("Digite os dados a serem cadastrados:\n"); //Mensagem ao usu�rio
	printf ("------------------------------------\n");
	printf ("\tCPF: "); //Perguntando o CPF ao usu�rio
	scanf (" %s", cpf); //Lendo a resposta do usu�rio
	
	strcpy (arquivo, cpf); //Transferindo dados da vari�vel CPF para ARQUIVO

	FILE *file; //Cria��o de pasta
	file = fopen (arquivo, "w"); //Criando arquivo
	fprintf (file, "CPF: "); //Escrevendo dentro do arquivo "CPF:"
	fclose (file); //Fechando arquivo

	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file,  cpf); //Transferindo dados da vari�vel CPF para a pasta 
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, "\n"); //Pulando uma linha dentro da pasta
	fclose (file); //Fechando o arquivo
	
	printf ("\tNome: "); //Perguntando o nome ao usu�rio											
	scanf (" %s", nome); //Lendo a resposta do usu�rio

	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado								
	fprintf (file, "Nome: "); //Escrevendo dentro do arquivo "Nome:"
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, nome); //Colocando os dados da variavel NOME na pasta
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, "\n"); //Pulando uma linha dentro da pasta
	fclose (file); //Fechando o arquivo
	
	printf ("\tSobrenome: "); //Perguntando o SOBRENOME ao usu�rio
	scanf (" %s", sobrenome); //Lendo a resposta
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, "Sobrenome: "); //Escrevendo dentro do arquivo "Sobrenome:"
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, sobrenome); //Colocando os dados da variavel SOBRENOME na pasta
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, "\n"); //Pulando uma linha dentro da pasta
	fclose (file); //Fechando o arquivo
	
	printf ("\tCargo: "); //Perguntando o CARGO ao usu�rio
	scanf (" %s", cargo); //Lendo a resposta
	printf ("\n"); //Pulando uma linha
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, "Cargo: "); //Escrevendo dentro do arquivo "Cargo:"
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo j� criado
	fprintf (file, cargo); //Colocando os dados da variavel CARGO na pasta
	fclose (file); //Fechando o arquivo
	
	system ("cls");
	
	printf ("O usu�rio foi adicionado com sucesso!\n");				        	    		
	printf ("--------------------------------------\n");	
	printf ("Deseja adicionar mais usu�rios? [S/N] "); //Perguntando se o usu�rio quer continuar
	scanf (" %c", &resp); //Lendo a resposta do usu�rio
	resp = toupper(resp); //Formatando a resposta para letra mai�scula
	
	if (resp == 'S') //Estrutura de condi��o caso "S"
	{
		system ("cls"); //LimpaTela
		registro(); //Retornar a fun��o REGISTRO
	} //Fim da estrutura de condi��o caso "S"
	if (resp == 'N') //Estrutura de condi��o caso "N"													
	{																			
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela	
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim da condi��o caso "N"
	if (resp != 'S' && resp != 'N') //Estrutura de condi��o caso a resposta seja diferente de "S" e de "N"										
	{
		system ("cls"); //LimpaTela
		printf ("Comando n�o reconhecido!\n"); //Escrevendo na tela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim da condi��o caso resposta seja diferente de "S" e de "N"
	
} //Fim fun��o REGISTRAR

int consulta() //Fun��o para consultar os nomes registrados
{
	char cpf[40];																												
	char conteudo[200]; //Definindo vari�veis
	char resp;																		
	
	setlocale (LC_ALL, "Portuguese"); //Alterando localiza��o do texto
	
	printf ("Digite o CPF a ser consultado: "); //Perguntando CPF ao usu�rio
	scanf (" %s", cpf); //Lendo resposta e armazenando na vari�vel CPF
	printf ("-------------------------------------\n");
	
	FILE *file; //Criando arquivo file
	file = fopen (cpf, "r"); //Abrindo arquivo e lendo os dados
	
	if (file == NULL) //Condi��o se os dados forem nulos
	{ //In�cio condi��o
		printf ("N�o foi possivel localizar este CPF em nosso banco de dados \n\n"); //Escrevendo na tela do usu�rio
	} //Fim Condi��o
	
	while (fgets(conteudo, 200, file) != NULL) //Condi��o ENQUANTO Conteudos dentro da pasta for diferente de nulo escreva
	{ //In�cio condi��o												
		printf ("\t%s", conteudo); //Escrevendo conteudo dentro do arquivo
	} //Fim condi��o
	
	fclose (file); //Fechando o arquivo do banco de dados
	
	printf ("\n");
	printf ("-------------------------------------\n");
	printf ("Deseja consultar outro usu�rio? [S/N] "); //Perguntando ao usu�rio
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta do usu�rio para letra mai�cula
	
	if (resp == 'S') //Condi��o SE resposta = "S"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		consulta(); //Retornar a fun��o CONSULTA
	} //Fim condi��o
	
	if (resp == 'N') //Condi��o SE resposta = "N"																		
	{ //In�cio condi��o
		system ("cls"); //LimpaTela						
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usu�rio
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
	
	if (resp != 'S' && resp != 'N') //Condi��o SE resposta <> "S" e "N"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela	
		printf ("Comando n�o reconhecido!\n"); //Escrevendo na tela do usu�rio
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usu�rio
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
	
} //Fim fun��o CONSULTAR
		
int deletar() //Fun��o para deletar os nomes registrados
{
	char cpf[40];																
	char resp; //Definindo vari�veis
	char resp2;
	
	setlocale (LC_ALL, "Portuguese"); //Definindo regi�o do texto
	
	printf ("Digite o CPF do usu�rio a ser deletado: "); //Perguntando CPF ao usu�rio
	scanf (" %s", cpf); //Lendo resposta e jogando na vari�ve� CPF
	printf ("-----------------------------------------\n");
	
	FILE *file; //Criando arquivo
	file = fopen (cpf, "r"); //Abrindo arquivo e pedindo para ler os dados
	
	fclose (file); //Fechando arquivo
	
	printf ("Tem certeza que deseja deletar este usu�rio? [S/N] "); //Perguntando ao usu�rio
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta para letra mai�scula
	
	system ("cls");
	
	if (resp == 'S') //Se resposta for igual a "S"
	{ //In�cio condi��o
		if (remove (cpf) == 0) //Se remover o cpf fa�a
		{ //In�cio condi��o
			printf ("Usu�rio (%s) deletado com secesso!\n", cpf); //Escrevendo na tela
		} //Fim condi��o
		else //Sen�o (condi��o)
		{ //In�cio condi��o
			printf ("Dados do usu�rio n�o encontrados\n"); //Escrevendo na tela
		} //Fim condi��o
	} //Fim condi��o
	
	else if (resp == 'N') //Senao se resposta for igual a "N"			
	{ //In�cio condi��o
		printf ("Usu�rio (%s) n�o foi deletado\n", cpf); //Escrevendo na tela
	} //Fim condi��o
	
	else //Sen�o (condi��o)
	{ //In�cio condi��o
		printf ("ERRO: Op��o inv�lida!\n"); //Escrevendo na tela
	} //Fim condi��o
	
	printf ("----------------------------------\n");
	printf ("Deseja deletar outro usu�rio? [S/N] "); //Perguntando ao usu�rio
	scanf (" %c", &resp2); //Lendo resposta
	resp2 = toupper(resp2); //Formatando resposta para letra mai�scula
	
	if (resp2 == 'S') //Condi��o Se resp2 = "S"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		deletar(); //Retornar fun��o DELETAR
	} //Fim condi��o
	
	if (resp2 == 'N') //Condi��o Se = "N"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
	
	if (resp2 != 'S' && resp2 != 'N') //Se diferente de "S" e de "N"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		printf ("Comando n�o reconhecido!\n"); //Escrevendo na tela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
	
} //Fim fun��o DELETAR
	
int main() //Fun��o principal de escolha de menu
{
	int opcao=0; //Definindo a vari�vel do tipo inteiro
	int c=0; //Definindo vari�vel contadora
	
		setlocale (LC_ALL, "Portuguese"); //Regiao do texto
		
		system ("cls"); //LimpaTela
	
		printf ("=================================\n");
		printf ("          CART�RIO EBAC          \n");     
		printf ("=================================\n");	
		printf ("Escolha a op��o desejada do menu:\n\n"); //In�cio do menu		
		printf ("\t[1] Registrar nomes\n");                 
		printf ("\t[2] Consultar nomes\n");
		printf ("\t[3] Deletar nomes\n");
		printf ("\t[4] Sair\n");
		printf ("---------------------------------\n");
		
		printf ("Op��o: "); //Escolha do usu�rio
		scanf (" %d", &opcao); //Retorno da escolha do usu�rio
	
		system ("cls"); //LimpaTela
		
		switch (opcao) //Estrutura de condi��o
		{
			case 1:
				registro(); //Retornar fun��o "REGISTRO"
			break;	
			
			case 2:
				consulta(); //Retornar fun��o "CONSULTA"									
			break;
		
			case 3:
				deletar(); //Retornar fun��o "DELETAR"
			break;
			
			case 4:
				printf ("Encerrando o programa...\n\n");
			break;
		
			default:
				printf ("ERRO: Op��o inv�lida!\n\n");
				system ("pause");
				main(); //Retorno da fun��o PRINCIPAL
		} //Fim da condi��o SWITCH      
	
} //Fim fun��o PRINCIPAL
