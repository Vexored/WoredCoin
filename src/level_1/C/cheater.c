#include "cheater.h"

void alteredTransactionBlock(BlockChain* blockChain, Block* blockTemp, int removeTransaction){

  for(int i = removeTransaction; i < getNbTransationBlock(blockTemp) - 1; ++i){
      setListTransactionBlockI(blockTemp, getListTransationBlockI(blockTemp, i + 1), i);
  }

  printf("NB TRANS############################### %d\n\n", getNbTransationBlock(blockTemp));
  //freeBlockTransI(blockTemp, (getNbTransationBlock(blockTemp)));
  //printf("NB TRANS############################### %d\n\n", z);
  setNbTransactionBlock(blockTemp, getNbTransationBlock(blockTemp) - 1);
  printf("\n");
  for(int i = 0; i <  getNbTransationBlock(blockTemp)+1; ++i){
    printf("Transaction %d -> %s\n", i, getListTransationBlockI(blockTemp, i));
  }

  /*for(int i = getIndexBlock(blockTemp); i < getNbBlock(blockChain); ++i){
    setHashPrevious(getBlockInChain(blockChain, i), getHashCurrent(getBlockInChain(blockChain, i - 1)));
    miningBlock(getBlockInChain(blockChain, i), getDifficulty(blockChain));
    //printBlock(getBlockInChain(blockChain, i));
  }*/
}

void alteredRemoveBlock(BlockChain* blockChain, int index){
  //printf("Supprésion d du block %d\n", index);
  removeBlock(blockChain, index);
  //cheatingHash(blockChain, index);
  //printf("finish\n");
  for(int i = index; i < getNbBlock(blockChain); ++i){
  //  printf("CHEATING BLOCK %d\n", i);
  /*  Block* temp1 = getBlockInChain(blockChain, i);
    Block* temp2 = getBlockInChain(blockChain, i - 1);
    setHashPrevious(temp1, getHashCurrent(temp2));
    setIndexBlock(temp1, getIndexBlock(temp1)  - 1);
    miningBlock(temp1, getDifficulty(blockChain));*/
    setHashPrevious(getBlockInChain(blockChain, i), getHashCurrent(getBlockInChain(blockChain, i - 1)));
    miningBlock(getBlockInChain(blockChain, i), getDifficulty(blockChain));
  }
}

/*void cheatingHash(BlockChain* blockChain, int index){

  for(int i = index; i < getNbBlock(blockChain); ++i){
    printf("CHEATING BLOCK %d\n", i);
    Block* temp1 = getBlockInChain(blockChain, i);
    Block* temp2 = getBlockInChain(blockChain, i - 1);
    setHashPrevious(temp1, getHashCurrent(temp2));
    setIndexBlock(temp1, getIndexBlock(temp1)  - 1);
    miningBlock(temp1, getDifficulty(blockChain));
  }
}*/
