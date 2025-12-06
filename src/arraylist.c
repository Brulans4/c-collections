#include "../include/arraylist.h"

typedef struct ArrayList
{
    size_t size;
    size_t capacity;
    int typeSize;
    void *data;
} ArrayList;

/**
 * Declaration of static functon signature
 */
static void arraylist_resize(ArrayList *list);
static void arraylist_resizeList(ArrayList *list, float factor);

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

size_t arraylist_size(const ArrayList *list)
{
    return list->size;
}

void arraylist_Add(ArrayList *list, void *element)
{
    uint8_t *byteData = (uint8_t *)list->data;
    memcpy(byteData + list->typeSize * list->size,
           element,
           list->typeSize);
    list->size++;

    if (list->size == list->capacity)
    {
        arraylist_resize(list);
    }
}

void arraylist_AddIndex(ArrayList *list, void *element, size_t index)
{
    if (list->size <= index)
    {
        return;
    }

    uint8_t *byteData = (uint8_t *)list->data;

    memmove(byteData + ((index + 1) * list->typeSize),
            byteData + (index * list->typeSize),
            (list->size - index) * list->typeSize);

    memcpy(byteData + (index * list->typeSize),
           element,
           list->typeSize);
    list->size++;

    if (list->size == list->capacity)
    {
        arraylist_resize(list);
    }
}

static void arraylist_resize(ArrayList *list)
{
    if (list->capacity <= 1024)
    {
        arraylist_resizeList(list, 2.0);
    }
    else
    {
        arraylist_resizeList(list, 1.3);
    }
}

static void arraylist_resizeList(ArrayList *list, float factor)
{
    size_t newCapacity = list->capacity * factor;
    uint8_t *newData = malloc(newCapacity * list->typeSize);

    if (!newData)
    {
        return;
    }

    uint8_t *oldData = (uint8_t *)list->data;

    memcpy(newData,
           oldData,
           list->size * list->typeSize);
    free(oldData);

    list->data = newData;
    list->capacity = newCapacity;
}

void *arraylist_Remove(ArrayList *list)
{
    if (list->size == 0)
    {
        return NULL;
    }

    void *element = malloc(list->typeSize);
    if (!element)
    {
        return NULL;
    }
    uint8_t *byteData = (uint8_t *)list->data;

    memcpy(element,
           byteData,
           list->typeSize);
    list->size--;

    memmove(byteData,
            byteData + list->typeSize,
            list->typeSize * list->size);

    return element;
}

void *arraylist_RemoveIndex(ArrayList *list, size_t index)
{
    if (list->size == 0)
    {
        return NULL;
    }

    void *element = malloc(list->typeSize);
    if (!element)
    {
        return NULL;
    }
    uint8_t *byteData = (uint8_t *)list->data;

    memcpy(element,
           byteData + (index * list->typeSize),
           list->typeSize);
    list->size--;

    memmove(byteData + (index * list->typeSize),
            byteData + (index + 1) * list->typeSize,
            list->typeSize * (list->size - index));

    return element;
}