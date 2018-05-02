#include <stdio.h>
#include <stdlib.h>

Block firstBlock();
BlockList genBlockList(Block block);
BlockChain genBlockChain(int difficulty);
void addBlock(BlockChain blockChain, Block block);
