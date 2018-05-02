#include "block.h"

#define MAX_BLOCK 3 //nb de caract du Nombre
#define TIMESTAMP_SIZE


struct sBlock{

  int index;                      //Numéro du BlockList
  char timeStamp[TIMESTAMP_SIZE+1]; //Horodatage du block

  int nbTransaction;              //Nombre de transaction
  char* transactionList[NB_TRANSACTION_MAX];         //Liste des transactions

  char hashMerkleRoot[HASH_SIZE+1]; //Hash root de l'arbre de Merkle des transactions
  char hashCurrent[HASH_SIZE+1];    //Hash du block courant
  char hashPrevious[HASH_SIZE+1];   //Hash du block précèdent

  int nonce;                      //Nombre pseudo aléatoire et unique

};

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


void miningBlock(Block blockTemp, int difficulty){
  //concaténer les infos du block -> Taille + malloc
  int sizeConcat = MAX_BLOCK + TIMESTAMP_SIZE + MAX_TRANSACTION + TRANSACTION_SIZE*blocktemp->nbTransaction + HASH_SIZE*2 + MAX_NONCE;
  char* hashBlock[HASH_SIZE + 1];
  char* tabConcat = malloc( (sizeConcat + 1) * sizeof(char));
  char* tabConcatNonce = malloc( (sizeConcat + 1) * sizeof(char));
  //Concaténation
  snprinft(tabConcat, sizeof(tabConcat), "%d%s%d", blockTemp->index, blockTemp->timeStamp, blockTemp->nbTransaction);
  for(int i = 0; i < blockTemp->nbTransaction; i++){
    snprintt(tabConcat, sizeof(tabConcat), "%s", blockTemp->transactionList[i]);
  }
  blockTemp->hashMerkleRoot = getMerkelRoot(blockTemp->transactionList, blockTemp->nbTransaction);
  snprintf(tabConcat, sizeof(tabConcat), "%s", blockTemp->hashMerkleRoot);
  snprintf(tabConcat, sizeof(tabConcat), "%s", blockTemp->hashPrevious);

  int nonce = 0,

  while(1){
    tabConcatNonce = tabConcat;
    snprintf(tabConcatNonce, sizeof(tabConcatNonce), "%d", nonce);
    sha256ofString((BYTE*)tabConcat, hashBlock);
    if(miningOK(hashBlock, difficulty)){
      break;
    }
    nonce++;
  }
  blockTemp->hashCurrent = hashBlock;
  blockTemp->Nonce = nonce;
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
