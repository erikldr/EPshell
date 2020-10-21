#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(){
char comando[10],*ptr;
int tp;

do{
  printf("EP-shell ----> ");
  gets(comando); //lê espaço ok
     // if()
    tp = strlen(comando); //tamanho ok
    printf("comando: %s\ntp: %d\n",comando,tp);
    if(comando==NULL){
      tp=0;
    }else if((tp<0)||(tp>10)){ //512
      printf("Tamanho de comando invalido\n");
    }


ptr = strstr(comando,"quit"); //strstr ponteiro p/ 1ª posição


//if((ptr[4]=='NULL')||(ptr[4]==""))
printf("strstr: %c conteudo: %c prox: %c\n",*ptr,ptr[3],ptr[4]);


}while((strcmp(comando,"quit")!=0)&&((ptr[4]=='NULL')||(ptr[4]!=' ')));
  //execvp();
//printf("Voce escolheu sair");
}

