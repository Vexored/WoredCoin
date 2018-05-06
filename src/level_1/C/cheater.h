#ifndef CHEATER_H
#define CHEATER_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "block.h"
#include "blockchain.h"


void alteredTransactionBlock(BlockChain* blockChain, Block* blockTemp, int removeTransaction);
void alteredRemoveBlock(BlockChain* blockChain, int index);
void cheatingHash(BlockChain* blockChain, int index);


























#endif
