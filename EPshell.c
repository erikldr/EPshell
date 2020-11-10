#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_WORD 100 
#define MAX_CHAR 512 // tamanho maximo de input de caracteres
#define clear() printf("\033[H\033[J") // para limpar a tela

void retira_espacos(char *input, char **comandos);
void execucao(char **comandos);
void inicializar();

void  retira_espacos(char *input, char **comandos){ // retira o excesso de espacos digitados 
     while (*input != '\0'){
          while ( *input == ' ')
               *input++ = '\0'; //adiciona NULL no lugar dos espacos
          *comandos++ = input;
          while (*input != '\0' && *input != ' ' && *input != '\n') 
               input++;
     }
     *comandos = '\0'; // adiciona NULL a ultima posicao da lista de comandos
}

void  execucao(char **comandos){
     pid_t pid;
     int status;
     
     if ((pid = fork()) < 0){ // cria um processo filho e verifica erro na criacao
          printf("Problema no fork.\n");
          exit(1);
     } else if (pid == 0){ // processo filho executa
          if (execvp(*comandos, comandos) < 0){
               printf("Nao conheco esse comando...\n");
               exit(1);
          }
     } else{ // processo pai espera a execucao do filho
          while (wait(&status) != pid);
     }
}

void inicializar(){
    char* username = getenv("USER"); // pega o username para printar

    printf("\e[36;1m"); //pinta a fonte de azul claro
	printf("%s@EPshell> ", username);
    printf("\e[0m");
}

int main () {
    char input[MAX_CHAR]; //512 caracteres
    char *comandos[MAX_WORD]; // 100 palavras
    char *token; 
    int tam_input = 0;

    clear(); // limpa a tela

    while(1){
        inicializar(); // imprime o nome de usuario seguido do nome do shell
        fgets(input, MAX_CHAR, stdin); //gets estava dando warning
        
        tam_input = strlen(input); //salva a posicao do \n

        if(tam_input > 0 && input[tam_input-1] == '\n')
            input[tam_input-1] = '\0'; //retira o \n da entrada
        fflush(stdin); //limpa buffer

        if(strlen(input)>512){ // so eh aceito strings de comandos menores que 512 caracteres no total
            printf("ERRO: entrada maior que a permitida!\n");
        }
        
        token = strtok(input,",");

        while (token != NULL) { 
            retira_espacos(token, comandos);

            if(!strcmp(comandos[0],"quit")) // sai quando quit eh digitado, independente da posicao do comando
                exit(0);

            execucao(comandos); //chama a funcao para execucao

            token = strtok(NULL, ","); 
        }
        printf("\n");
     }
}