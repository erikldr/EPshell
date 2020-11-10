#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAX_WORD 10
#define MAX_CHAR 512 // tamanho maximo de entrada de caracteres

void remove_endOfLine(char line[]) {
	int i=0;
	while(line[i] != '\n') // encontra a ultima posicao do que foi digitado
		i++;

	line[i] = '\0'; // coloca a ultima posição como NULL
}

void read_line(char line[]) {
	char* username = getenv("USER"); // pega o username para printar
	printf("%s@EPshell> ", username);
	char* input = fgets(line, MAX_CHAR, stdin); //gets estava dando warning
	
	remove_endOfLine(line);

	if(strcmp(line, "quit")==0 || input == NULL) {
		exit(0);
	}
    if(strlen(input)>=512){
        printf("Ops... caracteres demais!");
        exit(0);
    }
}

int process_line(char* args[], char line[]) {
	int i = 0;
	//args[i] = strtok(line," "); 
    char *token = strtok(line, ",");

    while(token != NULL){
        char *token2 = strtok(token, " ");

        while (token2 != NULL){
            args[i] = token2;
            i++;
            token2 = strtok(NULL, " ");    
        }
        args[i] = NULL;
        token = strtok(NULL, ",");
    }
	return 1;
}

int read_parse_line(char* args[], char line[]) {
	read_line(line);
	process_line(args, line);
	return 1;
}

int main () {
	char* args[MAX_WORD]; //comandos
	char line[MAX_CHAR]; //entrada do usuario

	while(read_parse_line(args,line)) {
		pid_t child_pid = fork();

		if(child_pid == 0) {
			execvp(args[0], args);
		}else {
			waitpid(child_pid, 0);
		}
	}
	return 0;
}