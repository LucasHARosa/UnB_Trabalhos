 /* Lucas Henrique Alves Rosa (180042572)
  * Diciplina : APC
  * Trabalho : Trabalho 2, jogo "Don’t Break The Ice" */
 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 
 /* Delay para valor aleatório*/
 void delay(){
	 int i;
	 for(i=0;i<55000000;i++){
	 }
 }
 
 /* Imprimi o Mapa*/
 void imprimimapa(char lago[12][22]){
	     int i,j;
	      
         for(i=0;i<12;i++){
		     for(j=0;j<22;j++){
			     printf("%c",lago[i][j]);
		     }
		     printf("\n");
	     }
	     printf("\n\n\n");
 }
 
 /* Probabilidade de quebrar 1 ou 2 blocos*/
 int quebrarbloco(char jogador[30]){
	 int totaldeblocos;
	 int i = 0;
	 do{
	    printf("%s vai quebrar quantos blocos:",jogador);
	    scanf("%d",&totaldeblocos);
	    if(totaldeblocos == 2){
			srand(time(NULL));
            i = (1+ rand() % 100);
            if(i<80){
				totaldeblocos = 2;
			}
			else{
				totaldeblocos = 1;
			}
		}
		else if(totaldeblocos == 1){
			srand(time(NULL));
            i = (1+ rand() % 100);
            if(i<20){
				totaldeblocos = 2;
			}
			else{
				totaldeblocos = 1;
			}
		}
	 }while(i == 0);
	 return totaldeblocos;
 }
 
 /* Checagem se a coordenada x escolhida está permitida*/
 int coordenadax(){
	 int cordx = 0;
	 do{
	     printf ("Coordenada x:");
	     scanf("%d",&cordx);
	 }while(cordx < 1 || cordx > 20);
     return cordx; 
 } 
 
  /*Checagem se a coordenada y escolhida está permitida*/
 int coordenaday(){
	 int cordy = 0;
	 do{
	     printf ("Coordenada y:");
	     scanf("%d",&cordy);
	 }while(cordy < 1 || cordy > 10);
     return cordy; 
 } 
 
 /* Checagem se aang está ligado ao norte*/
 int checknorte(char lago[12][22],int x,int y){
	 char copialago[12][22];
	 int i,j;
	 int resultado = 0;
	 for(i=0;i<12;i++){
			 for(j=0;j<22;j++){
				 copialago[i][j] = lago [i][j];
			 }
		 }
	 for(i=1;i<11;i++){
		 for(j=1;j<21;j++){
			  if(copialago[i][j] == '#'){
				  if(copialago[i-1][j] == '-' || copialago[i-1][j] == 'V'|| copialago[i][j-1] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	  for(i=1;i<11;i++){
		 for(j=20;j>0;--j){
			  if(copialago[i][j] == '#' || copialago[i][j] == 'V' ){
				  if(copialago[i-1][j] == '-' || copialago[i-1][j] == 'V'|| copialago[i][j+1] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	  
	  if(copialago[x-1][y] == 'V' || copialago[x-1][y+1]== 'V' || copialago[x-1][y] == '-'||copialago[x+2][y] == 'V' || copialago[x+2][y+1]== 'V' || copialago[x][y+2] == 'V' || copialago[x+1][y+2]== 'V' || copialago[x][y-1] == 'V' || copialago[x+1][y-1] == 'V' ){
		  resultado = 0;
	  }
	  else{
		  resultado = 1;
	  }
	  return resultado;
  }
 
 /* Checagem se aang está ligado ao sul*/
 int checksul(char lago[12][22],int x,int y){
	 char copialago[12][22];
	 int i,j;
	 int resultado = 0;
	 ++x;
	 for(i=0;i<12;i++){
			 for(j=0;j<22;j++){
				 copialago[i][j] = lago [i][j];
			 }
		 }
	 for(i=10;i>0;i--){
		 for(j=1;j<21;j++){
			  if(copialago[i][j] == '#'){
				  if(copialago[i+1][j] == '-' || copialago[i+1][j] == 'V'|| copialago[i][j-1] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	  for(i=10;i>0;i--){
		 for(j=20;j>0;j--){
			  if(copialago[i][j] == '#'|| copialago[i][j] == 'V'){
				  if(copialago[i+1][j] == '-' || copialago[i+1][j] == 'V'|| copialago[i][j+1] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	  if(copialago[x-2][y] == 'V' || copialago[x-2][y+1]== 'V' ||copialago[x+1][y] == 'V' || copialago[x+1][y+1]== 'V' || copialago[x+1][y] == '-' || copialago[x][y+2] == 'V' || copialago[x-1][y+2]== 'V' || copialago[x][y-1] == 'V' || copialago[x-1][y-1] == 'V' ){
		  resultado = 0;
	  }
	  else{
		  resultado = 1;
	  }
	  return resultado;
  }
 
 /* Checagem se aang está ligado ao leste*/
 int checkleste(char lago[12][22],int x,int y){
	 char copialago[12][22];
	 int i,j;
	 int resultado = 0;
	 ++y;
	 for(i=0;i<12;i++){
			 for(j=0;j<22;j++){
				 copialago[i][j] = lago [i][j];
			 }
		 }
	 for(j=20;j>0;--j){
		 for(i=1;i<11;i++){
			  if(copialago[i][j] == '#'){
				  if(copialago[i][j+1] == '|' || copialago[i][j+1] == 'V' || copialago[i-1][j] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	  for(j=20;j>0;--j){
		 for(i=10;i>0;--i){
			  if(copialago[i][j] == '#' || copialago[i][j] == 'V'){
				  if(copialago[i][j+1] == '|' || copialago[i][j+1] == 'V' || copialago[i+1][j] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	  if(copialago[x-1][y] == 'V' || copialago[x-1][y-1]== 'V' || copialago[x+2][y] == 'V' || copialago[x+2][y-1]== 'V' || copialago[x][y+1] == 'V' || copialago[x+1][y+1]== 'V' || copialago[x][y+1] == '|' || copialago[x][y-2] == 'V' || copialago[x+1][y-2] == 'V' ){
		  resultado = 0;
	  }
	  else{
		  resultado = 1;
	  }
	  return resultado;
  }
  
  /* Checagem se aang está ligado ao oeste*/
 int checkoeste(char lago[12][22],int x,int y){
	 char copialago[12][22];
	 int i,j;
	 int resultado = 0;
	 for(i=0;i<12;i++){
			 for(j=0;j<22;j++){
				 copialago[i][j] = lago [i][j];
			 }
		 }
	 for(j=1;j<21;j++){
		 for(i=1;i<11;i++){
			  if(copialago[i][j] == '#'){
				  if(copialago[i][j-1] == '|' || copialago[i][j-1] == 'V'|| copialago[i-1][j] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	   for(j=1;j<21;j++){
		 for(i=10;i>0;--i){
			  if(copialago[i][j] == '#'|| copialago[i][j] == 'V'){
				  if(copialago[i][j-1] == '|' || copialago[i][j-1] == 'V'|| copialago[i+1][j] == 'V'){
					  copialago[i][j] = 'V';
				  }
			  }
		  }
	  }
	   if(copialago[x-1][y] == 'V' || copialago[x-1][y+1]== 'V' ||copialago[x+2][y] == 'V' || copialago[x+2][y+1]== 'V' || copialago[x][y+2] == 'V' || copialago[x+1][y+2]== 'V' || copialago[x][y-1] == 'V' || copialago[x+1][y-1] == 'V' || copialago[x][y-1] == '|'){
		  resultado = 0;
	  }
	  else{
		  resultado = 1;
	  }
	  return resultado;
  } 
  
  /* Quando o jogo acaba, contagem dos pontos*/
 int contagemdepontos(char lago[12][22]){
	  char copialago[12][22];
	  int pontos;
	  int i,j;
	  for(i=0;i<12;i++){
			 for(j=0;j<22;j++){
				 copialago[i][j] = lago [i][j];
			 }
		 }
	  for(i=0;i<12;i++){
		  for(j=0;j<22;j++){
			  if(copialago[i][j]== '#'){
				  pontos++;
			  }
		  }
	  }
	  return pontos;
  }
	  
	  
 int main(){
	 char jogador1[25];
	 char jogador2[25];
	 char lago[12][22];
	 /*variaveis auxiliares da matriz*/
	 int i,j;
	 int x,y;
	 /*pontos dos jogadores*/
	 int ponto1 = 0;
	 int ponto2 = 0;
	 /*variaveis auxiliares*/
	 int totaldeblocos =0;
	 int cordy,cordx;
	 int aux1=0;
	 int norte,sul,leste,oeste;
	 int n1 = 0,n2 = 0;
	 
	 /* "printf" específico para limpar a tela do usuário*/
	 printf("\33[H\33[2J");
	 printf("Bem vindo a: A LENDA DE AANG\n\n");
	 
	 printf("Jogador 1, seu nome de guerra: ");
	 /* Pegar o nome do jogador 1*/
	 do{
		 jogador1[n1] = getchar();
		 ++n1;
	 }while(jogador1[n1-1] != '\n');
	 jogador1[n1-1] = '\0';
	 
	 printf("Jogador 2, seu nome de guerra: ");
	 /* Pegar o nome do jogador 2*/
	 do{
		 jogador2[n2] = getchar();
		 ++n2;
	 }while(jogador2[n2-1] != '\n');
	 jogador2[n2-1] = '\0';
	 
	 /* Gera as bordas do mapa*/
	 for(j=0;j<22;j++){
     lago[0][j] = '-';
     lago[11][j] = '-';
     }
     for(i=0;i<12;i++){
     lago[i][0] = '|'; 
     lago[i][21] = '|';
     } 
     for(i=1;i<11;i++){
      	for(j=1;j<21;j++){
			lago[i][j] = '#';
		}
	 }
	 /* Gera aang no mapa aleatoriamente*/
	 srand(time(NULL));
     x = (1+ rand() % 9);
     delay();
     srand(time(NULL));
     y = (1 + rand() % 19);
     lago[x][y] = '@';
     lago[x][y+1]= '@';
     lago[x+1][y] = '@';
     lago[x+1][y+1] = '@';
     
     /*jogo*/
	do{
	     printf("\33[H\33[2J");
	     imprimimapa(lago);
		 norte = 0;
		 sul = 0;
		 leste = 0;
		 oeste = 0;
		 /*layout para a qunatidade de pontos*/
	     printf("%s: %d pontos            %s:%d pontos\n\n",jogador1,ponto1,jogador2,ponto2);
	     printf("\n");
	     totaldeblocos = quebrarbloco(jogador1);
	     /* Laço de repetição para validação da coordenada*/
	     do{
		    aux1 = 0;
	        cordx = coordenadax();
	        cordy = coordenaday();
	        if(lago[cordy][cordx] != ' ' && lago[cordy][cordx] != '@'){
	           if(totaldeblocos == 1){
			      lago[cordy][cordx] = ' ';
			      ++ponto1;
			      break;
		       }
		       if(totaldeblocos == 2){
			      if(lago[cordy+1][cordx] != ' '&& lago[cordy+1][cordx] != '@' && lago[cordy+1][cordx] != '-'){
				       lago[cordy][cordx] = ' ';
				       lago[cordy+1][cordx] = ' ';
				       ponto1 += 2;
				       break;
			      }
			      else if(lago[cordy-1][cordx] != ' '&& lago[cordy-1][cordx] != '@' && lago[cordy-1][cordx] != '-'){
	        	       lago[cordy][cordx] = ' ';
				       lago[cordy-1][cordx] = ' ';
				       ponto1 += 2;
				       break;
		          }
			      else if(lago[cordy][cordx+1] != ' ' && lago[cordy][cordx+1] != '@' && lago[cordy][cordx+1] != '|'){
				       lago[cordy][cordx] = ' ';
				       lago[cordy][cordx+1] = ' ';
				       ponto1 += 2;
				       break;
			      }
			      else if(lago[cordy][cordx-1] != ' ' && lago[cordy][cordx-1] != '@' && lago[cordy][cordx-1] != '|'){
				       lago[cordy][cordx] = ' ';
				       lago[cordy][cordx-1] = ' ';
				       ponto1 += 2;
				       break;
			      }
			      else if(lago[cordy][cordx] != ' ' && lago[cordy][cordx] != '@'){	
			           lago[cordy][cordx] = ' ';
			           ++ponto1;
			           break;
		          }
		       }
	        }
		    else{
			    aux1 = 1;
		    }
		 
	     }while(aux1 == 1);
	     
	 
		 /* Checagem se aang está ligado ao continente*/
	     norte = checknorte(lago,x,y);
	     sul = checksul(lago,x,y);
	     leste = checkleste(lago,x,y);
	     oeste = checkoeste(lago,x,y);
	     if((norte == 1 && leste == 1)||(norte == 1 && oeste==1)||(sul==1 && leste ==1)||(sul==1 && oeste==1)){ 
			  ponto2 += contagemdepontos(lago);
			  printf("\33[H\33[2J"); 	  
	          imprimimapa(lago);
	          printf("%s: %d pontos            %s: %d pontos\n",jogador1,ponto1,jogador2,ponto2);
	          if(ponto2 > ponto1){
				  printf("\n%s ganhou o jogo com mais pontos, Parabens\n",jogador2);
				  printf("Aperte ENTER para acabar o jogo\n");
				  getchar();
				  getchar();
				  break;
			  }
			  else{
				  printf("\n%s ganhou o jogo com mais pontos, Parabens\n",jogador1);
				  printf("Aperte ENTER para acabar o jogo\n");
				  getchar();
				  getchar();
				  break;
			  }
		  }
         printf("\33[H\33[2J"); 	  
	     imprimimapa(lago);
		 norte = 0;
		 sul = 0;
		 leste = 0;
		 oeste = 0;
		 /*layout para a qunatidade de pontos*/
	     printf("%s: %d pontos            %s: %d pontos\n\n\n",jogador1,ponto1,jogador2,ponto2);
	     totaldeblocos = quebrarbloco(jogador2);
	     /* Laço de repetição para validação da coordenada*/
	     do{
		    aux1 = 0;
	        cordx = coordenadax();
	        cordy = coordenaday();
	        if(lago[cordy][cordx] != ' ' && lago[cordy][cordx] != '@'){
	             if(totaldeblocos == 1){
			               lago[cordy][cordx] = ' ';
			               ++ponto2;
			               break;
		         }
		         if(totaldeblocos == 2){
			          if(lago[cordy+1][cordx] != ' '&& lago[cordy+1][cordx] != '@' && lago[cordy+1][cordx] != '-'){
				           lago[cordy][cordx] = ' ';
				           lago[cordy+1][cordx] = ' ';
				           ponto2 += 2;
				           break;
			          }
			          else if(lago[cordy-1][cordx] != ' '&& lago[cordy-1][cordx] != '@' && lago[cordy-1][cordx] != '-'){
	        	           lago[cordy][cordx] = ' ';
				           lago[cordy-1][cordx] = ' ';
				           ponto2 += 2;
				           break;
		              }
			          else if(lago[cordy][cordx+1] != ' ' && lago[cordy][cordx+1] != '@' && lago[cordy][cordx+1] != '|'){
				           lago[cordy][cordx] = ' ';
				           lago[cordy][cordx+1] = ' ';
				           ponto2 += 2;
				           break;
			          }
			          else if(lago[cordy][cordx-1] != ' ' && lago[cordy][cordx-1] != '@' && lago[cordy][cordx-1] != '|'){
				           lago[cordy][cordx] = ' ';
				           lago[cordy][cordx-1] = ' ';
				           ponto2 += 2;
				           break;
			          }
			          else if(lago[cordy][cordx] != ' ' && lago[cordy][cordx] != '@'){	
			               lago[cordy][cordx] = ' ';
			               ++ponto2;
			               break;
		              }
		          }
	         }
		     else{
			      aux1 = 1;
		     }
		 
	     }while(aux1 == 1);
	     
	     
	      /* Checagem se aang está ligado ao continente*/
	     norte = checknorte(lago,x,y);
	     sul = checksul(lago,x,y);
	     leste = checkleste(lago,x,y);
	     oeste = checkoeste(lago,x,y);
	     if((norte == 1 && leste == 1)||(norte == 1 && oeste==1)||(sul==1 && leste ==1)||(sul==1 && oeste==1)){ 
			  ponto1 += contagemdepontos(lago);
			  printf("\33[H\33[2J"); 	  
	          imprimimapa(lago);
	          printf("%s: %d pontos            %s: %d pontos\n",jogador1,ponto1,jogador2,ponto2);
	          if(ponto2 > ponto1){
				  printf("\n%s ganhou o jogo com mais pontos, Parabens\n",jogador2);
				  printf("Aperte ENTER para acabar o jogo\n");
				  getchar();
				  getchar();
				  break;
			  }
			  else{
				  printf("\n%s ganhou o jogo com mais pontos, Parabens\n",jogador1);
				  printf("Aperte ENTER para acabar o jogo\n");
				  getchar();
				  getchar();
				  break;
			  }
		  }
	 }while(ponto1 < 1000);
	 return 0;
 }
