#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>
#include <stdint.h>

typedef struct ArrayList ArrayList;

ArrayList *arraylist_create(int typeSize);

ArrayList *arraylist_createInitSize(int typeSize, int initialSize);

#endif // ARRAY_LIST_H