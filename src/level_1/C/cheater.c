#include "cheater.h"

void alteredTransactionBlock(BlockChain* blockChain, Block* blockTemp, int removeTransaction){

  for(int i = removeTransaction; i < getNbTransationBlock(blockTemp) - 1; ++i){
      setListTransactionBlockI(blockTemp, getListTransationBlockI(blockTemp, i + 1), i);
  }

  setNbTransactionBlock(blockTemp, getNbTransationBlock(blockTemp) - 1);
}

void alteredRemoveBlock(BlockChain* blockChain, int index){

  removeBlock(blockChain, index);
  for(int i = index; i < getNbBlock(blockChain); ++i){
      setHashPrevious(getBlockInChain(blockChain, i), getHashCurrent(getBlockInChain(blockChain, i - 1)));
    miningBlock(getBlockInChain(blockChain, i), getDifficulty(blockChain));
  }
}
