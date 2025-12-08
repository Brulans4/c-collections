#include "../include/boolarray.h"

typedef struct BoolArray
{
    size_t size;
    size_t capacity;
    uint8_t *data;
} BoolArray;

BoolArray *boolarray_create()
{
    BoolArray* bArray = malloc(sizeof(BoolArray));
    uint8_t* pInt8 = malloc(sizeof(uint8_t));

    if (bArray == NULL || pInt8 == NULL)
    {
        return NULL;
    }
    bArray->capacity = sizeof(uint8_t);
    bArray->size = 0;
    bArray->data = pInt8;
    
    return bArray;
}

void boolarray_free(BoolArray *bArray)
{
    if (bArray == NULL)
    {
        return;
    }
    free(bArray->data);
    free(bArray);
}

size_t boolarray_size(const BoolArray *bArray)
{
    if (bArray == NULL)
    {
        return -1;
    }
    return bArray->size;
}

bool boolarray_isEmpty(const BoolArray *bArray)
{
    return boolarray_size(bArray) == 0;
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