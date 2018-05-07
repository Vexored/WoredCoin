#include "transaction.h"


void genTransaction(Block* block){

  srand((unsigned int) clock());
  int nb_Transaction = (rand()%(MAX_TRANSACTION) + 1);
  //int nb_Transaction = ;
  //printf("Nombre de transaction rand -> %d\n", nb_Transaction);
  char** tab_Transaction = malloc(nb_Transaction * sizeof(char*));
  for(int i = 0; i < nb_Transaction; ++i){

    tab_Transaction[i] = malloc((TRANSACTION_SIZE + 1) * sizeof(char));
    //tab_Transaction[i] = "Source-Destination: ";
    sprintf(tab_Transaction[i], "%s%d", "Source-Destination: ", rand()%MAX_VALUE_RAND);
        //strcat(tab_Transaction[i], buffer);
  }
  //block->nbTransaction = nb_Transaction;
  //block->transactionList = tab_Transaction;
  setNbTransactionBlock(block, nb_Transaction);
  setListTransactionBlock(block, tab_Transaction);
}
