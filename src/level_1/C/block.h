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

typedef struct sBlock Block;

//Structure Block
//typedef struct sBlock Block;

int getIndexBlock(Block* blockTemp);
void setIndexBlock(Block* blockTemp, int index);
char* getTimeStampBlock(Block* blockTemp);
void setTimeStampBlock(Block* blockTemp, char* timeStamp);
int getNbTransationBlock(Block* blockTemp);
void setNbTransactionBlock(Block* blockTemp, int nb);
char** getListTransationBlock(Block* blockTemp);
void setListTransactionBlock(Block* blockTemp, char** transaction);
char* getListTransationBlockI(Block* blockTemp, int index);

void setListTransactionBlocIk(Block* blockTemp, char* transaction, int index);

char* getHashMerkleRoot(Block* blockTemp);
void setHashMerkleRoot(Block* blockTemp, char* hash);
char* getHashPrevious(Block* blockTemp);
void setHashPrevious(Block* blockTemp, char* hash);
char* getHashCurrent(Block* blockTemp);
void setHashCurrent(Block* blockTemp, char* hash);
int getNonceBlock(Block* blockTemp);
void setNonceBlock(Block* blockTemp, int nonce);

//Fonction
char* getTimeStamp();
bool miningOK(char* hasTemp, int difficulty);
void miningBlock(Block* blockTemp, int difficulty);
bool blockIsValid(Block* blockTemp, int difficulty);
bool merkleIsValid(Block* blockTemp);
Block* GenesisBlock();
Block* GenBlock(Block* prevBlock);

#endif /* !BLOCK_H */
