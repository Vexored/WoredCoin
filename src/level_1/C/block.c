#include "block.h"

struct sBlock{

  int index;                      //Numéro du BlockList
  char timeStamp[TIMESTAMP_SIZE]; //

  int nbTransaction;              //Nombre de transaction
  char** transactionList;         //Liste des transactions

  char hashMerkleRoot[HASH_SIZE]; //Hash root de l'arbre de Merkle des transactions
  char hashCurrent[HASH_SIZE];    //Hash du block courant
  char prevHash[HASH_SIZE];       //Hash du block précèdent

  int nonce;                    //Nombre pseudo aléatoire et unique

}
