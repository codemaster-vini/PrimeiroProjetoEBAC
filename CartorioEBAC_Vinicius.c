#include <stdio.h>  //Bibliotea que exibe texto ao usuário
#include <stdlib.h> //Biblioteca de alocação de espaço
#include <locale.h> //Biblioteca de alocação da localização do texto
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função para registrar os nomes
{
	char cpf[40];
	char nome[40];												
	char sobrenome[40]; //Definindo variáveis
	char cargo [40];											
	char arquivo[40];
	char resp; 
	
	printf ("Digite os dados a serem cadastrados:\n"); //Mensagem ao usuário
	printf ("------------------------------------\n");
	printf ("\tCPF: "); //Perguntando o CPF ao usuário
	scanf (" %s", cpf); //Lendo a resposta do usuário
	
	strcpy (arquivo, cpf); //Transferindo dados da variável CPF para ARQUIVO

	FILE *file; //Criação de pasta
	file = fopen (arquivo, "w"); //Criando arquivo
	fprintf (file, "CPF: "); //Escrevendo dentro do arquivo "CPF:"
	fclose (file); //Fechando arquivo

	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file,  cpf); //Transferindo dados da variável CPF para a pasta 
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, "\n"); //Pulando uma linha dentro da pasta
	fclose (file); //Fechando o arquivo
	
	printf ("\tNome: "); //Perguntando o nome ao usuário											
	scanf (" %s", nome); //Lendo a resposta do usuário

	file = fopen (arquivo, "a"); //Atualizando arquivo já criado								
	fprintf (file, "Nome: "); //Escrevendo dentro do arquivo "Nome:"
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, nome); //Colocando os dados da variavel NOME na pasta
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, "\n"); //Pulando uma linha dentro da pasta
	fclose (file); //Fechando o arquivo
	
	printf ("\tSobrenome: "); //Perguntando o SOBRENOME ao usuário
	scanf (" %s", sobrenome); //Lendo a resposta
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, "Sobrenome: "); //Escrevendo dentro do arquivo "Sobrenome:"
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, sobrenome); //Colocando os dados da variavel SOBRENOME na pasta
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, "\n"); //Pulando uma linha dentro da pasta
	fclose (file); //Fechando o arquivo
	
	printf ("\tCargo: "); //Perguntando o CARGO ao usuário
	scanf (" %s", cargo); //Lendo a resposta
	printf ("\n"); //Pulando uma linha
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, "Cargo: "); //Escrevendo dentro do arquivo "Cargo:"
	fclose (file); //Fechando o arquivo
	
	file = fopen (arquivo, "a"); //Atualizando arquivo já criado
	fprintf (file, cargo); //Colocando os dados da variavel CARGO na pasta
	fclose (file); //Fechando o arquivo
	
	system ("cls");
	
	printf ("O usuário foi adicionado com sucesso!\n");				        	    		
	printf ("--------------------------------------\n");	
	printf ("Deseja adicionar mais usuários? [S/N] "); //Perguntando se o usuário quer continuar
	scanf (" %c", &resp); //Lendo a resposta do usuário
	resp = toupper(resp); //Formatando a resposta para letra maiúscula
	
	if (resp == 'S') //Estrutura de condição caso "S"
	{
		system ("cls"); //LimpaTela
		registro(); //Retornar a função REGISTRO
	} //Fim da estrutura de condição caso "S"
	if (resp == 'N') //Estrutura de condição caso "N"													
	{																			
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela	
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim da condição caso "N"
	if (resp != 'S' && resp != 'N') //Estrutura de condição caso a resposta seja diferente de "S" e de "N"										
	{
		system ("cls"); //LimpaTela
		printf ("Comando não reconhecido!\n"); //Escrevendo na tela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim da condição caso resposta seja diferente de "S" e de "N"
	
} //Fim função REGISTRAR

int consulta() //Função para consultar os nomes registrados
{
	char cpf[40];																												
	char conteudo[200]; //Definindo variáveis
	char resp;																		
	
	setlocale (LC_ALL, "Portuguese"); //Alterando localização do texto
	
	printf ("Digite o CPF a ser consultado: "); //Perguntando CPF ao usuário
	scanf (" %s", cpf); //Lendo resposta e armazenando na variável CPF
	printf ("-------------------------------------\n");
	
	FILE *file; //Criando arquivo file
	file = fopen (cpf, "r"); //Abrindo arquivo e lendo os dados
	
	if (file == NULL) //Condição se os dados forem nulos
	{ //Início condição
		printf ("Não foi possivel localizar este CPF em nosso banco de dados \n\n"); //Escrevendo na tela do usuário
	} //Fim Condição
	
	while (fgets(conteudo, 200, file) != NULL) //Condição ENQUANTO Conteudos dentro da pasta for diferente de nulo escreva
	{ //Início condição												
		printf ("\t%s", conteudo); //Escrevendo conteudo dentro do arquivo
	} //Fim condição
	
	fclose (file); //Fechando o arquivo do banco de dados
	
	printf ("\n");
	printf ("-------------------------------------\n");
	printf ("Deseja consultar outro usuário? [S/N] "); //Perguntando ao usuário
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta do usuário para letra maiúcula
	
	if (resp == 'S') //Condição SE resposta = "S"
	{ //Início condição
		system ("cls"); //LimpaTela
		consulta(); //Retornar a função CONSULTA
	} //Fim condição
	
	if (resp == 'N') //Condição SE resposta = "N"																		
	{ //Início condição
		system ("cls"); //LimpaTela						
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usuário
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
	
	if (resp != 'S' && resp != 'N') //Condição SE resposta <> "S" e "N"
	{ //Início condição
		system ("cls"); //LimpaTela	
		printf ("Comando não reconhecido!\n"); //Escrevendo na tela do usuário
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usuário
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
	
} //Fim função CONSULTAR
		
int deletar() //Função para deletar os nomes registrados
{
	char cpf[40];																
	char resp; //Definindo variáveis
	char resp2;
	
	setlocale (LC_ALL, "Portuguese"); //Definindo região do texto
	
	printf ("Digite o CPF do usuário a ser deletado: "); //Perguntando CPF ao usuário
	scanf (" %s", cpf); //Lendo resposta e jogando na variáveç CPF
	printf ("-----------------------------------------\n");
	
	FILE *file; //Criando arquivo
	file = fopen (cpf, "r"); //Abrindo arquivo e pedindo para ler os dados
	
	fclose (file); //Fechando arquivo
	
	printf ("Tem certeza que deseja deletar este usuário? [S/N] "); //Perguntando ao usuário
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta para letra maiúscula
	
	system ("cls");
	
	if (resp == 'S') //Se resposta for igual a "S"
	{ //Início condição
		if (remove (cpf) == 0) //Se remover o cpf faça
		{ //Início condição
			printf ("Usuário (%s) deletado com secesso!\n", cpf); //Escrevendo na tela
		} //Fim condição
		else //Senão (condição)
		{ //Início condição
			printf ("Dados do usuário não encontrados\n"); //Escrevendo na tela
		} //Fim condição
	} //Fim condição
	
	else if (resp == 'N') //Senao se resposta for igual a "N"			
	{ //Início condição
		printf ("Usuário (%s) não foi deletado\n", cpf); //Escrevendo na tela
	} //Fim condição
	
	else //Senão (condição)
	{ //Início condição
		printf ("ERRO: Opção inválida!\n"); //Escrevendo na tela
	} //Fim condição
	
	printf ("----------------------------------\n");
	printf ("Deseja deletar outro usuário? [S/N] "); //Perguntando ao usuário
	scanf (" %c", &resp2); //Lendo resposta
	resp2 = toupper(resp2); //Formatando resposta para letra maiúscula
	
	if (resp2 == 'S') //Condição Se resp2 = "S"
	{ //Início condição
		system ("cls"); //LimpaTela
		deletar(); //Retornar função DELETAR
	} //Fim condição
	
	if (resp2 == 'N') //Condição Se = "N"
	{ //Início condição
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
	
	if (resp2 != 'S' && resp2 != 'N') //Se diferente de "S" e de "N"
	{ //Início condição
		system ("cls"); //LimpaTela
		printf ("Comando não reconhecido!\n"); //Escrevendo na tela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
	
} //Fim função DELETAR
	
int main() //Função principal de escolha de menu
{
	int opcao=0; //Definindo a variável do tipo inteiro
	int c=0; //Definindo variável contadora
	
		setlocale (LC_ALL, "Portuguese"); //Regiao do texto
		
		system ("cls"); //LimpaTela
	
		printf ("=================================\n");
		printf ("          CARTÓRIO EBAC          \n");     
		printf ("=================================\n");	
		printf ("Escolha a opção desejada do menu:\n\n"); //Início do menu		
		printf ("\t[1] Registrar nomes\n");                 
		printf ("\t[2] Consultar nomes\n");
		printf ("\t[3] Deletar nomes\n");
		printf ("\t[4] Sair\n");
		printf ("---------------------------------\n");
		
		printf ("Opção: "); //Escolha do usuário
		scanf (" %d", &opcao); //Retorno da escolha do usuário
	
		system ("cls"); //LimpaTela
		
		switch (opcao) //Estrutura de condição
		{
			case 1:
				registro(); //Retornar função "REGISTRO"
			break;	
			
			case 2:
				consulta(); //Retornar função "CONSULTA"									
			break;
		
			case 3:
				deletar(); //Retornar função "DELETAR"
			break;
			
			case 4:
				printf ("Encerrando o programa...\n\n");
			break;
		
			default:
				printf ("ERRO: Opção inválida!\n\n");
				system ("pause");
				main(); //Retorno da função PRINCIPAL
		} //Fim da condição SWITCH      
	
} //Fim função PRINCIPAL
