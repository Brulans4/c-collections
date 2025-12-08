#include "../include/boolarray.h"

typedef struct BoolArray
{
    size_t size;
    size_t capacity;
    uint8_t *data;
} BoolArray;

BoolArray *boolarray_create()
{

}

void boolarray_free(BoolArray *bArray)
{
}

size_t boolarray_size(const BoolArray *bArray)
{
}

bool boolarray_isEmpty(const BoolArray *bArray)
{
}

bool boolarray_add(BoolArray *bArray, bool value)
{
}

bool boolarray_addAt(BoolArray *bArray, bool value, size_t index)
{
}

bool *boolarray_remove(BoolArray *bArray)
{
}

bool *boolarray_removeAt(BoolArray *bArray, size_t index)
{
}

bool *boolarray_get(BoolArray *bArray, size_t index)
{
}

void boolarray_flipAt(BoolArray *bArray, size_t index)
{
}