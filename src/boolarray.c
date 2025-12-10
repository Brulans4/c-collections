#include "../include/boolarray.h"

typedef struct BoolArray
{
    size_t size;
    size_t capacity;
    uint8_t *data;
} BoolArray;

static bool boolarray_resizeList(BoolArray *bArray);

BoolArray *boolarray_create()
{
    BoolArray *bArray = malloc(sizeof(BoolArray));
    uint8_t *pInt8 = malloc(sizeof(uint8_t));

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
    if (bArray == NULL)
    {
        return false;
    }

    size_t index = (bArray->size >> 3);
    uint8_t bitIndex = (bArray->size & 0x07u);

    uint8_t bitmask = 0x01u << bitIndex;

    uint8_t *dataArray = bArray->data;

    if (value)
    {
        dataArray[index] |= bitmask;
    }
    else
    {
        dataArray[index] &= ~bitmask;
    }
    bArray->size++;

    if (bArray->size == bArray->capacity)
    {
        return boolarray_resizeList(bArray);
    }
    return true;
}

bool boolarray_addAt(BoolArray *bArray, bool value, size_t index)
{
    if (bArray == NULL)
    {
        return false;
    }
    if (index < 0 || bArray->size < index)
    {
        return false;
    }

    for (size_t i = bArray->size; i > index; i--)
    {
        bool bitValue;
        if (boolarray_get(bArray, &bitValue, i - 1) == false)
        {
            return false;
        }

        if (boolarray_set(bArray, i, &bitValue) == false)
        {
            return false;
        }
    }
    boolarray_set(bArray, index, value);

    bArray->size++;
    if (bArray->size == bArray->capacity)
    {
        return boolarray_resizeList(bArray);
    }
    return true;
}

static bool boolarray_resizeList(BoolArray *bArray)
{
    size_t newCapacity = bArray->capacity * 2;
    uint8_t *newData = malloc((newCapacity >> 3) * sizeof(uint8_t));

    if (!newData)
    {
        return false;
    }
    uint8_t *oldData = (uint8_t *)bArray->data;

    memcpy(newData,
           oldData,
           (bArray->capacity >> 3) * sizeof(uint8_t));
    free(oldData);

    bArray->data = newData;
    bArray->capacity = newCapacity;

    return true;
}

bool boolarray_remove(BoolArray *bArray, bool *res)
{
}

bool boolarray_removeAt(BoolArray *bArray, bool *res, size_t index)
{
}

bool boolarray_get(const BoolArray *bArray, bool *res, size_t index)
{
    if (bArray == NULL)
    {
        return false;
    }
    if (index < 0 || bArray->size <= index)
    {
        return false;
    }
    size_t byte = index >> 3;
    uint8_t bit = index & 0x07u;

    *res = ((bArray->data[byte]) >> bit) & 0x01u;
    return true;
}

bool boolarray_set(BoolArray *bArray, size_t index, bool value)
{
    if (bArray == NULL)
    {
        return false;
    }
    if (index < 0 || bArray->size <= index)
    {
        return false;
    }
    size_t byte = index >> 3;
    uint8_t bit = index & 0x07u;

    if (value == true)
    {
        (bArray->data[byte]) |= (0x01u << bit);
    }
    else
    {
        (bArray->data[byte]) &= ~(0x01u << bit);
    }
    return true;
}

bool boolarray_flip(BoolArray *bArray, size_t index)
{
    if (bArray == NULL)
    {
        return false;
    }
    if (index < 0 || bArray->size <= index)
    {
        return false;
    }
    size_t byteIndex = index >> 3;
    uint8_t bitIndex = index & 0x07u;

    bArray->data[byteIndex] = bArray->data[byteIndex] ^ (0x01u << bitIndex);
    return true;
}