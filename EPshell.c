#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAX_WORD 10
#define MAX_CHAR 512 // tamanho maximo de entrada de caracteres

void execucao(char* args[]){
    if(strcmp(args[0], "quit")==0 || args[0] == NULL) {
		exit(0);
	}

    pid_t pid = fork();

    if(pid == -1) {
        perror("Algo deu errado no fork...");
    }
    if(pid == 0) {
        if(execvp(args[0], args) == -1){
            perror("Erro na execução");
            exit(1);
        }
    }

    if(wait(0) == -1){
        perror("Erro no wait");
    }
}

void remove_endOfLine(char line[]) {
	int i=0;
	while(line[i] != '\n') // encontra a ultima posicao do que foi digitado
		i++;

	line[i] = '\0'; // coloca a ultima posição como NULL
}

int process_line(char line[]) {
	int i = 0;
	//args[i] = strtok(line," "); 
    char* args[MAX_WORD];
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
	execucao(args);
}

void read_line(char line[]) {
	char* username = getenv("USER"); // pega o username para printar
	printf("%s@EPshell> ", username);
	char* input = fgets(line, MAX_CHAR, stdin); //gets estava dando warning
	
	remove_endOfLine(line);

	
    if(strlen(input)>=512){
        printf("Ops... caracteres demais!");
        exit(0);
    }
    process_line(line);
}

int main () {
	char* args[MAX_WORD]; //comandos
	char line[MAX_CHAR]; //entrada do usuario

	while(1){
        read_line(line);
    }
	return 0;
}