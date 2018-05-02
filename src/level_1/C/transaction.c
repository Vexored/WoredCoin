#include transaction.h



void genTransaction(Block block){

  int nb_Transaction = rand()%(MAX_TRANSACTION);

  char* tab_Transaction = malloc(nb_Transaction * sizeof(char*));

  for(int i = 0; i < nbTransaction; ++i){
    tab_Transaction[i] = malloc((MAX_TRANSACTION_CHAR + 1) * sizeof(char));
    snprintf(tab_Transaction[i], sizeof(tab_Transaction[i]), "%s%d","Source-Destination: ", rand()%(MAX_VALUE_RAND));
  }
  block->nbTransaction = nb_Transaction;
  block->tabTransaction = tab_Transaction;
}
