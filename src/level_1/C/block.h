#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Constante
#define MAX_BLOCK 3 //nb de caract du Nombre
#define TIMESTAMP_SIZE 25 //nb de caract du timeStamp
#define MAX_TRANSACTION 100 //nb max de transaction
#define MAX_TRANSACTION_CHAR 3 //nb de caract du Nombre de Transaction
#define TRANSACTION_SIZE 32 // Taille de la chaine de caractère d'une transaction
#define HASH_SIZE 32 //Taille du hash
#define MAX_NONCE 9999999 //Nonce max
#define MAX_NONCE_CHAR 10 //Nb caract max de la nonce

//Structure Block
typedef struct sBlock *Block;

//Fonction
char* getTimeStamp();
bool miningOK(char* hasTemp, int difficulty);
char* miningBlock(Block blockTemp);
Block GenesisBlock();
Block GenBlock(Block prevBlock);