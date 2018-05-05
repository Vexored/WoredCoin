#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "blockchain.h"

struct sBlockList {
  Block* block;                //Block
  struct sBlockList *next;    //Pointeur vers prochain block
};

struct sBlockChain {
  int nbBlocks;               //Nombre de nbBlock
  int difficulty;             //Difficulté de la blockchain
  BlockList *blocklist;        //Liste des blocks
  BlockList *lastBlockList;    //Dernier block
  //BlockList firstBlockList;
};

Block* firstBlock(int difficulty){
  Block* first = GenesisBlock();
  miningBlock(first, difficulty);
  return first;
}

BlockList* addBlockList(Block* block){

  BlockList* bl = (BlockList*)malloc(sizeof(struct sBlockList));
	bl->block = block;
	bl->next = NULL;
	return bl;
}

BlockChain* genBlockChain(int difficulty){
  BlockChain *blockChain = malloc(sizeof(struct sBlockList));
  blockChain->nbBlocks = 1;
  blockChain->difficulty = difficulty;
  blockChain->blocklist = addBlockList(firstBlock(difficulty));
  blockChain->lastBlockList = blockChain->blocklist;
  return blockChain;

}

Block* getLastBlock(BlockChain* blockChain){
  return blockChain->lastBlockList->block;
}

void addBlock(BlockChain* blockChain, Block* block){
  printf("genBlocklist");
  blockChain->lastBlockList->next = addBlockList(block);
  printf("Add réussi \n");
  blockChain->lastBlockList = blockChain->lastBlockList->next;
  ++(blockChain->nbBlocks);
}

bool chainIsValid(BlockChain* blockChain){
  return true;
}

// Block Genesis
