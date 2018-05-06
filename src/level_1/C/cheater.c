#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cheater.h"

void alteredTransactionBlock(BlockChain* blockChain, Block* blockTemp, int removeTransaction){
  printf("Supprésion de la transaction %d du block %s\n", removeTransaction, getIndexBlock(blockTemp));
  for(int i = removeTransaction; i < getNbTransationBlock(blockTemp) - 1; ++i){
      //strcpy(blockTemp->transactionList[i], getListTransationBlock(blockTemp)[i + 1]);
      setListTransactionBlocIk(blockTemp, getListTransationBlockI(blockTemp, i + 1), i);
  }
  //blockTemp->nbTransaction = blockTemp->nbTransaction - 1;
  setNbTransactionBlock(blockTemp, getNbTransationBlock(blockTemp) - 1);
  cheatingHash(blockChain, getIndexBlock(blockTemp));
  printf("finish\n");
}

void alteredRemoveBlock(BlockChain* blockChain, int index){
  printf("Supprésion d du block %d\n", index);
  removeBlock(blockChain, index);
  cheatingHash(blockChain, index);
  printf("finish\n");
}

void cheatingHash(BlockChain* blockChain, int index){
  printf("Recalculs des hash de la chaine...\n");

  for(int i = index; i < getNbBlock(blockChain); ++i){
    Block* temp1 = getBlockInChain(blockChain, i);
    Block* temp2 = getBlockInChain(blockChain, i - 1);
    //strcpy(temp1->hashPrevious, temp2->hashCurrent);
    setHashPrevious(temp1, getHashCurrent(temp2));
    //temp1->index = temp1->index - 1;
    setIndexBlock(temp1, getIndexBlock(temp1)  - 1);
    miningBlock(temp1, getDifficulty(blockChain));
    printf("\n\n\n#### BLOCK %d\n", getIndexBlock(temp1));
    printf("hashMerkleRoot = %s\n", getHashMerkleRoot(temp1));
    printf("hashPrevious = %s\n", getHashPrevious(temp1));
    printf("hashCurrent = %s\n", getHashCurrent(temp1));
  }
}
