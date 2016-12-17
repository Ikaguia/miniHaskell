Técnicas de Programação I 2/2016 Prof. Rodrigo Bonifário
#MiniHaskell

Alunos:

    Cristiano Cardoso 15/0058349

    João Pedro Silva Sousa 15/0038381

    José Marcos da Silva Leite 15/0038810

    Cristiano Krug Brust 15/0008058

Neste trabalho dividimos a equipe em duas. A primeira é formada pelos alunos de número 1 e 2 com o objetivo de desenvolver a solução do MiniHaskell proposta pelo professor, porém foi abandonada. Enquanto que a segunda, decidiu refazer o interpretador em C++.

Isto acontece porque a primeira equipe deseja compreender os pradrões de projeto e apefeiçoar seu conhecimento em ambiente Java. Enquanto que a segunda, tem objetivo de por em prática conhecimentos relacionados a parsing e técnicas de testes unitários em C++.

#Versão C++

1. Compilando o executável mh: 

a) Requisitos:
g++ (Ubuntu 4.9.4-2ubuntu1~14.04.1) 4.9.4
g++ (macOS com MacPorts ou Homebrew) 4.9.4 ~ Caso seu sistema for macOS/OSX
flex 2.5.35 ~ Utilize o comando "sudo apt-get install flex" em sistemas Debian para instala-lo.

b) Abra o terminal na pasta raiz de onde foi extraido o zip. Execute o comando:

$ make

c) Compilando o executável tmh

c1) Abra o terminal e execute:

$ make bltest

obs: Caso não seja possível realizar a compilação, os arquivos executáveis estão disponíveis na pasta /bin.



2. Executando o interpretador: $ ./mh

a) Para sair, entre com: > exit

b) Para limpar a tela: > clear


3. Utilizando o Ikaguia's MiniHaskell

a) A sintaxe completa está definida pelo arquivo "gramatica"

b) Por exemplo, na linha 14, definimos a soma como sendo sum(%s,%s), onde %s é uma expressão. Podemos usar no intepretador, por exemplo:

> sum(1,10)

11

b1) Podemos ver que o retorno é 11, como o esperado.

