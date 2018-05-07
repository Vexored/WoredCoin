#include "process.h"
//#include "blockchain.h"

int main(int argc, char **argv) {

  BlockChain* test = genBlockChain(2, 20);
  //printBlockChain(test);
  printBlock(getBlockInChain(test, 5));
  hackBlockChain(test, 5, 2);
  printBlock(getBlockInChain(test, 5));


  return 0;
}
