# *Trabalho Prático I: Construindo um Interpretador Shell* 

> Project Status: Concluído :white_check_mark: 

> Repositório: [*EPShell*](https://github.com/erikldr/EPshell) :shipit:

**Alunos:** 

Erik Lucas da Rocha - 2732
        
Paulo Gabriel Pimenta Gomes - 3687

Foi desenvolvido um interpretador shell que faz a leitura de um ou mais comandos, separados por ", " e os executa. A execução do shell se finaliza com o leitura do comando "quit"

 :large_orange_diamond: Obs: A leitura de " , " (espaço vírgula espaço), como proposta no projeto não obeteve êxito, a leitura implementada é a de ", " (vírgula espaço).

### Como executar:
Junto ao arquivo do código fonte, existe um arquivo Makefile que tem a função de compilar o código.

**Tutorial:**

No terminal, entre no diretório do EPShell, digite "make" e em seguida ./epshell. O shell será executado.
Caso você já tenha executado o EPShell anteriormente, execute o comando "make clean" antes do comando "make".

**Explicação:**

Quando o comando make é executado, é criado um arquivo executável do EPShell.
Quando o comando make clean é executado, o arquivo executável anteriormente criado do EPShell é excluído.

### Casos de teste:
            user@EP-shell> ls
            user@EP-shell> ls -la -ll
            user@EP-shell> quit, poweroff
            
### Erros:
    Nenhum erro inesperado encontrado no código atual. Todos foram devidamente tratados ou corrigidos.
   
> Agradecemos por esse trabalho desafiador, proposto pelo professor Rodrigo Moreira na disciplina de Sistemas Operacionais, da UFV-CRP. 

> Agradecemos ao autor do site [BR-C - Wiki para programação em C](http://www.br-c.org/doku.php?id=start), Marcos Laureano! 
