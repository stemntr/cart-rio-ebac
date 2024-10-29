#include <stdio.h> //biblioteca de comunica��oo com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/strings
	
	printf("Digite o CPF: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se as strings (armazenando as string)
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria um novo arquivo. w � de whrite, para o cliente escrever a info
	fprintf(file,cpf); //salva o valor da vari�vel (valor = informa��o fornecida pelo cliente)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,", "); //abre o arqivo novamente para acrescentar uma virgula entre a informa��o anterior e a pr�xima
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome: "); //coletando informa��es do usu�rio
	scanf("%s",nome); // armazenando a informa��o na string
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,nome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file," "); // abre o arquivo e acrescenta um espa�o entre a informa��o anterior e a pr�xima
	fclose(file); // fecha o arquivp
	
	printf("Digite o sobrenome: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); // armazenando a informa��o na string
	
	file = fopen(arquivo, "a");  // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,", "); //abre o arqivo novamente para acrescentar uma virgula entre a informa��o anterior e a pr�xima
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo: "); // coletando informa��es do usu�rio
	scanf("%s",cargo); //armazenando a infoma��o na string
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //"congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu	
}

int consulta() //fun��o respons�vel pelas consultas dos usu�rios no sistema
{
	//inicio da cria��o de vari�veis
	char cpf[40]; 
	char conteudo[200];
	//fim da cria��o de vari�veis
	
	printf("Digite o CPF: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //armazenando as informa��es
	
	FILE *file; // //cria o arquivo
	file = fopen(cpf,"r"); //r de read, para o arquivo ler a info digitada
	
	if(file == NULL) //indica uma condi��o
	{
		printf("CPF n�o localizado\n"); //mensagem apresentada se a condi��o anterior ocoorer (no caso, digitar uma informa��o que n�o existe)
	}
	
	while(fgets(conteudo, 100, file) != NULL) //outra condi��o. Enquanto as informa��es digitadas existirem, siga a instru��o (que est� abaixo)
	{
		printf("\nEssas s�o as informa��es localizadas: "); //mensagem exibida para o cliente
		printf("%s", conteudo); // exibe os dados armazenados na string
		printf("\n\n"); //pula duas linhas
	}
	
	system("pause"); //"congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu
}

int deletar() //fun��o respons�vel por deletar as informa��es dadas pelos su�rios no sistema
{
	//inicio da cria��o de vari�veis
	char cpf[40];
	//fim da cria��o de vari�veis
	
	printf("Digite o CPF que deseja deletar: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); ////armazenando as informa��es
	
	remove(cpf); // fun��o j� existente que remove a vari�vel (no caso, a variavel CPF)
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e l�
	
	if(file == NULL) //indica uma condi��o
	{
		printf("Usu�rio n�o encontrado.\n"); //mensagem exibida ao cliente
		system("pause"); // "congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu
	}
}

int main() //fun��o base/principal
{
	int opcao=0; //define vari�vel
	int laco=1; //define vari�vel
	
	for(laco=1;laco=1;) //para repeti��o. O cliente vai voltar para o inicio do menu
	{
	
	system("cls"); //limpa a tela quando o cliente escolhe a op��o
	
		setlocale (LC_ALL, "portuguese"); //define a linguagem
		
		//inicio do menu
		printf("______- Cart�rio da Ebac -______\n\n");
		printf("Escolha a  op��o desejada do menu:\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Op��o  :");
		//fim do menu
	
		scanf("%d",&opcao); //armazena a escolha do usu�rio
	
		system("cls"); //limpa a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); // chama as a fun��o registro
			break; //pausa a chamada da fun��o
			
			case 2:
			consulta(); // chama a fun��o consulta
			break; // pausa a chamada da fun��o
			
			case 3:
			deletar(); //chama a fun��o deletar
			break; // pausa a chamada da fun��o
			
			case 4:
			printf("Obrigada por utilizar o sistema! Volte sempre!\n"); //mensagem exibida ao cliente
			return 0; // sair do sistema
			break; //pausa da fun��o
						
			default: //fun��o usada para indicar qualquer valor diferente dos cases acima
			printf("Essa op��o n�o est� dispon�vel.\n"); // mensagem exibida ao cliente
			system("pause"); //congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu
			break;	// pausa a chamada da fun��o
		}
	}
}
