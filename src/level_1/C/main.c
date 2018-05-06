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
  BlockChain* test = genBlockChain(2);

  printf("BlockChain créé.\n");
  int i = 0;
  while(i<10){


  addBlock(test, GenBlock(getLastBlock(test)));
  printf("\n\n\n#### BLOCK %d\n", getLastBlock(test)->index);

  printf("hashPrevious = %s\n", getLastBlock(test)->hashPrevious);
  genTransaction(getLastBlock(test));
  miningBlock(getLastBlock(test), 2);
  printf("hashMerkleRoot = %s\n", getLastBlock(test)->hashMerkleRoot);
  printf("hashPrevious = %s\n", getLastBlock(test)->hashPrevious);
  printf("hashCurrent = %s\n", getLastBlock(test)->hashCurrent);
  i++;
  }
  Block* testB = getBlockInChain(test, 5);
  testB->nonce = 3;
  printf("\n\n\n#### BLOCK %d IS CORRECT ?\n", testB->index);
  if(blockIsValid(testB, 2) == true){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }
  return 0;
}
