#ifndef BLOCK_H
#define BLOCK_H


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "merkel.h"
#include "sha256_utils.h"


//Constante
#define MAX_BLOCK 3 //nb de caract du Nombre
#define TIMESTAMP_SIZE 25 //nb de caract du timeStamp
#define MAX_TRANSACTION 100 //nb max de transaction
#define MAX_TRANSACTION_CHAR 3 //nb de caract du Nombre de Transaction
#define TRANSACTION_SIZE 30 // Taille de la chaine de caractère d'une transaction
#define HASH_SIZE 64 //Taille du hash
#define MAX_NONCE 9999999 //Nonce max
#define MAX_NONCE_CHAR 10 //Nb caract max de la nonce

typedef struct sBlock{

  int index;                      //Numéro du BlockList
  char timeStamp[TIMESTAMP_SIZE+1]; //Horodatage du block

  int nbTransaction;              //Nombre de transaction
  char** transactionList;         //Liste des transactions

  char* hashMerkleRoot; //Hash root de l'arbre de Merkle des transactions
  char* hashCurrent;    //Hash du block courant
  char* hashPrevious;   //Hash du block précèdent

  int nonce;                      //Nombre pseudo aléatoire et unique

}Block;

//Structure Block
//typedef struct sBlock Block;

//Fonction
char* getTimeStamp();
bool miningOK(char* hasTemp, int difficulty);
void miningBlock(Block* blockTemp, int difficulty);
bool blockIsValid(Block* blockTemp, int difficulty);
Block* GenesisBlock();
Block* GenBlock(Block* prevBlock);

#endif /* !BLOCK_H */
