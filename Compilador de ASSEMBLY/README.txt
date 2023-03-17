Feito em windows 10 (VSCode)

Aluno: Lucas Henrique Alves Rosa
Mtr: 180042572

3.1 Montador
Nota 1: Montador não detecta erro. 

Compile da seguinte forma:
g++ montador.cpp -o montador -Wall
    

Execute da seguinte forma (exemplo):
./montador -r 1 myprogram.asm


3.2 Carregador
Nota 1: Tive que repetir o sistema de operações para cada um dos arquivos para evitar o conflito de parâmetros
Nota 2: Os arquivos de saída do montador (3.1) são os arquivos de entrada do Carregador.
De uma forma geral o formato da entrada do carregador é o aprensentado na especificação do trabalho

Compile da seguinte forma:
g++ carregador.cpp -o carregador -Wall

Execute da seguinte forma (exemplo):
./carregador myprogram1.obj myprogram2.obj 3 15 16 10 1000 2500 5000


Observações gerais:
No pasta (testes) estão arquivos que foram usados para os testes do algoritmo.