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

int main(int argc, char **argv) {

  printf("Creation de la BlockChain...\n");
  BlockChain* test = genBlockChain(4);

  printf("BlockChain créé.\n");
  int i = 0;
  while(i<2000){

  printf("\n\n\n#### BLOCK %d\n", getLastBlock(test)->index);

  addBlock(test, GenBlock(getLastBlock(test)));
  printf("hashPrevious = %s\n", getLastBlock(test)->hashPrevious);
  genTransaction(getLastBlock(test));
  miningBlock(getLastBlock(test), 5);
  printf("hashMerkleRoot = %s\n", getLastBlock(test)->hashMerkleRoot);
  printf("hashPrevious = %s\n", getLastBlock(test)->hashPrevious);
  printf("hashCurrent = %s\n", getLastBlock(test)->hashCurrent);
  i++;
}

  return 0;
}
