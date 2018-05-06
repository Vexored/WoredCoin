#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "block.h"

char* getTimeStamp(){
  time_t ltime;
  time(&ltime);
  return ctime(&ltime);
}

bool miningOK (char* hashTemp, int difficulty){
  for(int i = 0; i < difficulty; ++i){
    if(hashTemp[i] != '0'){
      return false;
    }
  }
  return true;
}


void miningBlock(Block* blockTemp, int difficulty){
  //concaténer les infos du block -> Taille + malloc
  int sizeConcat = MAX_BLOCK + TIMESTAMP_SIZE + MAX_TRANSACTION + (TRANSACTION_SIZE)*blockTemp->nbTransaction + (HASH_SIZE)*2 + MAX_NONCE_CHAR;

  char* hashBlock = malloc((HASH_SIZE + 1)*sizeof(char));
  char* tabConcat = malloc( (sizeConcat + 1) * sizeof(char));

  char IndexToString[MAX_BLOCK];
  char NbTransToString[MAX_TRANSACTION];
  char NonceToString[MAX_NONCE_CHAR];

  sprintf(IndexToString, "%d", blockTemp->index);
  sprintf(NbTransToString, "%d", blockTemp->nbTransaction);


  strcpy(tabConcat, IndexToString);
  strcat(tabConcat, blockTemp->timeStamp);
  strcat(tabConcat, NbTransToString);

  for(int i = 0; i < blockTemp->nbTransaction; i++){
    strcat(tabConcat, blockTemp->transactionList[i]);
  }

  blockTemp->hashMerkleRoot = getMerkelRoot(blockTemp->transactionList, blockTemp->nbTransaction);
  //printf("STRLEN TABCONCAT = %d  MERKLE ROOT %d", strlen(tabConcat), strlen(blockTemp->hashMerkleRoot));
  //printf("HASH MERKLE %s\n", blockTemp->hashMerkleRoot);
  strcat(tabConcat, blockTemp->hashMerkleRoot);
  //printf("HASH PREV %s\n", blockTemp->hashPrevious);
  strcat(tabConcat, blockTemp->hashPrevious);

  int nonce = 0;
  char* tabConcatNonce = malloc((sizeConcat + 1) * sizeof(char));
  while(1){
    strcpy(tabConcatNonce, tabConcat);
    sprintf(NonceToString, "%d", nonce);
    strcat(tabConcatNonce, NonceToString);
    sha256ofString((BYTE*)tabConcatNonce, hashBlock);
    if(miningOK(hashBlock, difficulty) ==true){
      break;
    }
    nonce = nonce + 1;
  }
  blockTemp->hashCurrent = hashBlock;
  blockTemp->nonce = nonce;
}

bool blockIsValid(Block* blockTemp, int difficulty){


  //concaténer les infos du block -> Taille + malloc
  int sizeConcat = MAX_BLOCK + TIMESTAMP_SIZE + MAX_TRANSACTION + (TRANSACTION_SIZE)*blockTemp->nbTransaction + (HASH_SIZE)*2 + MAX_NONCE_CHAR;

  char* hashBlock = malloc((HASH_SIZE + 1)*sizeof(char));
  char* tabConcat = malloc( (sizeConcat + 1) * sizeof(char));

  char IndexToString[MAX_BLOCK];
  char NbTransToString[MAX_TRANSACTION];
  char NonceToString[MAX_NONCE_CHAR];

  sprintf(IndexToString, "%d", blockTemp->index);
  sprintf(NbTransToString, "%d", blockTemp->nbTransaction);

  strcpy(tabConcat, IndexToString);
  strcat(tabConcat, blockTemp->timeStamp);
  strcat(tabConcat, NbTransToString);

  for(int i = 0; i < blockTemp->nbTransaction; i++){
    strcat(tabConcat, blockTemp->transactionList[i]);
  }
  getMerkelRoot(blockTemp->transactionList, blockTemp->nbTransaction);
  strcat(tabConcat, getMerkelRoot(blockTemp->transactionList, blockTemp->nbTransaction));
  strcat(tabConcat, blockTemp->hashPrevious);
  sprintf(NonceToString, "%d", blockTemp->nonce);
  strcat(tabConcat, NonceToString);
  sha256ofString((BYTE*)tabConcat, hashBlock);
  if(strcmp(hashBlock, blockTemp->hashCurrent) == 0){
    return true;
  }
  return false;
}

bool merkleIsValid(Block* blockTemp){
  if(strcmp(blockTemp->hashMerkleRoot, getMerkelRoot(blockTemp->transactionList, blockTemp->nbTransaction)) == 0){
    return true;
  }
  return false;
}


Block* GenesisBlock(){

  char* timeStamp = getTimeStamp();

  Block* temp = malloc(sizeof(struct sBlock));

  temp->index = 0;
  temp->nbTransaction = 1;

  temp->transactionList = malloc(sizeof(char)*8);
  temp->transactionList[0] = "Genesis";
  strcpy(temp->timeStamp,timeStamp);
  temp->hashPrevious = "0";

  return temp;
}

Block* GenBlock(Block* prevBlock){

  char *timeStamp = getTimeStamp();

  Block* temp = (Block*) malloc(sizeof(struct sBlock));

  temp->index = prevBlock->index + 1;
  strcpy(temp->timeStamp, timeStamp);
  temp->hashPrevious = prevBlock->hashCurrent;

  return temp;
}
