#include "process.h"
//#include "blockchain.h"

int main(int argc, char **argv) {

  BlockChain* test = genBlockChain(2, 20);
  //printBlockChain(test);
  printBlock(getBlockInChain(test, 5));
  hackBlockChain(test, 5, 2);
  printBlock(getBlockInChain(test, 5));

  //printBlock(getBlockInChain(test, 3));

  //printBlockChain(test);

  //while(i<15){


  /*addBlock(test, GenBlock(getLastBlock(test)));
  //printf("\n\n\n#### BLOCK %d\n", getIndexBlock(getLastBlock(test)));

  //printf("hashPrevious = %s\n", getHashPrevious(getLastBlock(test)));
  genTransaction(getLastBlock(test));
  miningBlock(getLastBlock(test), getDifficulty(test));
  //printf("hashMerkleRoot = %s\n", getHashMerkleRoot(getLastBlock(test)));
  //printf("hashPrevious = %s\n", getHashPrevious(getLastBlock(test)));
  //printf("hashCurrent = %s\n", getHashCurrent(getLastBlock(test)));
  printBlock(getLastBlock(test));
  i++;
  }
  chainIsValid(test);
  alteredRemoveBlock(test, 3);
  chainIsValid(test);*/

  return 0;
}
