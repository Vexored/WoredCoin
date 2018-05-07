#ifndef PROCESS_H
#define PROCESS_H

//Librairie
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Fichier h
#include "blockchain.h"
#include "block.h"
#include "transaction.h"
#include "cheater.h"
#include "merkel.h"
#include "sha256_utils.h"
#include "config.h"

void createBlock(BlockChain* temp);
void printBlockMining(Block* blockTemp);
void printBlock(Block* blockTemp);
void printBlockChain(BlockChain* blockChain);
bool verifBlockChain(BlockChain* blockChain);
bool verifHashRoot(BlockChain* blockChain);
void hackBlockChain(BlockChain* blockChain, int i, int transaction);
BlockChain* genBlockChain(int difficulty, int nbBlock);

#endif /* !PROCESS_H */
