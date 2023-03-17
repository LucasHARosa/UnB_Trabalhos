/*     Trabalho: Jogo King of Tokyo
 *     Aluno: lucas henrique alves rosa (180042572)
 * disciplina: Algoritmos e Programação de Computadores*/



#include <stdio.h>
#include <stdlib.h>/*Biblioteca para a função rand*/
#include <time.h>/*Seed para a função rand*/
#include <string.h>/*Biblioteca para dar nome aos personagens*/


      void interface(int a, int b, int c,int d,int e,int f,int g, int h,char i[15], char j[15]){
	  printf("             %s    |    %s\n",i,j);
	  
      if (a<10 && b<10){
	      printf("          HP: 0%d/10    |    HP: 0%d/10\n",a,b);
      }
      else if ( a<10 && b ==10){
		  printf("          HP: 0%d/10    |    HP: %d/10\n",a,b);
	  }
	  else if (a==10&&b<10){
		  printf("          HP: %d/10    |    HP: 0%d/10\n",a,b);
	  }
	  else{
		  printf("          HP: %d/10    |    HP: %d/10\n",a,b);
	  }
	  
	  
	  
	  if (c<10 && d<10){
	       printf("          PV: 0%d/20    |    PV: 0%d/20\n",c,d);
	  }
	  else if ( c<10 && d >=10){
		   printf("          PV: 0%d/20    |    PV: %d/20\n",c,d);
	   }
	  else if (c>=10 && d<10){
		   printf("          PV: %d/20    |    PV: 0%d/20\n",c,d);
	   }
	  else{
		   printf("          PV: %d/20    |    PV: %d/20\n",c,d);
	   }
		  
		   
	     
	  if(e<10 && f<10){   
	       printf("          Poder: 0%d    |    Poder: 0%d\n",e,f);
	  }
	  else if ( e < 10 && f >=10){
		   printf("          Poder: 0%d    |    Poder: %d\n",e,f);
	  }
	  else if (e >= 10 && f < 10){
		   printf("          Poder: %d    |    Poder: 0%d\n",e,f);
	  }
	  else{
	       printf("          Poder: %d    |    Poder: %d\n",e,f);
	  }
	  
	  
	  if(g == 0 && h == 0){
		  printf("        Sem a Forca    |    Sem a Forca\n\n\n");
	  }
	  else if (g == 0 && h==1){
		  printf("        Sem a Forca    |    Com a Forca\n\n\n");
	  }
	  else if (g == 1 && h==0){
		  printf("        Com a Forca    |    Sem a Forca\n\n\n");
	  }
  }
       
       /*Função para gerar valores diferentes nos dados*/
      void delay(){
		 int i;
		 for (i=0; i<550000000; i++){
		 }
	 }

	  int dado1(){ 
		int num;
		 srand (time(NULL));
	     num = (1 + rand() % 6);/*funçẫo rand*/
	         
	         if(num == 1){
				 printf ("1 PV");
			 }
			 else if (num == 2){
				 printf("2 PV");
			 }
			 else if (num == 3){
				 printf("3 PV");
			 }
			 else if (num == 4){
				 printf ("Ataque");
			 }
			 else if(num == 5){
			     printf ("Cura");
			 }
			 else if (num == 6){
				 printf("Poder");
			 }  
			 delay();	
	     return num;
	 }     
	 
	 
	  int dado2(){ 
		int num;
		 srand (time(NULL));
	     num = (1 + rand() % 6);
	         
	         if(num == 1){
				 printf ("1 PV");
			 }
			 else if (num == 2){
				 printf("2 PV");
			 }
			 else if (num == 3){
				 printf("3 PV");
			 }
			 else if (num == 4){
				 printf ("Ataque");
			 }
			 else if(num == 5){
			     printf ("Cura");
			 }
			 else if (num == 6){
				 printf("Poder");
			 }  
			 delay();	
	     return num;
	 }     
	 
	 
	  int dado3(){ 
		int num;
		 srand (time(NULL));
	     num = (1 + rand() % 6);
	         
	         if (num == 1){
				 printf ("1 PV");
			 }
			 else if (num == 2){
				 printf("2 PV");
			 }
			 else if (num == 3){
				 printf("3 PV");
			 }
			 else if (num == 4){
				 printf ("Ataque");
			 }
			 else if (num == 5){
			     printf ("Cura");
			 }
			 else if (num == 6){
				 printf("Poder");
			 }  
			 delay();	
	     return num;
	 }     
	 
	 
	  int dado4(){ 
		int num;
		 srand (time(NULL));
	     num = (1 + rand() % 6);
	         
	         if(num == 1){
				 printf ("1 PV");
			 }
			 else if (num == 2){
				 printf("2 PV");
			 }
			 else if (num == 3){
				 printf("3 PV");
			 }
			 else if (num == 4){
				 printf ("Ataque");
			 }
			 else if(num == 5){
			     printf ("Cura");
			 }
			 else if (num == 6){
				 printf("Poder");
			 }  
			 delay();	
	     return num;
	 }     

      int modobatalha(char a[15],char b[15]){
 
                int i;
                int opcao;
                int i2;
                
                printf(" %s Atacou %s\n",b,a);
                printf("\n%s voce foi atacado(a) o que deseja fazer?\n 1 - Ceder a FORCA\n 2 - Continuar com a FORCA\n\n >> ",a);
                
                for(i = 0;i<1;){
			         
                     scanf("%d",&opcao);
                  
                         switch (opcao){
							 case 1:
							    i++;
							    i2 = 1;
							    printf(" \n %s assume o controle da FORCA\n",b);
							    break;
							 case 2:
							    i++;
							    i2 = 2;
							    printf("\n %s mantem o controle da FORCA\n",a);
							    break;
							 default:
							     printf("\n Escolha um valor valido >>");
							     break;
					     }	    
				}
				return i2;
			}
 
