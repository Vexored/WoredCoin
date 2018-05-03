#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "merkel.h"

//BYTE buffer[sizeof(a) + sizeof(b)];
typedef	unsigned char	BYTE ;	/* 8-bit data */
//Fonction de control
char* getMerkelRoot(char** tabTransaction, int nbTransaction){

  char** tabHash = malloc(nbTransaction * (sizeof(char*)));
  for(int i = 0; i < nbTransaction; ++i){
    tabHash[i] = malloc(HASH_SIZE * (sizeof(char)) + 2);
  }
  //Hashage de chaque transaction si impair on duplique la dernière case du tableau
  for(int i = 0; i < nbTransaction; ++i){
    BYTE buffer[sizeof(tabTransaction[i])] = tabTransaction[i];
    sha256ofString(buffer, tabHash[i]);
  }
  if(nbTransaction%2 != 0){
    tabHash[nbTransaction - 1] = tabHash[nbTransaction - 2];
  }
  //Calcul des hash comme un génie
  for(int i = nbTransaction/2; i >= 0; i = i/2){
    for(int j = 0; j < i*2; j = j + 2){
        BYTE buffer[sizeof(tabHash[j]) + sizeof(tabHash[j+1])];
        snprintf(buffer, sizeof(buffer), "%s%s", tabHash[j], tabHash[j+1]);
        sha256ofString(buffer, tabHash[j]);
    }
  }
  return tabHash[0];
}
