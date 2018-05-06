#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "block.h"

//Structure Block
typedef struct sBlockList BlockList;
//Structure Block
typedef struct sBlockChain BlockChain;


Block* firstBlock(int difficulty);
BlockList* genBlockList(Block* block);
BlockChain* genBlockChain(int difficulty);
void addBlock(BlockChain* blockChain, Block* block);
Block* getLastBlock(BlockChain* blockChain);

#endif /* !BLOCKCHAIN_H */
