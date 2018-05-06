#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "merkel.h"
#include "sha256_utils.h"
#include "blockchain.h"
#include "block.h"
#include "transaction.h"
#include "cheater.h"

int main(int argc, char **argv) {

  printf("Creation de la BlockChain...\n");
  BlockChain* test = genBlockChain(4);

  printf("BlockChain créé.\n");
  int i = 0;
  while(i<1000){


  addBlock(test, GenBlock(getLastBlock(test)));
  printf("\n\n\n#### BLOCK %d\n", getIndexBlock(getLastBlock(test)));

  printf("hashPrevious = %s\n", getHashPrevious(getLastBlock(test)));
  genTransaction(getLastBlock(test));
  miningBlock(getLastBlock(test), getDifficulty(test));
  printf("hashMerkleRoot = %s\n", getHashMerkleRoot(getLastBlock(test)));
  printf("hashPrevious = %s\n", getHashPrevious(getLastBlock(test)));
  printf("hashCurrent = %s\n", getHashCurrent(getLastBlock(test)));
  i++;
  }
  chainIsValid(test);
  alteredRemoveBlock(test, 3);
  chainIsValid(test);

  return 0;
}
