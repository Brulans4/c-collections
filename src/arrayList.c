#include "include/arrayList.h"

typedef struct ArrayList
{
    size_t size;
    size_t capacity;
    void *data;
    int typeSize;
} ArrayList;

ArrayList *arraylist_create(int typeSize)
{
    return arraylist_createInitSize(typeSize, 4);
}

ArrayList *arraylist_createInitSize(int typeSize, int initialSize)
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));

    list->size = 0;
    list->capacity = initialSize;
    list->typeSize = typeSize;

    list->data = malloc(list->capacity * typeSize);
    if (!list->data)
    {
        free(list);
        return NULL;
    }
    return list;
}