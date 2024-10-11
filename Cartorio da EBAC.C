#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca para alocação de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavél por cuidar das strings

int registro() //funcao responsavel por cadastar os usuarios no sistema
{
	//inicio, criacao de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	//final, criacao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coleta a informacao do usuario
	scanf("%s", cpf);//%s refere-se a string, chamando ela //scanf armazena os dados no arquivo selecionado
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" e de escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo //o "a" significa atualizar o arquivo
	fprintf(file, ",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //exemplo de armazenar os dados no arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa o programa para fim de visualizacao
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //exclui o arquivo seleciondo
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //caso nao encontre o arquivo, solta a mensagem na tela
	{
		printf("O usuário não se encontra mais no sistema!. \n");
		system("pause");
	}
}

int main() //inicio do menu
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //loop do script
	{
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("  Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) //Melhor opção pra quando tem muitos IF`s
		{
			case 1:
				registro(); //chamada das funcoes
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			
			default: //caso usem a opcao nao existente /nao e uma funcao ja feita e sim da "switch"
				printf("Essa opção não está disponível\n\n");
				system("pause");
			break;
		}
	}
}
