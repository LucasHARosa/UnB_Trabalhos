/*
Aluno: Lucas Henrique Alves Rosa
Mtr: 180042572

3.2 Carregador
Nota: Tive que repetir o sistema de operações para cada um dos arquivos para evitar o conflito de parâmetros


Compile da seguinte forma:
//  g++ carregador.cpp -o carregador -Wall

Execute da seguinte forma (exemplo):
//  ./carregador myprogram1.obj myprogram2.obj 3 15 16 10 1000 2500 5000
*/

#include <bits/stdc++.h>
using namespace std; 

typedef struct{
    int PC;
    int opcode;
    int operando1;
    int operando2;
} Endereco;

typedef struct{
    int position = 0;
    vector <int> lines;
}TS;


typedef struct{
    string name;
    vector <int> indice_chunks;
}Info;

Info atual;
TS tabelasimbol[300];
Endereco line[300];
vector <int> tamanhochunk;
vector <int> enderecochunk;


string RetiraEspacos(string str){
    while(str.front()== ' '){
        str.erase(str.begin());
    }
    while(str.back()== ' '){
        str.pop_back();
    }
    return str;
}

string retiralabel(string str){
    int posicao;
    string saida;
    posicao = str.find(":");
    saida = str.substr(posicao+1);
    saida = RetiraEspacos(saida);
    return saida;
}

int DevolveEndereco(int end){
    int aux =0;
    int enderecofinal;
    int limite = tamanhochunk[atual.indice_chunks[aux]];
    while(end>limite){
        if(end > limite){
            end -= limite;
            aux++;
            limite = tamanhochunk[atual.indice_chunks[aux]];
        }
    }
    int inicial = enderecochunk[atual.indice_chunks[aux]];
    enderecofinal = inicial + end;
    return enderecofinal;
}



void preparaendereco(vector <int> end){
    //printf("entrei Aqui 3\n");
    int aux =0;
    int inicial = enderecochunk[atual.indice_chunks[aux]];
    int limite = tamanhochunk[atual.indice_chunks[aux]];
    unsigned int i = 0;
    int aux2= 0;
    int aux3;
    int position=0;
    while(end[i] != 14){
        if(aux2 > limite){
            aux++;
            aux2 = aux2 - limite -1;
            inicial = enderecochunk[atual.indice_chunks[aux]];
            limite = tamanhochunk[atual.indice_chunks[aux]];
        }
        if(end[i]==9){
            line[position].PC = aux2+inicial;
            aux2+=3;
            line[position].opcode = end[i];

            i++;
            aux3 = DevolveEndereco(end[i]);
            line[position].operando1 = aux3;
            
            i++;
            aux3 = DevolveEndereco(end[i]);
            line[position].operando2 = aux3;
            i++;
            position++;
        }
        else if(end[i]>0 && end[i]<14 && end[i]!=9 && end[i]!=5 && end[i]!=6 && end[i]!=7 && end[i]!=8 ){
            line[position].PC = aux2+inicial;
            aux2+=2;
            line[position].opcode = end[i];
            i++;
            aux3 = DevolveEndereco(end[i]);
            line[position].operando1 = aux3;
            i++;
            line[position].operando2 = -1;
            position++;
        }
        else if(end[i]==5 || end[i]==6 || end[i]==7 || end[i]==8 ){
            line[position].PC = aux2+inicial;
            aux2+=2;
            line[position].opcode = end[i];
            i++;
            aux3 = DevolveEndereco(end[i]);
            line[position].operando1 = aux3;
            i++;
            line[position].operando2 = -1;
            position++;
        }
        if(end[i]==14){
            //printf("entrei Aqui 4\n");
            line[position].PC = aux2+inicial;
            aux2++;
            line[position].opcode = end[i];
            line[position].operando1 = -1;
            line[position].operando2 = -1;
            position++;
        }
    }
    i++;
    while(i<end.size()){
        //printf("entrei Aqui 5\n");
        if(aux2 > limite){
            aux++;
            aux2 = aux2 -limite-1;
            inicial = enderecochunk[atual.indice_chunks[aux]];
            limite = tamanhochunk[atual.indice_chunks[aux]];
        }
        line[position].PC = aux2+inicial;
        aux2++;
        line[position].opcode = end[i];
        line[position].operando1 = -1;
        line[position].operando2 = -1;
        position++;
        i++;
    }
    line[position].opcode = -1;
}

