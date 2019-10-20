#ifndef _MACROS_HPP_
#define _MACROS_HPP_

// BOOLEAN
	#ifdef TRUE
	#undef TRUE
	#endif
	#ifdef FALSE
	#undef FALSE
	#endif

	#ifndef TRUE
	#define TRUE 1
	#endif
	#ifndef FALSE
	#define FALSE 0
	#endif

// STRING TOKEN DELIMITERS
	#ifdef STRTK_DLM
	#undef STRTK_DLM
	#endif
	#ifndef STRTK_DLM
	#define STRTK_DLM (char*) "\t\n "  
	#endif


// DEF TERMINAL
	// Mensagem Inicial
	#ifdef INITIAL_MSG
	#undef INITIAL_MSG
	#endif
	#ifndef INITIAL_MSG
	#define INITIAL_MSG (char*) "Bem-vindo ao Simple Shell!\nEscreva \"help\" para comandos disponíveis.\n"  
	#endif
	
	// Mensagem Comandos Disponiveis
	#ifdef HELP_MSG
	#undef HELP_MSG
	#endif
	#ifndef HELP_MSG
	#define HELP_MSG (char*) "'pwd'\n'cd' <path>\n'ls'\n'more'<file>'grep' <string>\n'help'\n'clear'\n'exit'\n\n"  
	#endif

	// PATH padrão do Linux
	#ifdef DEF_PATH
	#undef DEF_PATH
	#endif
	#ifndef DEF_PATH
	#define DEF_PATH (char*) "PATH=/bin"  
	#endif

	// Show prompt
	#ifdef PRMPT
	#undef PRMPT
	#endif
	#ifndef PRMPT
	#define PRMPT (char*) ">\t" 
	#endif
	// Alternativas: ">\t"; "#\t" ou "$\t"

	// Size
	#ifdef INPUT_SIZE
	#undef INPUT_SIZE
	#endif
	#ifndef INPUT_SIZE
	#define INPUT_SIZE 1024
	#endif
	#ifdef PAR_SIZE
	#undef PAR_SIZE
	#endif
	#ifndef PAR_SIZE
	#define PAR_SIZE 16
	#endif

	
#endif
