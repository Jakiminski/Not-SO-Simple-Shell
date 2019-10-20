#include "header.hpp"
using namespace std;

void mostraPrompt(void){
	setlocale(LC_ALL,"Portuguese");
	static int flag = TRUE;
	// limpa-tela no terminal e mostra cabeçalho
	if (flag){ 
		system("clear");
		cout << INITIAL_MSG;
		flag = FALSE;
	}	
	// Indica qnd inserir novo comando estiver disponível
	cout << endl << PRMPT;

}

void lerComando(char cmd[], char* par[]){
	// "Retorna" comando + parametros, modificando os ponteiros

	char entrada [INPUT_SIZE];
	char* vet[100];
	char* str; // var auxiliar

	// Ler 1 linha
	int k = 0;
	while (k<INPUT_SIZE){
		entrada[k] = (char) fgetc(stdin);
		if (entrada[k] == '\n' || entrada[k] == EOF){
			break;
		}
		k++;
	}
	// Dividir em palavras
	if (k>1){
		str = strtok(entrada, STRTK_DLM);
		int i = 0;
		while (str!=NULL){
			vet[i] = strdup(str);
			i++;
			str = strtok(NULL,STRTK_DLM);
		}	
	
	
		// Identificar o comando (1a palavra)
		strcpy(cmd, vet[0]);
		// Identificar parametros, se houver
		for (int j=0; j<i; j++){
			par[j] = vet[j];
		}par[i] = NULL;
	}
}

int main(void){
	setlocale(LC_ALL,"Portuguese");
	char cmd [INPUT_SIZE], comando [INPUT_SIZE]; // Entrada do teclado
	char* parametros [PAR_SIZE]; // Argumentos/Parametros
	char* envpath[] = {DEF_PATH,NULL}; // $PATH Linux default
	int end = FALSE; // Flag para encerrar programa


	while (TRUE){

		mostraPrompt(); // Mostra o prompt na tela
		lerComando(comando, parametros); // Ler input do terminal
		/*
		for (int i=0;i<PAR_SIZE;i++){
			if (parametros[i]!=NULL) cout << "p[" << i << "]: '" << parametros[i] << "'." << endl;
			else break;
		}
		*/

		if (fork()!=0){ // Fork off child proccess
		    	// Processo-pai
			wait(NULL); // Espera pela execução do pocesso-filho

		}else{
		    	// Processo-filho			
			strcpy(cmd, "/bin/");
			strcat(cmd, comando);	    		
			execve(comando,parametros,envpath); //Executar comando;execve(comando,parametros,N);
			cout << cmd << endl;	 
			
		}// if-else
		if (strcmp(comando, "help") == 0 || strcmp(comando, "HELP") == 0){
				//HELP -> exibe todos os comandos
				cout << HELP_MSG;
		}
		if (strcmp(comando, "clear") == 0 || strcmp(comando, "CLEAR") == 0){
			//CLEAR -> limpa a tela
			system("clear");
		}
		if (strcmp(comando, "exit") == 0 || strcmp(comando, "EXIT") == 0){
			//EXIT -> Encerra o Shell
			break;
		}
    	}// end while()
	return EXIT_SUCCESS;
}// end main()
