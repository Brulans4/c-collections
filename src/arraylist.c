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
static bool arraylist_resize(ArrayList *list);
static bool arraylist_resizeList(ArrayList *list, float factor);

ArrayList *arraylist_create(size_t typeSize)
{
    return arraylist_createInitSize(typeSize, 4);
}

ArrayList *arraylist_createInitSize(size_t typeSize, size_t initialSize)
{
    if (typeSize == 0 || initialSize == 0)
    {
       return NULL;
    }
    
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));

    list->size = 0;
    list->capacity = initialSize;
    list->typeSize = typeSize;

    list->data = malloc((list->capacity) * typeSize);
    if (!list->data)
    {
        free(list);
        return NULL;
    }
    return list;
}

void arraylist_free(ArrayList *list)
{
    if (list == NULL)
    {
        return;
    }
    free(list->data);
    free(list);
}

size_t arraylist_size(const ArrayList *list)
{
    if (list == NULL)
    {
        return -1;
    }
    return list->size;
}

bool arraylist_add(ArrayList *list, void *element)
{
    if (list == NULL || element == NULL)
    {
        return false;
    }
    uint8_t *byteData = (uint8_t *)list->data;

    memcpy(byteData + (list->typeSize * list->size),
           element,
           list->typeSize);
    list->size++;

    if (list->size == list->capacity)
    {
        return arraylist_resize(list);
    }
    return true;
}

bool arraylist_addAt(ArrayList *list, void *element, size_t index)
{
    if (list == NULL || element == NULL)
    {
        return false;
    }
    if (index < 0 || list->size < index)
    {
        return false;
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
        return arraylist_resize(list);
    }
    return true;
}

static bool arraylist_resize(ArrayList *list)
{
    if (list->capacity <= 1024)
    {
        return arraylist_resizeList(list, 2.0);
    }
    else
    {
        return arraylist_resizeList(list, 1.3);
    }
}

static bool arraylist_resizeList(ArrayList *list, float factor)
{
    size_t newCapacity = (list->capacity) * factor;
    uint8_t *newData = malloc(newCapacity * list->typeSize);

    if (!newData)
    {
        return false;
    }

    uint8_t *oldData = (uint8_t *)list->data;

    memcpy(newData,
           oldData,
           list->size * list->typeSize);
    free(oldData);

    list->data = newData;
    list->capacity = newCapacity;

    return true;
}

void *arraylist_remove(ArrayList *list)
{
    if (list == NULL)
    {
        return NULL;
    }
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

void *arraylist_removeAt(ArrayList *list, size_t index)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (list->size == 0)
    {
        return NULL;
    }
    if (index < 0 || list->size <= index)
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

void *arraylist_get(ArrayList *list, size_t index)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (list->size == 0)
    {
        return NULL;
    }
    if (index < 0 || list->size <= index)
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

    return element;
}