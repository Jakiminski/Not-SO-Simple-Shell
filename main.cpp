#include "header.hpp"
using namespace std;


//
///////// Funções Recorrentes

void mostraPrompt (void){
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

void analisarComando (char cmd[], char* par[]){
	// "Retorna" comando + parametros, modificando os ponteiros
	char* entrada = new char [INPUT_SIZE];
	char* *vet = new char* [100];
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
		strcpy(cmd, *vet);
		// Identificar parametros, se houver
		for (int j=0; j<i; j++){
			par[j] = vet[j]; // Adiciona parametros da entrada
		}
		par[i-1] = NULL;// Apaga parametros não utilizados
		for (int j=i;j<PAR_SIZE;j++){
			par[j] = NULL;	
		}
	}

	delete[] entrada;
	delete[] *vet;
}

void execComando (char* args[],char* const* path){
	int status = 0; // Indica erros de execução no comando	

	if (strcmp(args[0], "ls")==0){
		//LS Path
		status = execve("/bin/ls", args, path);
		assert(!status);
	}
	if (strcmp(args[0], "more")==0){
		//MORE Path
		status = execve("/bin/more", args, path);
		assert(!status);		
	}
	if (strcmp(args[0], "grep")==0){
		//GREP Path
		status = execve("/bin/grep", args, path);
		assert(!status);	
	}

	if (strcmp(args[0],"pwd")==0){
		//PWD Function
		pwd(path);	
	}else if (strcmp(args[0], "cd")==0){
		//CD Function
		cd(path);
	}
	exit(status); // termina o processo filho
	
}


//
///////// Implementação dos Comandos

void cd (char*path){
	char* oldPath = new char [INPUT_SIZE];
	strcpy(oldPath,path);
	char* newPath = new char [INPUT_SIZE];
	if (*oldPath == '/'){
		chdir(oldPath); // Change Dir - Muda o diretório atual do terminal
	}else{
		newPath = getcwd(newPath, INPUT_SIZE); // Determina novo diretório
		newPath = strcat(strcat(newPath," /"),path); // add '/' ao começo do diretório, caso não tenha	
		chdir(newPath); // Change Dir - Muda o diretório atual do terminal	
	}
	delete[] oldPath;
	delete[] newPath;
}

void pwd (char*path){
	char* oldPath = new char [INPUT_SIZE];
	strcpy(oldPath,path);
	getcwd(oldPAth, INPUT_SIZE);
	delete[] oldPath;
}


//
///////// Main()

int main (void){
	setlocale(LC_ALL,"Portuguese");
	char  comando [INPUT_SIZE]; // Entrada do teclado
	char* parametros [PAR_SIZE]; // Argumentos/Parametros
	char* envp[] = {DEF_PATH, 0}; // Linux Environment Path
	
	while (TRUE){

		mostraPrompt(); // Mostra o prompt na tela
		analisarComando(comando, parametros); // Ler input do terminal/ parse(args)

		if (fork()!=0){ // Clonar processo-filho
		    	// Processo-pai
			wait(NULL); // Espera pela execução do processo-filho

		}else{
		    	// Processo-filho			
	    							
			// checar Pipe
			// executar linha de comando
			execComando(parametros+1,envp); // Executa o comando, dados os parametros e path
				
		}

		if (strcmp(comando, "help") == 0){
			//HELP -> exibe todos os comandos
			cout << HELP_MSG;
		}
		if (strcmp(comando, "clear") == 0){
			//CLEAR -> limpa a tela
			system("clear");
		}
		if (strcmp(comando, "exit") == 0){
			//EXIT -> Encerra o Shell
			break;
		}

    	}
	return EXIT_SUCCESS;
}
