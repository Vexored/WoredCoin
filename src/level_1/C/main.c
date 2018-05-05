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

int main(int argc, char *argv) {

  printf("Creation de la BlockChain...\n");
  BlockChain* test = genBlockChain(2);
  printf("BlockChain créé.\n");

  printf("\nBlock 1\n");
  addBlock(test, GenBlock(getLastBlock(test)));
  genTransaction(getLastBlock(test));
  miningBlock(getLastBlock(test), 2);
  printf("timeStamp = %s\n", getLastBlock(test)->timeStamp);
  printf("hashMerkleRoot = %s\n", getLastBlock(test)->hashMerkleRoot);
  printf("hashPrevious = %s\n", getLastBlock(test)->hashPrevious);
  printf("hashCurrent = %s\n", getLastBlock(test)->hashCurrent);
  printf("Index Block = %d\n", getLastBlock(test)->index);

  printf("\nBlock 2\n");
  addBlock(test, GenBlock(getLastBlock(test)));
  printf("test\n");
  /*genTransaction(getLastBlock(test));
  printf("test\n");
  miningBlock(getLastBlock(test), 2);
  printf("timeStamp = %s\n", getLastBlock(test)->timeStamp);
  printf("hashMerkleRoot = %s\n", getLastBlock(test)->hashMerkleRoot);
  printf("hashPrevious = %s\n", getLastBlock(test)->hashPrevious);
  printf("hashCurrent = %s\n", getLastBlock(test)->hashCurrent);
  printf("Index Block = %d\n", getLastBlock(test)->index);

  printf("\nBlock 3\n");
  addBlock(test, GenBlock(getLastBlock(test)));
  genTransaction(getLastBlock(test));
  miningBlock(getLastBlock(test), 2);
  printf("timeStamp = %s\n", getLastBlock(test)->timeStamp);
  printf("hashMerkleRoot = %s\n", getLastBlock(test)->hashMerkleRoot);
  printf("hashPrevious = %s\n", getLastBlock(test)->hashPrevious);
  printf("hashCurrent = %s\n", getLastBlock(test)->hashCurrent);
  printf("Index Block = %d\n", getLastBlock(test)->index);*/

  return 0;
}
