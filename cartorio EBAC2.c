#include <stdio.h> //biblioteca de comunicaçãoo com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/strings
	
	printf("Digite o CPF: "); //coletando as informações do usuário
	scanf("%s", cpf); // %s refere-se as strings (armazenando as string)
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria um novo arquivo. w é de whrite, para o cliente escrever a info
	fprintf(file,cpf); //salva o valor da variável (valor = informação fornecida pelo cliente)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,", "); //abre o arqivo novamente para acrescentar uma virgula entre a informação anterior e a próxima
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome: "); //coletando informações do usuário
	scanf("%s",nome); // armazenando a informação na string
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,nome); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file," "); // abre o arquivo e acrescenta um espaço entre a informação anterior e a próxima
	fclose(file); // fecha o arquivp
	
	printf("Digite o sobrenome: "); //coletando informações do usuário
	scanf("%s",sobrenome); // armazenando a informação na string
	
	file = fopen(arquivo, "a");  // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,", "); //abre o arqivo novamente para acrescentar uma virgula entre a informação anterior e a próxima
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo: "); // coletando informações do usuário
	scanf("%s",cargo); //armazenando a infomação na string
	
	file = fopen(arquivo, "a"); // atualiza o mesmo arquivo com novas infos que o cliente vai digitar
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //"congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu	
}

int consulta() //função responsável pelas consultas dos usuários no sistema
{
	//inicio da criação de variáveis
	char cpf[40]; 
	char conteudo[200];
	//fim da criação de variáveis
	
	printf("Digite o CPF: "); //coletando informações do usuário
	scanf("%s",cpf); //armazenando as informações
	
	FILE *file; // //cria o arquivo
	file = fopen(cpf,"r"); //r de read, para o arquivo ler a info digitada
	
	if(file == NULL) //indica uma condição
	{
		printf("CPF não localizado\n"); //mensagem apresentada se a condição anterior ocoorer (no caso, digitar uma informação que não existe)
	}
	
	while(fgets(conteudo, 100, file) != NULL) //outra condição. Enquanto as informações digitadas existirem, siga a instrução (que está abaixo)
	{
		printf("\nEssas são as informações localizadas: "); //mensagem exibida para o cliente
		printf("%s", conteudo); // exibe os dados armazenados na string
		printf("\n\n"); //pula duas linhas
	}
	
	system("pause"); //"congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu
}

int deletar() //função responsável por deletar as informações dadas pelos suários no sistema
{
	//inicio da criação de variáveis
	char cpf[40];
	//fim da criação de variáveis
	
	printf("Digite o CPF que deseja deletar: "); //coletando informações do usuário
	scanf("%s", cpf); ////armazenando as informações
	
	remove(cpf); // função já existente que remove a variável (no caso, a variavel CPF)
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e lê
	
	if(file == NULL) //indica uma condição
	{
		printf("Usuário não encontrado.\n"); //mensagem exibida ao cliente
		system("pause"); // "congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu
	}
}

int main() //função base/principal
{
	int opcao=0; //define variável
	int laco=1; //define variável
	
	for(laco=1;laco=1;) //para repetição. O cliente vai voltar para o inicio do menu
	{
	
	system("cls"); //limpa a tela quando o cliente escolhe a opção
	
		setlocale (LC_ALL, "portuguese"); //define a linguagem
		
		//inicio do menu
		printf("______- Cartório da Ebac -______\n\n");
		printf("Escolha a  opção desejada do menu:\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Opção  :");
		//fim do menu
	
		scanf("%d",&opcao); //armazena a escolha do usuário
	
		system("cls"); //limpa a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); // chama as a função registro
			break; //pausa a chamada da função
			
			case 2:
			consulta(); // chama a função consulta
			break; // pausa a chamada da função
			
			case 3:
			deletar(); //chama a função deletar
			break; // pausa a chamada da função
			
			case 4:
			printf("Obrigada por utilizar o sistema! Volte sempre!\n"); //mensagem exibida ao cliente
			return 0; // sair do sistema
			break; //pausa da função
						
			default: //função usada para indicar qualquer valor diferente dos cases acima
			printf("Essa opção não está disponível.\n"); // mensagem exibida ao cliente
			system("pause"); //congela" a tela e o cliente precisa digitar uma tecla para finalizar e voltar ao menu
			break;	// pausa a chamada da função
		}
	}
}