int main(int argc, char *argv[]){
    std :: ios :: sync_with_stdio ( false );
    cin.tie ( NULL );

//--------------------------------------------------------
    
    string entrada;
    string aux1;
    string aux2;
    string aux3;
    int aux4;
    int leTudo = 0;
    int i=1;
    int naux1;
    int naux2;

//--------------------------------------------------------  
    int chunks;
    vector <string> nomearquivo;
    vector <int> lista;
    vector <int> lista2;
    vector <int> lista3;
    stringstream buffer;
    stringstream buffer2;
    stringstream buffer3;
//--------------------------------------------------------
    unsigned int indiceNA = 0;
    int indiceChunk = 0;
//--------------------------------------------------------
    string linha;
    string tamanho;
    string objeto;
    int tamanhoint;
    int ordemlinhas;
    
    vector <int> listaenderecochunk;
//--------------------------------------------------------
    while(leTudo == 0){
      
        entrada = argv[i];
        if(entrada.size()>1){
            nomearquivo.push_back(entrada);
        }
        else{
            chunks = stoi(entrada);
            for(int x = 1;x<=chunks;x++){
                aux1 = argv[i+x];
                aux2 = argv[i+x+chunks];
                naux1 = stoi(aux1);
                naux2 = stoi(aux2);
                tamanhochunk.push_back(naux1);
                enderecochunk.push_back(naux2);
            }
            leTudo = 1;
        }
        i++;
    }

    //Loop enquanto houver arquivos para carregar

    //abertura de arquivos de leitura e saida
    ifstream arquivo;
    ofstream saida;
    arquivo.open(nomearquivo[indiceNA]);
    if(!arquivo.is_open()){
        printf("Nao foi possivel abrir o arquivo!!\n");
    }
    //Nome do arquivo
    getline(arquivo,atual.name);
    atual.name = retiralabel(atual.name);
    //Tamanho do arquivo
    getline(arquivo,tamanho);
    tamanho = retiralabel(tamanho);
    tamanhoint = stoi(tamanho);
    if(indiceChunk>=chunks){
        indiceNA = 5;
        cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
    }
    else{
        //caso o tamanho do arquivo seja maior que o chunk
        if(tamanhoint > tamanhochunk[indiceChunk]){
            //printf("entrei aqui 1\n");
            while(tamanhoint > tamanhochunk[indiceChunk] && indiceNA < 3){
                if(indiceChunk>=chunks){
                    //caso não tenha mais chunks para alocar
                    indiceNA = 5;
                    cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
                }
                else if(indiceChunk == (chunks-1)){
                    indiceNA = 5;
                    cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
                }
                else{
                    //caso tenha mais chunks para alocar o projeto
                    //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                    tamanhoint -= tamanhochunk[indiceChunk];
                    atual.indice_chunks.push_back(indiceChunk);
                    listaenderecochunk.push_back(enderecochunk[indiceChunk]);
                    indiceChunk++;
                    //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                }
            }
        }
        if(tamanhoint <= tamanhochunk[indiceChunk]){
            //caso os tamanho do arquivo seja menor ou igual o tamanho do chunk
            atual.indice_chunks.push_back(indiceChunk);
            listaenderecochunk.push_back(enderecochunk[indiceChunk]);
            indiceChunk++;
        }
    }
    getline(arquivo,tamanho);

    //coloca os codigos em um array de inteiro chamado lista
    getline(arquivo,objeto);
    objeto = retiralabel(objeto);
    buffer<<objeto;
    while(buffer>>aux3){
        aux4 = stoi(aux3);
        lista.push_back(aux4);
    }
    arquivo.close();
    

    //foi possivel alocar e faz a impressão de onde foi alocado
    if(indiceNA != 5){
        saida.open(atual.name+".saida");
        if(listaenderecochunk.size()>1){
            cout<<atual.name<<" utilizando "<<listaenderecochunk.size()<<" CHUNKS. Enderecos iniciais: ";
            for(unsigned int y = 0;y<listaenderecochunk.size();y++){
                cout<<" " <<listaenderecochunk[y] <<" ";
            }
            cout<<endl;

        }
        else{
            cout<<atual.name<<" utilizando "<<listaenderecochunk.size()<<" CHUNK. Endereco inicial: "<<listaenderecochunk[0]<<endl;
        }
        //função que coloca o endereco nas linhas e arruma const e espace
        preparaendereco(lista);
        ordemlinhas = 0;
        while(line[ordemlinhas].opcode!=-1){
            saida << line[ordemlinhas].PC<< " "<< line[ordemlinhas].opcode;
            if(line[ordemlinhas].operando1 != -1){
                saida<< " "<<line[ordemlinhas].operando1;
                if(line[ordemlinhas].operando2 != -1){
                    saida<< " "<<line[ordemlinhas].operando2;
                }
            }
            saida<<endl;
            ordemlinhas++;
        }
        saida.close();
        
    }
    indiceNA++;
    
    atual.indice_chunks.clear();
    listaenderecochunk.clear();
    lista.clear();



    //-------------------------------------------
    if(indiceNA<nomearquivo.size()){
        ifstream arquivo2;
        ofstream saida2;
        arquivo2.open(nomearquivo[indiceNA]);
        if(!arquivo2.is_open()){
            printf("Nao foi possivel abrir o arquivo!!\n");
        }
        //Nome do arquivo
        getline(arquivo2,atual.name);
        atual.name = retiralabel(atual.name);
        //Tamanho do arquivo
        getline(arquivo2,tamanho);
        tamanho = retiralabel(tamanho);
        tamanhoint = stoi(tamanho);
        if(indiceChunk>=chunks){
            indiceNA = 5;
            cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
        }
        else{
            //caso o tamanho do arquivo seja maior que o chunk
            if(tamanhoint > tamanhochunk[indiceChunk]){
                while(tamanhoint > tamanhochunk[indiceChunk]  && indiceNA < 3){
                    if(indiceChunk>=chunks){
                        //caso não tenha mais chunks para alocar
                        indiceNA = 5;
                        cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
                    }
                    else if(indiceChunk == (chunks-1)){
                        indiceNA = 5;
                        cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
                    }
                    else{
                        //caso tenha mais chunks para alocar o projeto
                        //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                        tamanhoint -= tamanhochunk[indiceChunk];
                        atual.indice_chunks.push_back(indiceChunk);
                        listaenderecochunk.push_back(enderecochunk[indiceChunk]);
                        indiceChunk++;
                        //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                    }
                }
            }
            if(tamanhoint <= tamanhochunk[indiceChunk]){
                //caso os tamanho do arquivo seja menor ou igual o tamanho do chunk
                //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                atual.indice_chunks.push_back(indiceChunk);
                listaenderecochunk.push_back(enderecochunk[indiceChunk]);
                indiceChunk++;
            }
        }
       
        getline(arquivo2,tamanho);

        //coloca os codigos em um array de inteiro chamado lista
        getline(arquivo2,objeto);
        objeto = retiralabel(objeto);
        buffer2<<objeto;
        while(buffer2>>aux3){
            aux4 = stoi(aux3);
            lista2.push_back(aux4);
        }
        arquivo2.close();
        

        //foi possivel alocar e faz a impressão de onde foi alocado
        if(indiceNA != 5){
            saida2.open(atual.name+".saida");
            if(listaenderecochunk.size()>1){
                cout<<atual.name<<" utilizando "<<listaenderecochunk.size()<<" CHUNKS. Enderecos iniciais: ";
                for(unsigned int y = 0;y<listaenderecochunk.size();y++){
                    cout<<" " <<listaenderecochunk[y] <<" ";
                }
                cout<<endl;

            }
            else{
                cout<<atual.name<<" utilizando "<<listaenderecochunk.size()<<" CHUNK. Endereco inicial: "<<listaenderecochunk[0]<<endl;
            }
            //função que coloca o endereco nas linhas e arruma const e espace
            preparaendereco(lista2);
            ordemlinhas = 0;
            while(line[ordemlinhas].opcode!=-1){
                saida2 << line[ordemlinhas].PC<< " "<< line[ordemlinhas].opcode;
                if(line[ordemlinhas].operando1 != -1){
                    saida2<< " "<<line[ordemlinhas].operando1;
                    if(line[ordemlinhas].operando2 != -1){
                        saida2<< " "<<line[ordemlinhas].operando2;
                    }
                }
                saida2<<endl;
                ordemlinhas++;
            }
            saida2.close();
            
        }
        indiceNA++;
        atual.indice_chunks.clear();
        listaenderecochunk.clear();
        lista.clear();
    }



    

    //-------------------------------------------
    if(indiceNA<nomearquivo.size() ){
        ifstream arquivo3;
        ofstream saida3;
        arquivo3.open(nomearquivo[indiceNA]);
        if(!arquivo3.is_open()){
            printf("Nao foi possivel abrir o arquivo!!\n");
        }
        //Nome do arquivo
        getline(arquivo3,atual.name);
        atual.name = retiralabel(atual.name);
        //Tamanho do arquivo
        getline(arquivo3,tamanho);
        tamanho = retiralabel(tamanho);
        tamanhoint = stoi(tamanho);
        if(indiceChunk>=chunks){
            indiceNA = 5;
            cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
        }
        else{
        
            //caso o tamanho do arquivo seja maior que o chunk
            if(tamanhoint > tamanhochunk[indiceChunk]){
                while(tamanhoint > tamanhochunk[indiceChunk]  && indiceNA < 3){
                    if(indiceChunk>=chunks){
                        //caso não tenha mais chunks para alocar
                        indiceNA = 5;
                        cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
                    }
                    else if(indiceChunk == (chunks-1)){
                        indiceNA = 5;
                        cout<<atual.name<<" NAO FOI POSSIVEL ALOCAR"<<endl;
                    }
                    else{
                        //caso tenha mais chunks para alocar o projeto
                        //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                        tamanhoint -= tamanhochunk[indiceChunk];
                        atual.indice_chunks.push_back(indiceChunk);
                        listaenderecochunk.push_back(enderecochunk[indiceChunk]);
                        indiceChunk++;
                        //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                    }
                }
            }
            if(tamanhoint <= tamanhochunk[indiceChunk]){
                //caso os tamanho do arquivo seja menor ou igual o tamanho do chunk
                //printf("tamanho do arquivo %d, tamanho do chunk atual: %d\n",tamanhoint,tamanhochunk[indiceChunk]);
                atual.indice_chunks.push_back(indiceChunk);
                listaenderecochunk.push_back(enderecochunk[indiceChunk]);
                indiceChunk++;
            }
        }
       
        getline(arquivo3,tamanho);

        //coloca os codigos em um array de inteiro chamado lista
        getline(arquivo3,objeto);
        objeto = retiralabel(objeto);
        buffer3<<objeto;
        while(buffer3>>aux3){
            aux4 = stoi(aux3);
            lista3.push_back(aux4);
        }
        arquivo3.close();

        //foi possivel alocar e faz a impressão de onde foi alocado
        if(indiceNA != 5){
            saida3.open(atual.name+".saida");
            if(listaenderecochunk.size()>1){
                cout<<atual.name<<" utilizando "<<listaenderecochunk.size()<<" CHUNKS. Enderecos iniciais: ";
                for(unsigned int y = 0;y<listaenderecochunk.size();y++){
                    cout<<" " <<listaenderecochunk[y] <<" ";
                }
                cout<<endl;
            }
            else{
                cout<<atual.name<<" utilizando "<<listaenderecochunk.size()<<" CHUNK. Endereco inicial: "<<listaenderecochunk[0]<<endl;
            }
            //função que coloca o endereco nas linhas e arruma const e espace
            preparaendereco(lista3);
            ordemlinhas = 0;
            while(line[ordemlinhas].opcode!=-1){
                saida3 << line[ordemlinhas].PC<< " "<< line[ordemlinhas].opcode;
                if(line[ordemlinhas].operando1 != -1){
                    saida3<< " "<<line[ordemlinhas].operando1;
                    if(line[ordemlinhas].operando2 != -1){
                        saida3<< " "<<line[ordemlinhas].operando2;
                    }
                }
                saida3<<endl;
                ordemlinhas++;
            }
            saida3.close();
        }
    }
    return 0;
}