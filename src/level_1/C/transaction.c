#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "transaction.h"
#include "block.h"

void genTransaction(Block* block){
  printf("coucou");
  srand((unsigned int) clock());
  int nb_Transaction = (rand()%(MAX_TRANSACTION) + 1);
  printf("Nombre de transaction rand -> %d\n", nb_Transaction);
  char** tab_Transaction = malloc(nb_Transaction * sizeof(char*));
  char buffer[10];

  for(int i = 0; i < nb_Transaction; ++i){

    tab_Transaction[i] = malloc((TRANSACTION_SIZE + 1) * sizeof(char));
    //tab_Transaction[i] = "Source-Destination: ";
    sprintf(tab_Transaction[i], "%s%d", "Source-Destination: ", rand()%MAX_VALUE_RAND);
        //strcat(tab_Transaction[i], buffer);
  }
  block->nbTransaction = nb_Transaction;
  block->transactionList = tab_Transaction;
}
