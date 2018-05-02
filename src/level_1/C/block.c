#include "block.h"

struct sBlock{

  int index;                      //Numéro du BlockList
  char timeStamp[TIMESTAMP_SIZE]; //

  int nbTransaction;              //Nombre de transaction
  char* transactionList[NB_TRANSACTION_MAX];         //Liste des transactions

  char hashMerkleRoot[HASH_SIZE]; //Hash root de l'arbre de Merkle des transactions
  char hashCurrent[HASH_SIZE];    //Hash du block courant
  char hashPrevious[HASH_SIZE];       //Hash du block précèdent

  int nonce;                    //Nombre pseudo aléatoire et unique

} *Block;

char* getTimeStamp(){
  return ctime(time(NULL));
}

bool miningOK (char* hashTemp, int difficulty){
  for(int i; i < difficulty){
    if(hashTemp[i] != '0'){
      return false;
    }
  }
  return true;
}


char* miningBlock(Block blockTemp){

}

Block GenesisBlock(){

  char *timeStamp = genTimeStamp();

  Block temp = malloc(sizeof * (struct sBlock));

  temp->index = 0;
  temp->nbTransaction = 1;

  temp->transactionList = malloc(sizeof * (char[7]));
  temp->transactionList[0] = "Genesis";

  temp->hashMerkleRoot = getMerkleRoot(temp->transactionList, 1);
  temp->hashPrevious = 0;
  //temp->hashCurrent = fonction de hash


  return temp;
}
