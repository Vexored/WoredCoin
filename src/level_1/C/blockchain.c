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
} *BlockChain;


// Block Genesis
