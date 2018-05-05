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
  int sizeConcat = MAX_BLOCK + TIMESTAMP_SIZE + MAX_TRANSACTION + (TRANSACTION_SIZE)*blockTemp->nbTransaction + (HASH_SIZE)*2 + MAX_NONCE;
  char* hashBlock = malloc((HASH_SIZE + 1)*sizeof(char));
  char* tabConcat = malloc( (sizeConcat + 1) * sizeof(char));
  char* Buffer = malloc( (sizeConcat + 1) * sizeof(char));

  char* tabConcatNonce = malloc( (sizeConcat + 1) * sizeof(char));
  //Concaténation
  sprintf(tabConcat, "%d%s%d", blockTemp->index, blockTemp->timeStamp, blockTemp->nbTransaction);
  for(int i = 0; i < blockTemp->nbTransaction; i++){
    sprintf(Buffer,"%s", blockTemp->transactionList[i]);
    strcat(tabConcat, Buffer);
  }
  blockTemp->hashMerkleRoot = getMerkelRoot(blockTemp->transactionList, blockTemp->nbTransaction);
  strcat(tabConcat, blockTemp->hashMerkleRoot);
  strcat(tabConcat, blockTemp->hashPrevious);

  int nonce = 0;
  while(1){
    tabConcatNonce = tabConcat;
    snprintf(Buffer, sizeof(Buffer), "%d", nonce);
    strcat(tabConcat, Buffer);
    sha256ofString((BYTE*)tabConcatNonce, hashBlock);
    if(miningOK(hashBlock, difficulty) ==true){
      break;
    }
    nonce = nonce + 1;
  }
  blockTemp->hashCurrent = hashBlock;
  blockTemp->nonce = nonce;
}

bool blockIsValid(Block* blockTemp){

  char* hashBlock[HASH_SIZE + 1];
  strcpy(hashBlock, getMerkelRoot(blockTemp->transactionList, blockTemp->nbTransaction));
  if(blockTemp->hashMerkleRoot == hashBlock){
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
  temp->hashPrevious = malloc((HASH_SIZE + 1) *sizeof(char));
  temp->hashPrevious = "0";

  return temp;
}

Block* GenBlock(Block* prevBlock){

  char *timeStamp = getTimeStamp();

  Block* temp = malloc(sizeof(struct sBlock));

  temp->index = prevBlock->index + 1;
  strcpy(temp->timeStamp, timeStamp);
  temp->hashPrevious = prevBlock->hashCurrent;

  return temp;
}
