Técnicas de Programação I 2/2016
Prof. Rodrigo Bonifário

# MiniHaskell

Alunos:

1. Cristiano Cardoso 				15/0058349

2. João Pedro Silva Sousa			15/0038381

3. José Marcos da Silva Leite	15/0038810

4. Cristiano Krug Brust				15/0008058

Neste trabalho dividimos a equipe em duas. A primeira é formada pelos alunos de número 1 e 2 com o objetivo de desenvolver a solução do MiniHaskell proposta pelo professor. Enquanto que a segunda, decidiu refazer o interpretador em C++. 

Isto acontece porque a primeira equipe deseja compreender os pradrões de projeto e apefeiçoar seu conhecimento em ambiente Java. Enquanto que a segunda, tem objetivo de por em prática conhecimentos relacionados a _parsing_ e técnicas de testes unitários em C++.

## Versão Java
1. Configurando o ambiente: Importe o projeto a partir da subpasta _VersaoJava_ situada no diretório onde foi extraido o zip ou ou clonado do repostiório hospedado no GitHub. Exemplo:
O zip foi extraido em ~/Documents/MiniHaskell. Então deves ir em File > Import > Existing Projects into Workspace. Em Select Root Directory o seguinte endereço deve ser escrito: ~/Documents/MiniHaskell/VersaoJava.

2. Rodando os testes: Com o plugin JUnit 4 instalado, vá no icone de Run e selecione a opção TesteTodos.

3. Verificando cobertura de teste: Com o plugin EclEmma instalado, vá no icone de Coverage Test e selecione a opção TesteTodos.

## Versão C++
1. Compilando o executável mh: Abra o terminal na pasta raiz de onde foi extraido o zip. Execute o comando:

$ make MakeFile all

2. Executando o interpretador: $ ./mh

3. Verificando a bateria de testes: 
