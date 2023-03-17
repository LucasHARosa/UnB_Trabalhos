/*
Aluno: Lucas Henrique Alves Rosa
Mtr: 180042572

3.1 Montador


Compile da seguinte forma:
//  g++ montador.cpp -o montador -Wall
    

Execute da seguinte forma (exemplo):
//  ./montador -r 1 myprogram1.asm
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi objeto;
int PC;
int contadordelinha;
int ord;


typedef struct{
    string nome;
    int valor = -1;
    int lista = 0;
    int linha = 0;
} Simbolo;

Simbolo tabela[200];
Simbolo ordem[200];





void insereObjeto(int opcode){
    objeto.push_back(opcode);
}

void InsereOrdem (string rotulo, string valor, int opcode){
    int aux = stoi(valor);
    if(opcode == 15){
        if(valor == "-1"){
            ordem[ord].nome = rotulo;
            ordem[ord].valor = 0;
            ordem[ord].lista = ord;
            ordem[ord].linha = contadordelinha;
        }
        else{
            ordem[ord].nome = rotulo;
            ordem[ord].valor = 0;
            ordem[ord].lista = ord;
            ordem[ord].linha = contadordelinha;
            for(int i=1;i<aux;i++){
                ord++;
                rotulo = rotulo+"+"+to_string(i);
                ordem[ord].nome = rotulo;
                ordem[ord].valor = 0;
                ordem[ord].lista = ord;
                ordem[ord].linha = contadordelinha ;
            }
        }
    }
    else if(opcode==16){
        ordem[ord].nome = rotulo;
        ordem[ord].valor = aux;
        ordem[ord].lista = ord;
        ordem[ord].linha = contadordelinha;
    }
    ord++;
}

void InsereTSLabel(string str,int linha){
    int i =0;
    while(tabela[i].linha != 0){
        if(tabela[i].nome == str){
            tabela[i].valor = linha;
            return;
        }
        i++;
    }
    tabela[i].nome = str;
    tabela[i].valor = linha;
    tabela[i].lista = -1;
    tabela[i].linha = contadordelinha;
}

void InsereTS(string str, int linha){
    int i =0;
    while(tabela[i].linha != 0){
        if(tabela[i].nome == str){
            if(tabela[i].valor != -1){
                insereObjeto(tabela[i].valor);
                return;
            }
            else{
                insereObjeto(tabela[i].lista);
                tabela[i].lista = linha;
                return;
            }
        }
        i++;
    }
    insereObjeto(-1);
    tabela[i].nome = str;
    tabela[i].lista = linha;
    tabela[i].linha = contadordelinha;
}



string maiuscula(string str){
    for(unsigned int i =0;i<str.size();i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

string comentario(string str){
    int coment=0;
    coment = str.find(";");
    if(coment != -1){
        str = str.substr(0,coment);
    }
    return str;
}

int IdentificadorDePalavra(string str){
    int coment=0;
    coment = str.find(" ");
    return coment;
}


string RetiraEspacos(string str){
    while(str.front()== ' '){
        str.erase(str.begin());
    }
    while(str.back()== ' '){
        str.pop_back();
    }
    return str;
}

int VerificaRotulo(string str){
    int rotulo=0;
    rotulo = str.find(":");
    return rotulo;
}

int VerificaCopy(string str){
    int virgula = 0;
    virgula = str.find(",");
    return virgula;
}



string ArrumaRotulo(string str){
    int erro=0;
    erro = str.find(":");
    if(erro != -1){
        str.erase(str.begin()+erro);
    }
    return str;
}

int caso(string str){
    int saida;
    if(str == "ADD"){
        saida = 1;
    }
    else if(str == "SUB"){
        saida = 2;
    }
    else if(str == "MUL"){
        saida = 3;
    }
    else if(str == "DIV"){
        saida = 4;
    }
    else if(str == "JMP"){
        saida = 5;
    }
    else if(str == "JMPN"){
        saida = 6;
    }
    else if(str == "JMPP"){
        saida = 7;
    }
    else if(str == "JMPZ"){
        saida = 8;
    }
    else if(str == "COPY"){
        saida = 9;
    }
    else if(str == "LOAD"){
        saida = 10;
    }
    else if(str == "STORE"){
        saida = 11;
    }
    else if(str == "INPUT"){
        saida = 12;
    }
    else if(str == "OUTPUT"){
        saida = 13;
    }
    else if(str == "STOP"){
        saida = 14;
    }
    else if(str == "SPACE"){
        saida = 15;
    }
    else if(str == "CONST"){
        saida = 16;
    }
    else{
        saida = 17;
    }
    return saida;
}


string Arrumalinha(string str){
    str = comentario(str);
    str = maiuscula(str);
    str = RetiraEspacos(str);
    return str;
}

void ArrumaTS(){
    int i = 1;
    int y;
    int parou;
    int position;
    int prox;
    while(ordem[i].linha != 0){
        parou = 0;
        y= 0;
        ordem[i].lista += PC-1;
        insereObjeto(ordem[i].valor);
        while(parou == 0){
            if(ordem[i].nome == tabela[y].nome){
                parou = 1;
            }
            else if(tabela[y].linha == 0){
                parou = 1;
            }
            else{
                y++;
            }
        }
        if(ordem[i].nome == tabela[y].nome){
            tabela[y].valor = ordem[i].lista;
            position = tabela[y].lista;
            while(position != -1){
                prox = objeto[position];
                objeto[position] = tabela[y].valor;
                position = prox;
            }
        }
        i++;
    }
    i=0;
}




int main(int argc, char *argv[]){
    std :: ios :: sync_with_stdio ( false );
    cin.tie ( NULL );

//--------------------------------------------------------
    ifstream arquivo;
    
    arquivo.open(argv[3]);
    ofstream saida;
    string info = argv[2];
    string txt = argv[3];
    string txt1;
    string linha; // variavel que será armazenada a linha
    string palavra; //palavras da linha serão armazenadas aqui
    string palavraaux; // um auxiliar para palavras, usado na instrução copy
    int posicao;   //armazena a posição de final de palavras

//--------------------------------------------------------
    PC = 0;
    int PC1 = 0;
    contadordelinha = 0;
    ord = 1;
    vector <int> mapadebits;
    vector <int> listaend;
    
    
//--------------------------------------------------------
    int section = 0; //Quando for 1 se trata da diretiva section, Quando 0 trata-se de uma linha de codigo
    int sectiondata = 0;
    int rotulo = 0; //Identifica rotulos
    int opcode; //identifica qual isntrução se refere a palavra
    int virgula; //identifica a posição da virgula nos operandos de copy
//--------------------------------------------------------
    if(!arquivo.is_open()){
        printf("Nao foi possivel abrir o arquivo!!\n");
    }
//--------------------------------------------------------
    /*
    Hierarquia de trabalho: 
    Ler linhas até o final do programa
    Apagar comentários das linhas e transformar strings minusculas em maiusculas
    Verificar se trata de um diretiva section
    Section TEXT:
        verificar quantidade de palavras dentro da linha
        verificar de a linha se inicia com a declaração de um rótulo
        Verificar a instrução da linha e se é valida
        De acordo com a instrução receber os operandos corretos
    Section DATA:
        Verificar se inicia com rotulo
        Verificar de a instrução é aceita
        Armazena a ordem da declaração das variaveis
    */
    while (getline(arquivo,linha)){
        if(linha.size()!=0){
            contadordelinha++;
            linha = Arrumalinha(linha);
            if(linha == "SECTION TEXT"){
                section = 1;
                sectiondata = 0;
            }
            else if(linha == "SECTION DATA"){
                section = 1;
                sectiondata = 1;
            }
            else{
                section = 0;
            }
            //ehsection = VerificaSection(linha);// 0 = section data; 1 = section text; -1 = não foi identificado section (erro diretiva) 
            if(section == 0){
                if(sectiondata == 0){
                
                /*
                Fluxo normal da SECTION TEXT
                Identifica se existe mais de uma palavra
                Identifica de a primeira palavra é uma linha
                Identifica a instrução e se é valida
                Identifica operando e quantidade de operandos
                */
                
                    posicao = 0;
                    while(posicao != -1){
                        posicao = IdentificadorDePalavra(linha);

                        /*
                        Caso que acontece quando tem uma única palavra em uma linha;
                        Ocorre quando um rotulo é declarado em uma linha sem instrução Ex: L_1:
                        Ocorre também quando existe um rotulo seguido de STOP Ex: L_1: STOP
                        Ocorre quando temos somente a instrução STOP, Ex: STOP
                        */

                        if(posicao == -1){
                            rotulo = VerificaRotulo(linha);
                            /*Se o rotulo for diferente de  -1 é porque existe rotulo*/
                            if(rotulo != -1){
                                linha = ArrumaRotulo(linha);
                                InsereTSLabel(linha,PC);        
                            }
                            //Não existe rotulo, portanto se trata de uma instrução com STOP
                            else{
                                opcode = caso(linha);
                                if(opcode == 14){
                                    insereObjeto(opcode);
                                    mapadebits.push_back(0);
                                    PC++;
                                }        
                            }
                        }
                        /*
                        Caso onde a linha se inicia com instrução ou label seguido de instrução
                        Pode ser rotulo + instrução + rotulo, Ex: L_1: JMP L_2
                        Pode ser Instrução + rotulo Ex: JMP L_2
                        */
                        else{
                            palavra = linha.substr(0,posicao);
                            linha = linha.substr(posicao);
                            palavra = Arrumalinha(palavra);
                            linha = Arrumalinha(linha);
                            rotulo = VerificaRotulo(palavra);

                            //caso onde não se inicia a linha com rotulo
                            if(rotulo == -1){
                                opcode = caso(palavra);
                                //instrução é um COPY, ou seja, recebe dois operandos separados por virgula
                                if(opcode == 9){
                                    insereObjeto(9);
                                    PC++;
                                    virgula = VerificaCopy(linha);
                                
                                    palavra = linha.substr(0,virgula);
                                    palavraaux = linha.substr(virgula+1);
                                    
                                    InsereTS(palavra,PC);
                                    listaend.push_back(PC);
                                    PC++;
                                    

                                    InsereTS(palavraaux,PC);
                                    listaend.push_back(PC);
                                    PC++;
                                    

                                    mapadebits.push_back(0);
                                    mapadebits.push_back(1);
                                    mapadebits.push_back(1);
                                }

                                //Demais instruções que recebem somente um operando
                                else if((opcode>0 && opcode<9) || (opcode>9 && opcode<14)){
                                    insereObjeto(opcode);
                                    PC++;
                                    palavra = linha;
                                    InsereTS(palavra,PC);
                                    listaend.push_back(PC);
                                    PC++;
                                    
                                    mapadebits.push_back(0);
                                    mapadebits.push_back(1);
                                }   
                            }
                            //Quando a linha se inicia na declaração de um rotulo
                            else{
                                palavra = ArrumaRotulo(palavra);
                                InsereTSLabel(palavra,PC); 
                            }
                        }
                    }
                /*
                Section DATA
                Fluxo normal da declaração de um section DATA, abaixo serão tratados os erros dessa seção
                Deve existir mais de uma palavra
                Identificação do Rotulo
                Identifica se existem mais palavras; 
                Armazena em um vetor na ordem que foram declaradas
                */
                }
                else if(sectiondata == 1){
                    mapadebits.push_back(0);
                    PC1++;
                    posicao = 0;
                    while(posicao != -1){
                        posicao = IdentificadorDePalavra(linha);
                        palavra = linha.substr(0,posicao);
                        linha = linha.substr(posicao);
                        palavra = Arrumalinha(palavra);
                        linha = Arrumalinha(linha);
                        //rotulo = VerificaRotulo(palavra);
                        //Se inicia com rotulo (caso normal)
                        palavra = ArrumaRotulo(palavra);
                        posicao = IdentificadorDePalavra(linha);
                        //Depois do rotulo existem somente duas palavras 
                        if(posicao != -1){
                            palavraaux = linha.substr(0,posicao);
                            linha = linha.substr(posicao);
                            palavraaux = Arrumalinha(palavraaux);
                            linha = Arrumalinha(linha);
                            opcode = caso(palavraaux); 
                            InsereOrdem(palavra,linha, opcode);
                            posicao = -1;
                        }
                        else{
                            opcode = caso(linha);
                            InsereOrdem(palavra,"-1", opcode);
                        }
                    }
                }
            } 
        }      
    }
    arquivo.close();
    
    ArrumaTS();
    
    PC =PC +PC1-1;
    txt.pop_back();
    txt.pop_back();
    txt.pop_back();
    txt.pop_back();
    txt1 = txt;
    txt = txt+".obj";
    saida.open(txt);

    txt1 = maiuscula(txt1);
    saida << "H: "<<txt1<<endl;
    saida << "H: "<<to_string(PC)<<endl;
    saida << "H: ";
    if(info == "1"){
        for(unsigned int x1 = 0;x1<listaend.size();x1++){
            saida<<listaend[x1]<<" ";
        }
        saida<<endl;
    }
    else{
        for(unsigned int x2 = 0;x2<mapadebits.size();x2++){
            saida<<mapadebits[x2];
        }
        saida<<endl;
    }
    saida << "T: ";
    for(unsigned int q = 0;q<objeto.size();q++){
        saida<<objeto[q]<<" ";
    }
    //cout<<endl;
    
    
    saida.close();
    
    //g++ montador2.cpp -o montador2 -Wall
    //./montador2 -r 1 myprogram.asm
    return 0;
}