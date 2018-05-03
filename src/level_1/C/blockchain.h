#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Block firstBlock();
BlockList genBlockList(Block block);
BlockChain genBlockChain(int difficulty);
void addBlock(BlockChain blockChain, Block block);
