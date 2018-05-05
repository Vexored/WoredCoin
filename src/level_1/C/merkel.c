#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "merkel.h"


//BYTE buffer[sizeof(a) + sizeof(b)];
//typedef	unsigned char	BYTE ;	/* 8-bit data */
//Fonction de control
char* getMerkelRoot(char** tabTransaction, int nbTransaction){
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

  if(nbTransaction%2 != 0){
    tabHash[nbTransaction] = tabHash[nbTransaction - 1];
    nbTransaction++;
  }
  //Calcul des hash comme un génie
  int i = nbTransaction/2;
  while( i >= 0){
    for(int j = 0; j < i*2; j+=2){
        BYTE buffer[sizeof(tabHash[j]) + sizeof(tabHash[j+1])];
        snprintf(buffer, sizeof(buffer), "%s%s", tabHash[j], tabHash[j+1]);
        sha256ofString(buffer, tabHash[j]);

    }
    if(i == 1 || i == 0){
      i = i -1;
    }
    else{
      i = i/2;
    }
  }
  return tabHash[0];
}
