#include "merkel.h"


//BYTE buffer[sizeof(a) + sizeof(b)];
//typedef	unsigned char	BYTE ;	/* 8-bit data */
//Fonction de control
char* getMerkelRoot(char** tabTransaction, int nbTransaction){
  //printf("getMerkelRoot -> nbtrans -> %d", nbTransaction);
  /*char** tabHash = malloc((nbTransaction+1) * (sizeof(char*)));
  for(int i = 0; i < nbTransaction + 1; ++i){
    tabHash[i] = malloc(((HASH_SIZE) + 1) * (sizeof(char)));
  }
  //Hashage de chaque transaction si impair on duplique la dernière case du tableau
  for(int i = 0; i < nbTransaction; ++i){
    BYTE buffer[TRANSACTION_SIZE];
    sprintf((char*)buffer, "%s", tabTransaction[i]);
    sha256ofString(buffer, tabHash[i]);
  }

  if(nbTransaction%2 != 0){
    tabHash[nbTransaction] = tabHash[nbTransaction - 1];
    nbTransaction++;
  }
  //Calcul des hash comme un génie
  int i = nbTransaction/2;
  while( i >= 0){
    for(int j = 0; j < i*2; j+=2){
      printf("i-> %d j-> %d tabHash[%d] -> %s\n",i, j, j, tabHash[j]);
      printf("i-> %d j-> %d tabHash[%d] -> %s\n",i, j, j+1, tabHash[j+1]);
        BYTE buffer[sizeof(tabHash[j]) + sizeof(tabHash[j+1])];
        snprintf((char*)buffer, sizeof(buffer), "%s%s", tabHash[j], tabHash[j+1]);
        sha256ofString(buffer, tabHash[j]);



    }
    printf("\n");
    if(i == 1 || i == 0){
      i = i -1;
    }
    else{
      if(i != 0){
        tabHash[i] = tabHash[i - 1];
        ++i;
      }
      i = i/2;
    }*/






    char** tabHash = malloc((nbTransaction+1) * (sizeof(char*)));
    for(int i = 0; i < nbTransaction + 1; ++i){
      tabHash[i] = malloc(((HASH_SIZE) + 1) * (sizeof(char)));
    }
    //Hashage de chaque transaction si impair on duplique la dernière case du tableau
    for(int i = 0; i < nbTransaction; ++i){
      BYTE buffer[TRANSACTION_SIZE];
      sprintf((char*)buffer, "%s", tabTransaction[i]);
      sha256ofString(buffer, tabHash[i]);
    }

    //Calcul des hash comme un génie
    int i = nbTransaction - 1;
    int temp = nbTransaction;
    int inc = 0;

    while(temp != 1){

      if(temp%2 != 0){
        tabHash[temp] = tabHash[temp - 1];
        temp++;
      }
      i = temp - 1;

      for(int indice = 0; indice < i; indice += 2){
        //printf("i-> %d j-> %d tabHash[%d] -> %s\n",i, j, j, tabHash[j]);
        //printf("i-> %d j-> %d tabHash[%d] -> %s\n",i, j, j+1, tabHash[j+1]);
          BYTE buffer[sizeof(tabHash[indice]) + sizeof(tabHash[indice+1])];
          snprintf((char*)buffer, sizeof(buffer), "%s%s", tabHash[indice], tabHash[indice+1]);
          sha256ofString(buffer, tabHash[inc]);
          inc++;
        }
        temp = temp/2;
        inc = 0;

  }

  //printf("HASH ROOT %s\n",tabHash[inc]);
  return tabHash[0];
}
