#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Structure Block
typedef struct sBlocList *BlockList;
//Structure Block
typedef struct sBlockChain *BlockChain;


Block firstBlock();
BlockList genBlockList(Block block);
BlockChain genBlockChain(int difficulty);
void addBlock(BlockChain blockChain, Block block);

#endif /* !BLOCKCHAIN_H */
