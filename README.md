# Not-SO-Simple-Shell
Projeto 1 de Sistemas Operacionais (SO1). Criando um Shell que aceita alguns comandos do UNIX.
Veja na íntegra o [contexto de implementação](./contexto.pdf) do referido programa.

## Máquina
- Notebook Acer Aspire V3
- Processador Intel Core i7-3632QM @2.2GHz x 8
- 8GBs RAM
- 500GB HD
- Ubuntu 18.04.3 LTS 64 bits


## Compilação
:bowtie: 
Foi usado o compilador de C++ *g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0*. No seu terminal **Linux**, compile o programa usando o seguinte comando no diretório onde se encontra o código-fonte:```g++ main.cpp -o SimpleShell```.
Uma vez compilado, rode o arquivo executável com o nome ```SimpleShell``` ou equivalente na sua máquina.

## Licença
[GNU General Public License v3.0](/LICENSE)

## Issues
- ```grep```,```more``` e ```ls``` nem sempre estão executando corretamente, não aceitando formatação ou argumentos com aspas; e a execução acompanhada do arg "--help" nesses comandos pode ocasionar estranheza. Não foi possível identificar causa(s), mas o path e os argumentos passados para execve() podem se modificar durante o programa, sem motivo aparente.
- O pipeline não foi implementado.

## GitHub
:octocat: [Not-SO-Simple-Shell](https://github.com/Jakiminski/Not-SO-Simple-Shell/)

## Sources

#### Sites
* [OPENGROUP.org - C Lib <unistd.h>](https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html)
* [IBM Knowledge Center](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/rtgtc.htm)
* [CPlusPlus.com](http://www.cplusplus.com/)

#### Livros
* Sistemas Operacionais Modernos - Tanenbaum - 4a Edição.

#### Vídeos
* [Linux/Mac Terminal Tutorial: The Grep Command - Search Files and Directories for Patterns of Text](https://www.youtube.com/watch?v=VGgTmxXp7xQ)
* [Writing a Simple Shell](https://www.youtube.com/watch?v=z4LEuxMGGs8)
* [C Tutorial | Write your own Shell](https://www.youtube.com/watch?v=QUCSyDFPbOI)
* [Grep Command - Practical Examples | Linux](https://www.youtube.com/watch?v=J6RWn7XJ23U)
* [C Programming in Linux Tutorial #026 - fork() Function](https://www.youtube.com/watch?v=tS-9zg3qfMY)
