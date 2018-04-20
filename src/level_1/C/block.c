#include <stdio.h>
#include <stdlib.h>

#define MAX_DATE_SIZE 100

struct Block {

  int index;
  char[DATE_SIZE] timestamp;
  int nb_transaction;

  //Liste des transaction a implementer

  char[HASH_SIZE] hash_prev;
  char[HASH_SIZE] hash_root;
  char[HASH_SIZE] hash_current;

  int nonce;

  struct Block *p_next;
  struct Block *p_prev;
}
