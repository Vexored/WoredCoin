#include "process.h"

void createBlock(BlockChain* temp){
  addBlock(temp, GenBlock(getLastBlock(temp)));
  genTransaction(getLastBlock(temp));
  miningBlock(getLastBlock(temp), getDifficulty(temp));
}

void printBlockMining(Block* blockTemp){
  printf("### BLOCK -> %d ### NB TRANSACTION -> %d\n### HASH MERKLE ROOT -> %s\n### HASH CURRENT -> %s\n### MINER EN xx\n\n", getIndexBlock(blockTemp), getNbTransationBlock(blockTemp), getHashMerkleRoot(blockTemp), getHashCurrent(blockTemp));
}

void printBlock(Block* blockTemp){
  printf("### BLOCK -> %d ### NB TRANSACTION -> %d\n### HASH PREV -> %s \n### HASH MERKLE ROOT -> %s\n### HASH CURRENT -> %s\n\n", getIndexBlock(blockTemp), getNbTransationBlock(blockTemp), getHashPrevious(blockTemp), getHashMerkleRoot(blockTemp), getHashCurrent(blockTemp));
}

void printBlockChain(BlockChain* blockChain){
  printf("### AFFICHAGE BLOCKCHAIN ### NOMBRE DE BLOCK %d ###\n", getNbBlock(blockChain));
  for(int i = 0; i< getNbBlock(blockChain); ++i){
    Block* temp = getBlockInChain(blockChain, i);
    printBlock(temp);
  }
  printf("### FIN AFFICHAGE BLOCKCHAIN ###\n\n");
}

bool verifBlockChain(BlockChain* blockChain){
  printf("### VERIFICATION DE LA COHERENCE DE LA BLOCKCHAIN ###\n");
  if(chainIsValid(blockChain) == true){
    printf("\n### LA BLOCKCHAIN EST COHERENTE ###\n\n");
    return true;
  }
  else{
    printf("\n### LA BLOCKCHAIN N'EST PAS COHERENTE ###\n\n");
    return false;
  }
}

bool verifHashRoot(BlockChain* blockChain){
  printf("### VERIFICATION DES HASHMERKLE DES BLOCS DE LA BLOCKCHAIN ###\n");
  if(merkleIsValid(blockChain) == true){
    printf("### LES HASHMERKLE DES BLOCS SONT VALIDES ###\n\n");
    return true;
  }
  else{
    printf("### LES HASHMERKLE DES BLOCS NE SONT PAS VALIDES ###\n\n");
    return false;
  }
}

void hackBlockChain(BlockChain* blockChain, int i, int transaction){
  printf("### CHEATER OF BLOCKCHAIN ###\n");
  if(transaction > -1){
    printf("### SUPPRESSION LA TRANSACTION n°%d DU BLOCK n°%d ###\n", transaction, i);
    printf("### RECALCUL DE TOUT LES HASHS DES BLOCKS A PARTIR DU BLOCK n°%d DE LA BLOCKCHAIN ###\n", i);

    float temps;
    clock_t t1, t2;
    t1 = clock();
    alteredTransactionBlock(blockChain, getBlockInChain(blockChain, i), transaction);
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("### FIN DU CALCUL DE TOUT LES HASHS DES BLOCKS DE LA BLOCKCHAIN EN %fs ###\n",temps);
    verifBlockChain(blockChain);
  }
  else{
    printf("### SUPPRESSION DU BLOCK n°%d ###\n", i);
    printf("### RECALCUL DE TOUT LES HASHS DES BLOCKS A PARTIR DU BLOCK n°%d DE LA BLOCKCHAIN ###\n", i);

    float temps;
    clock_t t1, t2;
    t1 = clock();
    alteredRemoveBlock(blockChain, i);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("### FIN DU CALCUL DE TOUT LES HASHS DES BLOCKS DE LA BLOCKCHAIN EN %fs ###\n",temps);
    verifBlockChain(blockChain);
  }
}
//cheater

BlockChain* genBlockChain(int difficulty, int nbBlock){
  printf("### GENERATION BLOCKCHAIN ###\n");
  //Genération de blockchain + génésis
  BlockChain* temp = createBlockChain(difficulty);
  //Génération x block

  for(int i  = 0; i < nbBlock; ++i){
    printf("### GENERATION BLOCK n° %d ###\n", i + 1);
    createBlock(temp);
    printBlock(getLastBlock(temp));
  }
  printf("### GENERATION BLOCKCHAIN TERMINEE ###\n\n");
  return temp;
}
