#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cheater.h"

/*void alteredTransactionBlock(Block* blockTemp, int removeTransaction){
  printf("Supprésion de la transaction %d du block %s\n", removeTransaction, blockTemp->index);
  for(int i = removeTransaction; i < blockTemp->nbTransaction - 1; ++i){
      strcpy(blockTemp->transactionList[i], blockTemp->transactionList[i + 1]);
  }
  prinft("Recalculs des hash de la chaine...\n");
  blockTemp->nbTransaction = blockTemp->nbTransaction - 1;
  for(int i = blockTemp->index; i < getNbBlock(blockChain); ++i){
    Block* temp1 = getBlockInChain(blockChain, i);
    Block* temp2 = getBlockInChain(blockChain, i - 1);
    strcpy(temp1->hashPrevious, temp2->hashCurrent);
    temp1->index = temp1->index - 1;
    miningBlock(temp1, getDifficulty(blockChain));
    printf("hashMerkleRoot = %s\n", temp1->hashMerkleRoot);
    printf("hashPrevious = %s\n", temp1->hashPrevious);
    printf("hashCurrent = %s\n", temp1->hashCurrent);
  }
  printf("finish\n");
}*/

void alteredRemoveBlock(BlockChain* blockChain, int index){
  printf("Supprésion d du block %d\n", index);
  removeBlock(blockChain, index);
  printf("Recalculs des hash de la chaine...\n");
  for(int i = index; i < getNbBlock(blockChain); ++i){
    Block* temp1 = getBlockInChain(blockChain, i);
    Block* temp2 = getBlockInChain(blockChain, i - 1);
    strcpy(temp1->hashPrevious, temp2->hashCurrent);
    temp1->index = temp1->index - 1;
    miningBlock(temp1, getDifficulty(blockChain));
    printf("\n\n\n#### BLOCK %d\n", temp1->index);
    printf("hashMerkleRoot = %s\n", temp1->hashMerkleRoot);
    printf("hashPrevious = %s\n", temp1->hashPrevious);
    printf("hashCurrent = %s\n", temp1->hashCurrent);
  }
  printf("finish\n");
}
