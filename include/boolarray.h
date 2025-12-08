#ifndef BOOL_ARRAY_H
#define BOOL_ARRAY_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct BoolArray;

BoolArray *boolarray_create();

void boolarray_free(BoolArray *bArray);

size_t boolarray_size(const BoolArray *bArray);

bool boolarray_isEmpty(const BoolArray *bArray);

bool boolarray_add(BoolArray *bArray, bool value);

bool boolarray_addAt(BoolArray *bArray, bool value, size_t index);

bool *boolarray_remove(BoolArray *bArray);

bool *boolarray_removeAt(BoolArray *bArray, size_t index);

bool *boolarray_get(BoolArray *bArray, size_t index);

void boolarray_flipAt(BoolArray *bArray, size_t index);

#endif // BOOL_ARRAY_H