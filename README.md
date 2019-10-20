# Not-SO-Simple-Shell
Projeto 1 de Sistemas Operacionais (SO1). Criando um Shell que aceita alguns comandos do UNIX.
Veja na íntegra o [contexto de implementação](./contexto.pdf) do referido programa.

## Máquina
Notebook Acer Aspire V3
Processador Intel Core i7-3632QM @2.2GHz x 8
8GBs RAM
500GB HD
Ubuntu 18.04.3 LTS 64 bits


## Compilação
:bowtie: 
Foi usado o compilador de C++ *g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0*. No seu terminal **Linux**, compile o programa usando o seguinte comando no diretório onde se encontra o código-fonte:```g++ main.cpp -o SimpleShell```.
Uma vez compilado, rode o arquivo executável com o nome ```SimpleShell``` ou equivalente na sua máquina.

## Licença
[GNU General Public License v3.0](/LICENSE)

## Issues
- O comando ```exit``` encerra processos normalmente, porém não encerrará o programa necessariamente. Durante os testes de execução do programa, foi relativamente incomum. Porém foram descobertas 2 causas para o problema: A primeira é o buffer de entrada não omitir espaços, tabs ou caracteres ocultos. A outra causa ocorre quando o programa estiver executando um processo-filho, pois ```exit``` encerrará apenas ele, mas não o processo-pai do processo encerrado. Ainda assim, persistir escrevendo o comando ```exit``` algumas poucas vezes será suficiente para matar todos os processos e encerrar o programa.
- Os comandos ```pwd``` e ```cd``` não foram implementados.
- O pipeline também não foi implementado.

## GitHub
:octocat: [Not-SO-Simple-Shell](https://github.com/Jakiminski/Not-SO-Simple-Shell/)
