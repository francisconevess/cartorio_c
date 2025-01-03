#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//fim cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usuario
	scanf("%s" , cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" , cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "%s", cargo);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" , cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, arquivo n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s" , conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int delete()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file ==  NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system ("pause");
	}
}

int main() 
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	int opcao=0; //definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;

	printf("\t Cart�rio\t\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls"); //responsavel por limpar a tela
		for(laco=1; laco=1;)
		{
			system("cls");
			setlocale(LC_ALL, "Portuguese"); //definindo linguagem
				
			printf("\t Cart�rio\t\n\n"); //inicio do menu
			printf("Por favor escolha a op��o desejada no menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");//fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
				
			switch(opcao) //inicio da sele��o
			{
				case 1:
				registro(); //chamada de fun��es
				break;
					
				case 2:
				consulta();
				break;
					
				case 3:
				delete();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				break;	
			} //fim da sele��o
		}
	}
	else 
		printf("Senha incorreta!");
}
