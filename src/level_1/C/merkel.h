#ifndef MERKEL_H
#define MERKEL_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sha256_utils.h"
#include "block.h"

#define HASH_SIZE 32

char* getMerkelRoot(char** tabTransaction, int nbTransaction);

#endif /* !MERKEL_H */
