#include "header.hpp"
using namespace std;

//
///////// Funções Recorrentes
//
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

void lerComando (char cmd[], char* par[]){
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
			par[j] = vet[j];
		}par[i] = NULL;
	}
}
/**/
void execComando (char* par[],char* const* path){
	int status;

	if(strcmp(par[0],"ls")==0){
		//LS Path
		status = execve("/bin/ls",par,path);
		assert(!status);
	}
	if(strcmp(par[0],"more")==0){
		//MORE Path
		status = execve("/bin/more",par,path);
		assert(!status);		
	}
	if(strcmp(par[0],"grep")==0){
		//GREP Path
		status = execve("/bin/grep",par,path);
		assert(!status);	
	}

	if(strcmp(par[0],"pwd")==0){
		//PWD Function
		cout << "PWD" << endl;	
	}else if(strcmp(par[0],"cd")==0){
		//CD Function
		cout << "CD" << endl;
	}
	
}
/**/

//
///////// Implementação dos Comandos
//

void cd (char*path){
	
}
void pwd (char*path){

}

//
///////// Main()
//

int main (void){
	setlocale(LC_ALL,"Portuguese");
	char  comando [INPUT_SIZE]; // Entrada do teclado
	char* parametros [PAR_SIZE]; // Argumentos/Parametros
	char* envp[] = {DEF_PATH,0}; // Linux Environment Path
	
	while (TRUE){

		mostraPrompt(); // Mostra o prompt na tela
		lerComando(comando, parametros); // Ler input do terminal

		if (fork()!=0){ // Fork off child proccess
		    	// Processo-pai
			cout << "FORK\n";
			wait(NULL); // Espera pela execução do pocesso-filho

		}else{
		    	// Processo-filho
			cout << "CHILD\n";			
	    			
				
			
			// checar Pipe
			// executar linha de comando
			
			execComando(parametros,envp);
						 
				
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
}// end main()
