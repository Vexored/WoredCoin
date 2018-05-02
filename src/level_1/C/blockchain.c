#define "blockchain.h"

typedef struct sBlockList {
  Block block;                //Block
  struct sBlockList *next;    //Pointeur vers prochain block
} *BlockList;

typedef struct sBlockChain {
  int nbBlocks;               //Nombre de nbBlock
  int difficulty;             //Difficulté de la blockchain
  BlockList blocklist;        //Liste des blocks
  BlockList lastBlockList;    //Dernier block
  //BlockList firstBlockList;
} *BlockChain;

Block firstBlock(){
  Block first = GenesisBlock();
  miningBlock(first, difficulty);
  return first;
}

BlockList genBlockList(Block block){
  BlockList bl = malloc(sizeof(struct sBlockList));
	bl->block = block;
	bl->next = NULL;
	return bl;
}

BlockChain genBlockChain(int difficulty){
  BlockChain blockChain = malloc(sizeof(struct sBlockList));
  blockChain->nbBlocks = 1;
  blockChain->difficulty = difficulty;
  blockChain->blocklist = genBlockList();
  bloackChain->lastBlockList = blockChain->blocklist;

  return blockChain;

}

void addBlock(BlockChain blockChain, Block block){
  blockChain->lastBlockList->next = genBlockList(block);
  blockChain->lastBlockList = blockChain->lastBlockList->next;
  ++(blockChain->nbBlocks);
}


// Block Genesis
