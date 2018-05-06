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
  miningBlock(first, 0);
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
  blockChain->lastBlockList->next = addBlockList(block);
  blockChain->lastBlockList = blockChain->lastBlockList->next;
  ++(blockChain->nbBlocks);
}

/*bool chainIsValid(BlockChain* blockChain){
  //Vérification du génésis
  char* hashTest[HASH_SIZE*2 + 1];
  if(blockChain->blocklist->block->index == 0 && strcmp(blockChain->blocklist->block->hashPrevious, "0")){
    //On vérifie ça contenance:
    if(blockChain->blocklist->block->nbTransaction == 1 && strcmp(blockChain->blocklist->block->transactionList[0], "Genesis") == 0){
      //On vérifie MERKLE
      if(strcmp(blockChain->blocklist->block->hashMerkleRoot, getMerkelRoot(blockChain->blocklist->block->transactionList, blockChain->blocklist->block->nbTransaction) == 0){
        //On vérifie le hash courant
        strcpy(hashTest, blockChain->blocklist->block->hashCurrent);
        if(strcmp(hashTest, miningBlock(blockChain->blocklist->block, 0))){
          printf("Genesis valide\n");

        }
      }
    }
  }
  for(int i = 1; i<blockChain->nbBlocks; ++i){
    Block blockTemp = getBlockChain(blockChain, i);
    if(BlockIsValide(hashTemp, blockTemp) != true){
      return false;
    }
  }
}*/

Block* getBlockInChain(BlockChain* blockChain, int index){
  BlockList* bl = blockChain->blocklist;

  int nbBlocks = blockChain->nbBlocks;
  for(int i = 0; i < index; i++){
    if(i < nbBlocks){
      bl = bl->next;
    }
    else{
      break;
    }
  }
  return bl->block;
}
// Block Genesis