int main (){
	
	int i1=0,i2=0,i3,i4,i5,i6,i8,i9;/*variaveis auxiliares nas funções de loop*/
	int personagem, escolha;
	char jogador2[20];
	char jogador1[15];
	char s1[15] = "  Luke";
	char s2[15] = "  Yoda";
	char s3[15] = "  Leia";
	char s4[15] = " C-3PO";
	char s5[15] = " R2-D2";
	char s6[15] = "Anakin";
	char s7[15] = "Darth Vader";
	char s8[15] = "Boba Fett";
	char s9[15] = "Darth Maul";
	char s10[15] = "Conde Dookan";
	char s11[15] = "Kylo Ren";
	char s12[15] = "Jar Jar Binks";
	int tokyo1 = 0, tokyo2 = 0;
	int poder1 = 1,poder2 = 1;
	int hp1 = 10,hp2 = 10;
	int pv1 = 0, pv2 = 0;
	int d1, d2, d3 ,d4;
	
	printf("\33[H\33[2J");/*printf para "limpar" a tela*/
	
	                        /*Nome do jogo e personagens mudados para uma temática Star Wars*/
	printf("\n              VOCE ESTA JOGANDO KING OF IMPERIO GALACTICO!\n\n");
	printf(" Jogadores se alternam entre turnos com o objetivo de atingir 20 DE PV ou ZERAR A VIDA do oponente... \n");
	printf(" Com o objetivo de assumir o controle do IMPERIO GALACTICO e SALVAR ou DESTRUIR a GALAXIA!\n\n");
	printf(" Jogador 1 escolha um personagem para DEFENDER a Galaxia, que a forca esteja com voce!\n\n");
	printf("  1 - Luke\n");
    printf("  2 - Yoda\n");
    printf("  3 - Leia\n");
    printf("  4 - C-3PO\n");
    printf("  5 - R2-D2\n");
    printf("  6 - Anakin\n");
    printf("  0 - Sair\n");
    printf("\n >> ");
    
    
    
    
     while(i1 == 0){
		 
	  scanf("%d",&personagem);
		   
      switch(personagem){
		  
		case 0:
		exit(0);
		break;  
		   
		case 1:
		strcpy(jogador1, s1);
		printf("\n Jogador 1 escolheu %s\n\n",jogador1);
		i1++;
		break;
		
		case 2:
		strcpy(jogador1, s2);
		printf("\n Jogador 1 escolheu %s\n\n",jogador1);
		i1++;
		break;
		
		
		case 3:
		strcpy(jogador1, s3);
		printf("\n Jogador 1 escolheu %s\n\n",jogador1);
		i1++;
		break;
	
		
		case 4:
		strcpy(jogador1, s4);
		printf("\n Jogador 1 escolheu %s\n\n",jogador1);
		i1++;
		break;
		
		case 5:
		strcpy(jogador1, s5);
		printf("\n Jogador 1 escolheu %s\n\n",jogador1);
		i1++;
		break;
		
		case 6:
		strcpy(jogador1, s6);
		printf("\n Jogador 1 escolheu %s\n\n",jogador1);
		i1++;
		break;
		
		default:
		printf("\n Opcao invalida tente novamente:\n >>");
		break;
		
	  }
   }
   
    
    printf("------------------------------------------------------------------------\n\n");
    
    
    printf(" Jogador 2 escolha um personagem para DESTRUIR a Galaxia\n\n");
	printf("  1 - Darth Vader\n");
    printf("  2 - Boba Fett\n");
    printf("  3 - Darth Maul\n");
    printf("  4 - Conde Dookan\n");
    printf("  5 - Kylo Ren\n");
    printf("  6 - Jar Jar Binks\n");
    printf("  0 - Sair\n");
    printf("\n >> ");
    
    
     while ( i2 == 0){
		 scanf("%d",&personagem);
      switch(personagem){
		  
		case 0:
		exit(0);
		break;  
		  
		case 1:
		strcpy(jogador2, s7);
		printf("\n Jogador 2 escolheu %s\n\n",jogador2);
		i2++;
		break;
		
		case 2:
		strcpy(jogador2, s8);
		printf("\n Jogador 2 escolheu %s\n\n",jogador2);
		i2++;
		break;
		
		
		case 3:
		strcpy(jogador2, s9);
		printf("\n Jogador 2 escolheu %s\n\n",jogador2);
		i2++;
		break;
	
		
		case 4:
		strcpy(jogador2, s10);
		printf("\n Jogador 2 escolheu %s\n\n",jogador2);
		i2++;
		break;
		
		case 5:
		strcpy(jogador2, s11);
		printf("\n Jogador 2 escolheu %s\n\n",jogador2);
		i2++;
		break;
		
		case 6:
		strcpy(jogador2, s12);
		printf("\n Jogador 2 escolheu %s\n\n",jogador2);
		i2++;
		break;
		
	
		
		default:
		printf("\nOpcao invalida tente novamente:\n >>");
		break;
		
	  }
  } 
  
     printf(" Pressione 'Enter' pra continuar...\n");
     getchar();
     getchar();
     
     
  do{
	  
	 do{ 
     printf("\33[H\33[2J");
     interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
     printf (" Turno do JOGADOR 1:\n Dados sendo jogados...\n\n ");
     
	 printf (" \n Primeiro dado: ");
	 d1 = dado1();
	 printf(" \n Segundo dado: ");
	 d2 = dado2();
	 printf(" \n Terceiro dado: ");			
	 d3 = dado3();
	 printf(" \n Quarto dado: ");
	 d4 = dado4();
	 	
	 i4 = 0;
	 i8 = 0;
	 printf("\n\n 1 - Atacar\n 2 - Curar-se\n 3 - +Poder\n 4 - +PV\n");
	     if(tokyo1 == 1){ 
			if((d1!=4 && d1!=6)&&(d2!=4 && d2!=6)&&(d3!=4 && d3!=6)&&(d4!=4 && d4!=6)){
				printf(" 5 - Pular a vez\n");
				i8 = 1;
			}
		}
	 
	 printf("\n %s, o que voce deseja fazer? >> ",jogador1);
	 
	 
	if(tokyo1 == 0 && tokyo2 == 0){
		 if(d1 == 4 || d2 == 4 || d3 == 4 || d4 == 4){ 
			 tokyo1 = 1;
			 pv1++;
		 }
	 }
	 
	for(i3 = 0;i3 < 1; ){ 
		
	scanf("%d",&escolha);
	  
	switch(escolha){
		 case 1:
		       if(d1 == 4 || d2 == 4 || d3 == 4 || d4 == 4){ 
		          if(tokyo1 == 1){
				     hp2 = hp2 - poder1;
				     printf(" %s Atacou %s",jogador1,jogador2);
				     i3++;
				     break;
			      }
		           else if(tokyo1 == 0 && tokyo2 == 1){
				        hp2 = hp2 - poder1;
				        printf("\33[H\33[2J");
                        interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
                        i5 = modobatalha(jogador2, jogador1);
                        
                        
                        switch (i5){
							case 1:
							     tokyo2 = 0;
					             tokyo1 = 1;
					             pv1++;
					             i3++;
					             break;
					        case 2:
					             i3 ++;
					             break;
				        }
                        break;  
		          } 
		      }
	          else{
		          printf("\n Opcao invalida\n Escolha outra opcao >> ");
			      break;
		          } 
		 
		 case 2: 
		   if(d1 == 5 || d2 == 5 || d3 == 5 || d4 == 5){ 
			  if(tokyo1==0){
					if(hp1 <= 7){
						hp1 += 3;
						printf(" %s ganhou 3 de HP\n",jogador1);
						i3++;
						break;
					}
					if(hp1 == 8){
						hp1 += 2;
						printf(" %s ganhou 2 de HP\n",jogador1);
						i3++;
						break;
					}
					if(hp1 == 9){
						hp1 +=1;
						printf(" %s ganhou 1 de HP\n",jogador1);
						i3++;
						break;
					}
					if(hp1 == 10){
						printf(" seu HP esta cheio, nada acontece\n");
						i3++;
						break;
					}
				}
			    else if(d1 == 5 && d2 == 5 && d3 == 5 && d4 == 5){
					printf(" Os dados vao ser rolados novamente\n\n ");
					i3++;
					i4++;
					break;
				}
			    else{
				    printf("\n Nao pode se curar com a FORCA\n\n\n Escolha outra opcao >> ");
				    break;
				    }
		 }
			    else{
				     printf("\n Opcao invalida\n Escolha outra opcao >> ");
				     break;
			    }
					 
		 
		 
		 
		 case 3:
		   if(d1 == 6 || d2 == 6 || d3 == 6 || d4 == 6){
			   poder1++;  
			   printf(" %s ganhou 1 de Poder\n",jogador1);
			   i3++;
			   break;
		   }
		   else{
			   printf("\n Opcao invalida\n Escolha outra opcao >> ");  
		       break;
		   }
		 
		 case 4:
		     if (d1 == 3 || d2 == 3 || d3 == 3 || d4 == 3){
				 if((d2==3 && d1==3) || (d1==3 && d3==3) || (d1==3&&d4==3) || (d2==3 && d3==3) || (d2==3 && d4==3) || (d3==3 && d4==3)){
					 pv1 += 3;
					 printf("\n %s ganhou 3 de PV\n",jogador1);
					 i3++;
					 break;
				 }
			 }
			 if (d1 == 2 || d2 == 2 || d3 == 2 || d4 == 2){
				 if((d2==2 && d1==2) || (d1==2 && d3==2) || (d1==2&&d4==2) || (d2==2 && d3==2) || (d2==2 && d4==2) || (d3==2 && d4==2)){
					 pv1 += 2;
					 printf("\n %s ganhou 2 de PV\n",jogador1);
					 i3++;
					 break;
				 }
			 }
			 if (d1 == 1 || d2 == 1 || d3 == 1 || d4 == 1){
				 if(d1==d2 || d1==d3 || d1==d4 || d2 ==d3 || d2==d4 || d3==d4){
					 pv1 += 1;
					 printf("\n %s ganhou 1 de PV\n",jogador1);
					 i3++;
					 break;
				 }
			 }
			 else{
				printf("\n Opcao invalida\n Escolha outra opcao >> ");
				break;
			  }
			  
	   if(i8 == 1){ 
		 case 5:
		 	 i3++;
		 	 break;
		 }	  
			  
		 
		 default:
		      printf("\n Opcao invalida\n Digite um valor valido >> ");
		      break;
		 
	}
    }
    }while(i4 == 1);
    
         if(tokyo1 == 1){
			 pv1 += 2;
		 }
		  if(hp2 < 1 || pv1 > 19){
			  printf("\33[H\33[2J");
              interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
			  printf("\n\n  %s Assumiu o controle do IMPERIO e SALVOU a galaxia!\n\n",jogador1);
			  printf("\n\n Pressione 'Enter' pra acabar o jogo...\n");
			  getchar();
			  getchar();
			  break;
		  } 
		  if(hp1 < 1 || pv2 > 19){
			  printf("\33[H\33[2J");
              interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
			  printf("\n\n %s Assumiu o controle do IMPERIO e DESTRUIU a galaxia!\n\n",jogador2);
			  printf("\n\n Pressione 'Enter' pra acabar o jogo...\n");
		      getchar();
		      getchar();
		      break;
		  }
		 
    
         printf("\n\n Pressione 'Enter' pra ir pro proximo turno...\n");
		 getchar();
		 getchar();
		 
		 
  do{ 
        printf("\33[H\33[2J");
        interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
        printf (" Turno do JOGADOR 2:\n Dados sendo jogados...\n\n "); 
        
      
	    printf (" \n Primeiro dado: ");
	    d1 = dado1();
	    printf(" \n Segundo dado: ");
	    d2 = dado2();
	    printf(" \n Terceiro dado: ");			
	    d3 = dado3();
	    printf(" \n Quarto dado: ");
	    d4 = dado4();
	    
        
	    
	    
	    
	    i4 = 0;
	    i9 = 0;
	    printf(" \n\n 1 - Atacar\n 2 - Curar-se\n 3 - +Poder\n 4 - +PV\n");
	    if(tokyo2 == 1){ 
			if((d1!=4 && d1!=6)&&(d2!=4 && d2!=6)&&(d3!=4 && d3!=6)&&(d4!=4 && d4!=6)){
				printf(" 5 - Pular a vez\n");
				i9 = 1;
			}
		}
				
	    
	    printf("\n %s, o que voce deseja fazer? >> ",jogador2);
	 
	 
	    if(tokyo1 == 0 && tokyo2 == 0){
		     if(d1 == 4 || d2 == 4 || d3 == 4 || d4 == 4){ 
			 tokyo2 = 1;
			 pv2++;
		     }
	    }
	 
	    for(i3 = 0;i3 < 1; ){ 
		
	    scanf("%d",&escolha);
	 
	    switch(escolha){
		     case 1:
		          if(d1 == 4 || d2 == 4 || d3 == 4 || d4 == 4){ 
		             if(tokyo2 == 1 && tokyo1 ==0){
				        hp1 = hp1 - poder2;
				        printf(" %s Atacou %s",jogador2,jogador1);
				        i3++;
				        break;
			         }
		             else if(tokyo2 == 0 && tokyo1 == 1){
				         hp1 = hp1 - poder2;
				         printf("\33[H\33[2J");
                         interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
                         i6 = modobatalha(jogador1, jogador2);
                
                         switch (i6){
							case 1:
							     tokyo1 = 0;
					             tokyo2 = 1;
					             pv2++;
					             i3++;
					             break;
					        case 2:
					             i3 ++;
					             break;
				        }
                        break;  
		            } 
			
		         }
	            else if (d1 != 4 && d2 != 4 && d3 != 4 && d4 != 4){
		               printf("\n Opcao invalida\n Escolha outra opcao >> ");
			           break;
		        }
		 
		 
		 
		 
		 case 2: 
		   if(d1 == 5 || d2 == 5 || d3 == 5 || d4 == 5){ 
			  if(tokyo2==0){
					if(hp2 <= 7){
						hp2 += 3;
						printf(" %s ganhou 3 de HP\n",jogador2);
						i3++;
						break;
					}
					if(hp2 == 8){
						hp2 += 2;
						printf(" %s ganhou 2 de HP\n",jogador2);
						i3++;
						break;
					}
					if(hp2 == 9){
						hp2 +=1;
						printf(" %s ganhou 1 de HP\n",jogador2);
						i3++;
						break;
					}
					if(hp2 == 10){
						printf(" Seu HP esta cheio, nada acontece\n");
						i3++;
						break;
					}
			  }
			  else if(d1 == 5 && d2 == 5 && d3 == 5 && d4 == 5){
					printf(" Os dados vao ser rolados novamente\n\n ");
					i3++;
					i4++;
					break;
			  }
			  else{
				    printf("\n Nao pode se curar com a FORCA\n Escolha outra opcao >> ");
				    break;
				    }
		   }
			  else{
				printf("\n Opcao invalida\n Escolha outra opcao >> ");
				break;
			  }
					 
		 
		 case 3:
		   if(d1 == 6 || d2 == 6 || d3 == 6 || d4 == 6){
			   poder2++;  
			   printf(" %s ganhou 1 de Poder\n",jogador2);
			   i3++;
			   break;
		   }
		   else{
			   printf("\n Opcao invalida\n Escolha outra opcao >> ");  
		       break;
		   }
		 
		 case 4:
		     if (d1 == 3 || d2 == 3 || d3 == 3 || d4 == 3){
				 if((d2==3 && d1==3) || (d1==3 && d3==3) || (d1==3&&d4==3) || (d2==3 && d3==3) || (d2==3 && d4==3) || (d3==3 && d4==3)){
					 pv2 += 3;
					 printf("\n %s ganhou 3 de PV\n",jogador2);
					 i3++;
					 break;
				 }
			 }
			 if (d1 == 2 || d2 == 2 || d3 == 2 || d4 == 2){
				 if((d2==2 && d1==2) || (d1==2 && d3==2) || (d1==2&&d4==2) || (d2==2 && d3==2) || (d2==2 && d4==2) || (d3==2 && d4==2)){
					 pv2 += 2;
					 printf("\n %s ganhou 2 de PV\n",jogador2);
					 i3++;
					 break;
				 }
			 }
			 if (d1 == 1 || d2 == 1 || d3 == 1 || d4 == 1){
				 if(d1==d2 || d1==d3 || d1==d4 || d2 ==d3 || d2==d4 || d3==d4){
					 pv2 += 1;
					 printf("\n %s ganhou 1 de PV\n",jogador2);
					 i3++;
					 break;
				 }
			 }
			 else{
				printf("\n Opcao invalida\n Escolha outra opcao >> ");
				break;
			 }
			 
		if(i9 == 1){ 
		 case 5:
		 	 i3++;
		 	 break;
		 }
      
		 
		 default:
		       printf("\n Opcao invalida\n Digite um valor valido >> ");
		       break;
		 
	   }
     }
   }while(i4 == 1);
          if(tokyo2 == 1){
			  pv2 += 2;
		  }
		  
		  if(hp2 < 1 || pv1 > 19){
			  printf("\33[H\33[2J");
              interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
			  printf("\n\n  %s Assumiu o controle do IMPERIO e SALVOU a galaxia!\n\n",jogador1);
			  printf("\n\n Pressione 'Enter' pra acabar o jogo...\n");
			  getchar();
			  getchar();
			  break;
		  } 
		  if(hp1 < 1 || pv2 > 19){
			  printf("\33[H\33[2J");
              interface(hp1,hp2,pv1,pv2,poder1,poder2,tokyo1,tokyo2,jogador1,jogador2);
			  printf("\n\n %s Assumiu o controle do IMPERIO e DESTRUIU a galaxia!\n\n",jogador2);
			  printf("\n\n Pressione 'Enter' pra acabar o jogo...\n");
		      getchar();
		      getchar();
		      break;
		  }
    
         printf("\n\n Pressione 'Enter' pra ir pro proximo turno...\n");
		 getchar();
		 getchar();
		 
}while(hp1 > 0 || hp2 > 0 || pv1 < 20 || pv2 < 20);	 
		 
	      
    return main();
}
    
