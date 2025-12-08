#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/arraylist.h"

void test_arraylist_free();

void test_arraylist_creat_zeroTypeSize();
void test_arraylist_creat();

void test_arraylist_createInitSize_zeroInitialSize();
void test_arraylist_createInitSize_zeroTypeSize();
void test_arraylist_createInitSize();

void test_arraylist_size_NULL();
void test_arraylist_size();

void test_arraylist_add_listNULL();
void test_arraylist_add_elementNULL();
void test_arraylist_add();

void test_arraylist_isEmpty_NULL();
void test_arraylist_isEmpty_false();
void test_arraylist_isEmpty();

void test_arraylist_remove_listNULL();
void test_arraylist_remove();

void test_arraylist_get_listNULL();
void test_arraylist_get_negIndex();
void test_arraylist_get_sizeIndex();
void test_arraylist_get_zeroIndex();
void test_arraylist_get_endIndex();
void test_arraylist_get();

void test_arraylist_addAt_listNULL();
void test_arraylist_addAt_elementNULL();
void test_arraylist_addAt_negIndex();
void test_arraylist_addAt_maxIndex();
void test_arraylist_addAt_zeroIndex();
void test_arraylist_addAt_sizeIndex();
void test_arraylist_addAt();

void test_arraylist_removeAt_listNULL();
void test_arraylist_removeAt_negIndex();
void test_arraylist_removeAt_sizeIndex();
void test_arraylist_removeAt_zeroIndex();
void test_arraylist_removeAt_endIndex();
void test_arraylist_removeAt();

void test_arraylist_set_listNULL();
void test_arraylist_set_elementNULL();
void test_arraylist_set_negIndex();
void test_arraylist_set_sizeIndex();
void test_arraylist_set_zeroIndex();
void test_arraylist_set_endIndex();
void test_arraylist_set();

void test_arraylist_sort_listNULL();
void test_arraylist_sort_comparNULL();
void test_arraylist_sort();

int main()
{
    test_arraylist_free();

    test_arraylist_creat_zeroTypeSize();
    test_arraylist_creat();

    test_arraylist_createInitSize_zeroInitialSize();
    test_arraylist_createInitSize_zeroTypeSize();
    test_arraylist_createInitSize();

    test_arraylist_size_NULL();
    test_arraylist_size();

    test_arraylist_add_listNULL();
    test_arraylist_add_elementNULL();
    test_arraylist_add();

    test_arraylist_isEmpty_NULL();
    test_arraylist_isEmpty_false();
    test_arraylist_isEmpty();

    test_arraylist_remove_listNULL();
    test_arraylist_remove();

    test_arraylist_get_listNULL();
    test_arraylist_get_negIndex();
    test_arraylist_get_sizeIndex();
    test_arraylist_get_zeroIndex();
    test_arraylist_get_endIndex();
    test_arraylist_get();

    test_arraylist_addAt_listNULL();
    test_arraylist_addAt_elementNULL();
    test_arraylist_addAt_negIndex();
    test_arraylist_addAt_maxIndex();
    test_arraylist_addAt_zeroIndex();
    test_arraylist_addAt_sizeIndex();
    test_arraylist_addAt();

    test_arraylist_removeAt_listNULL();
    test_arraylist_removeAt_negIndex();
    test_arraylist_removeAt_sizeIndex();
    test_arraylist_removeAt_zeroIndex();
    test_arraylist_removeAt_endIndex();
    test_arraylist_removeAt();

    test_arraylist_set_listNULL();
    test_arraylist_set_elementNULL();
    test_arraylist_set_negIndex();
    test_arraylist_set_sizeIndex();
    test_arraylist_set_zeroIndex();
    test_arraylist_set_endIndex();
    test_arraylist_set();

    test_arraylist_sort_listNULL();
    test_arraylist_sort_comparNULL();
    test_arraylist_sort();

    exit(0);
}

void test_arraylist_free()
{
    ArrayList *listInt = arraylist_createInitSize(sizeof(int *), 3);
    if (listInt == NULL)
    {
        perror("test_arraylist_free(): NULL\n");
        exit(1);
    }
    arraylist_free(listInt);
}

void test_arraylist_creat_zeroTypeSize()
{
    ArrayList *listInt = arraylist_create(0);
    assert(listInt == NULL);
    arraylist_free(listInt);
}

void test_arraylist_creat()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_creat(): NULL\n");
        exit(1);
    }
    arraylist_free(listInt);
}

void test_arraylist_createInitSize_zeroInitialSize()
{
    ArrayList *listInt = arraylist_createInitSize(sizeof(int *), 0);
    assert(listInt == NULL);
    arraylist_free(listInt);
}

void test_arraylist_createInitSize_zeroTypeSize()
{
    ArrayList *listInt = arraylist_createInitSize(0, 4);
    assert(listInt == NULL);
    arraylist_free(listInt);
}

void test_arraylist_createInitSize()
{
    ArrayList *listInt = arraylist_createInitSize(sizeof(int *), 4);
    if (listInt == NULL)
    {
        perror("test_arraylist_createInitSize(): NULL\n");
        exit(1);
    }
    arraylist_free(listInt);
}

void test_arraylist_size_NULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_size(listInt) == -1);
}

void test_arraylist_size()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_size(): NULL\n");
        exit(1);
    }

    assert(arraylist_size(listInt) == 0);
    arraylist_free(listInt);
}

void test_arraylist_add_listNULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_add(listInt, 0) == false);
    assert(arraylist_size(listInt) == -1);
}

void test_arraylist_add_elementNULL()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_add_elementNULL(): NULL\n");
        exit(1);
    }

    assert(arraylist_add(listInt, NULL) == false);
    assert(arraylist_size(listInt) == 0);
    arraylist_free(listInt);
}

void test_arraylist_add()
{
    size_t tabSize = 100;

    ArrayList *listInt = arraylist_create(sizeof(int *));

    int *values = malloc(sizeof(int) * tabSize);
    if (listInt == NULL || values == NULL)
    {
        perror("test_arraylist_add(): NULL\n");
        exit(1);
    }
    size_t size = 0;

    for (size_t i = 0; i < tabSize; i++)
    {
        values[i] = i * 10;
        assert(arraylist_add(listInt, &(values[i])) == true);
        size++;
    }
    assert(arraylist_size(listInt) == size);

    for (size_t i = 0; i < tabSize; i++)
    {
        assert(*(int *)arraylist_get(listInt, i) == values[i]);
    }
    free(values);
    arraylist_free(listInt);
}

void test_arraylist_isEmpty_NULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_empty(listInt) == false);
}

void test_arraylist_isEmpty_false()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value = malloc(sizeof(int));
    if (listInt == NULL || value == NULL)
    {
        perror("test_arraylist_isEmpty_false(): NULL\n");
        exit(1);
    }
    assert(arraylist_add(listInt, value) == true);
    assert(arraylist_empty(listInt) == false);
}

void test_arraylist_isEmpty()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_isEmpty(): NULL\n");
        exit(1);
    }
    assert(arraylist_empty(listInt) == true);
}

void test_arraylist_remove_listNULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_remove(listInt) == NULL);
}

void test_arraylist_remove()
{
    size_t tabSize = 100;

    ArrayList *listInt = arraylist_create(sizeof(int *));

    int *values = malloc(sizeof(int) * tabSize);
    if (listInt == NULL || values == NULL)
    {
        perror("test_arraylist_remove(): NULL\n");
        exit(1);
    }
    size_t size = 0;

    for (size_t i = 0; i < tabSize; i++)
    {
        values[i] = i * 10;
        assert(arraylist_add(listInt, &(values[i])) == true);
        size++;
    }
    assert(arraylist_size(listInt) == size);

    for (size_t i = 0; i < tabSize; i++)
    {
        assert(*(int *)arraylist_get(listInt, i) == values[i]);
    }

    for (size_t i = 0; i < tabSize; i += 2)
    {
        arraylist_remove(listInt);
        size--;
    }
    assert(arraylist_size(listInt) == size);

    free(values);
    arraylist_free(listInt);
}

void test_arraylist_get_listNULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_get(listInt, 0) == NULL);
}

void test_arraylist_get_negIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value = malloc(sizeof(int));
    if (listInt == NULL || value == NULL)
    {
        perror("test_arraylist_get_negIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value = 42;

    assert(arraylist_add(listInt, value) == true);
    size++;
    assert(arraylist_size(listInt) == size);
    assert(arraylist_get(listInt, -1) == NULL);

    free(value);
    arraylist_free(listInt);
}

void test_arraylist_get_sizeIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value = malloc(sizeof(int));
    if (listInt == NULL || value == NULL)
    {
        perror("test_arraylist_get_sizeIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value = 42;

    assert(arraylist_add(listInt, value) == true);
    size++;
    assert(arraylist_size(listInt) == size);
    assert(arraylist_get(listInt, size) == NULL);

    free(value);
    arraylist_free(listInt);
}

void test_arraylist_get_zeroIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value = malloc(sizeof(int));
    if (listInt == NULL || value == NULL)
    {
        perror("test_arraylist_get_zeroIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value = 42;

    assert(arraylist_add(listInt, value) == true);
    size++;
    assert(arraylist_size(listInt) == size);
    assert(*(int *)arraylist_get(listInt, 0) == *value);

    free(value);
    arraylist_free(listInt);
}

void test_arraylist_get_endIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL)
    {
        perror("test_arraylist_get_endIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;

    assert(arraylist_add(listInt, value1) == true);
    size++;

    assert(arraylist_add(listInt, value2) == true);
    size++;

    assert(arraylist_size(listInt) == size);
    assert(*(int *)arraylist_get(listInt, size - 1) == *value2);

    free(value2);
    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_get()
{
    size_t tabSize = 100;

    ArrayList *listInt = arraylist_create(sizeof(int *));

    int *values = malloc(sizeof(int) * tabSize);
    if (listInt == NULL || values == NULL)
    {
        perror("test_arraylist_get(): NULL\n");
        exit(1);
    }
    size_t size = 0;

    for (size_t i = 0; i < tabSize; i++)
    {
        values[i] = i * 10;
        assert(arraylist_add(listInt, &(values[i])) == true);
        size++;
    }
    assert(arraylist_size(listInt) == size);

    for (size_t i = 0; i < tabSize; i++)
    {
        assert(*(int *)arraylist_get(listInt, i) == values[i]);
    }

    for (size_t i = 0; i < tabSize / 2; i++)
    {
        assert(*(int *)arraylist_remove(listInt) == values[i]);
        size--;
    }
    assert(arraylist_size(listInt) == size);

    free(values);
    arraylist_free(listInt);
}

void test_arraylist_addAt_listNULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_addAt(listInt, 0, 0) == false);
    assert(arraylist_size(listInt) == -1);
}

void test_arraylist_addAt_elementNULL()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_addAt_elementNULL(): NULL\n");
        exit(1);
    }

    assert(arraylist_addAt(listInt, NULL, 0) == false);
    assert(arraylist_size(listInt) == 0);
    arraylist_free(listInt);
}

void test_arraylist_addAt_negIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));

    if (listInt == NULL || value1 == NULL)
    {
        perror("test_arraylist_addAt_negIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;

    assert(arraylist_addAt(listInt, value1, -1) == false);
    assert(arraylist_size(listInt) == size);
    assert(arraylist_get(listInt, 0) == NULL);

    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_addAt_maxIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));

    if (listInt == NULL || value1 == NULL)
    {
        perror("test_arraylist_addAt_maxIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;

    assert(arraylist_addAt(listInt, value1, 9999) == false);
    assert(arraylist_size(listInt) == size);
    assert(arraylist_get(listInt, 0) == NULL);

    free(value1);
    arraylist_free(listInt);
}

void test_arraylist_addAt_zeroIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL)
    {
        perror("test_arraylist_addAt_zeroIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_size(listInt) == size);
    assert(*(int *)arraylist_get(listInt, 0) == *value1);

    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_addAt_sizeIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL)
    {
        perror("test_arraylist_addAt_sizeIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_addAt(listInt, value2, size) == true);
    size++;

    assert(arraylist_size(listInt) == size);
    assert(*(int *)arraylist_get(listInt, 0) == *value1);
    assert(*(int *)arraylist_get(listInt, 1) == *value2);

    free(value2);
    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_addAt()
{
    size_t tabSize = 100;

    ArrayList *listInt = arraylist_create(sizeof(int *));

    int *values = malloc(sizeof(int) * tabSize);
    if (listInt == NULL || values == NULL)
    {
        perror("test_arraylist_get(): NULL\n");
        exit(1);
    }
    size_t size = 0;

    for (size_t i = 0; i < tabSize; i++)
    {
        values[i] = i * 10;
        assert(arraylist_addAt(listInt, &(values[i]), size) == true);
        size++;
    }
    assert(arraylist_size(listInt) == size);

    for (size_t i = 0; i < tabSize; i++)
    {
        assert(*(int *)arraylist_get(listInt, i) == values[i]);
    }
    assert(arraylist_size(listInt) == size);

    free(values);
    arraylist_free(listInt);
}

void test_arraylist_removeAt_listNULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_removeAt(listInt, 0) == NULL);
}

void test_arraylist_removeAt_negIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL || value3 == NULL)
    {
        perror("test_arraylist_removeAt_negIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;
    *value3 = 25;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_addAt(listInt, value2, size) == true);
    size++;

    assert(arraylist_addAt(listInt, value3, 1) == true);
    size++;

    assert(arraylist_size(listInt) == size);
    assert(arraylist_removeAt(listInt, -1) == NULL);
    assert(arraylist_size(listInt) == size);

    free(value3);
    free(value2);
    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_removeAt_sizeIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL || value3 == NULL)
    {
        perror("test_arraylist_removeAt_sizeIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;
    *value3 = 25;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_addAt(listInt, value2, size) == true);
    size++;

    assert(arraylist_addAt(listInt, value3, 1) == true);
    size++;

    assert(arraylist_size(listInt) == size);
    assert(arraylist_removeAt(listInt, 9999) == NULL);
    assert(arraylist_size(listInt) == size);

    free(value3);
    free(value2);
    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_removeAt_zeroIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL || value3 == NULL)
    {
        perror("test_arraylist_removeAt_zeroIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;
    *value3 = 25;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_addAt(listInt, value2, size) == true);
    size++;

    assert(arraylist_addAt(listInt, value3, 1) == true);
    size++;

    assert(arraylist_size(listInt) == size);
    assert(*(int *)arraylist_removeAt(listInt, 0) == *value1);

    size--;
    assert(arraylist_size(listInt) == size);

    free(value3);
    free(value2);
    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_removeAt_endIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL || value3 == NULL)
    {
        perror("test_arraylist_removeAt_endIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;
    *value3 = 25;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_addAt(listInt, value2, size) == true);
    size++;

    assert(arraylist_addAt(listInt, value3, 1) == true);
    size++;

    assert(arraylist_size(listInt) == size);
    assert(*(int *)arraylist_removeAt(listInt, 0) == *value1);

    size--;
    assert(arraylist_size(listInt) == size);

    free(value3);
    free(value2);
    free(value1);

    arraylist_free(listInt);
}

void test_arraylist_removeAt()
{
    size_t tabSize = 100;

    ArrayList *listInt = arraylist_create(sizeof(int *));

    int *values = malloc(sizeof(int) * tabSize);
    if (listInt == NULL || values == NULL)
    {
        perror("test_arraylist_get(): NULL\n");
        exit(1);
    }
    size_t size = 0;

    for (size_t i = 0; i < tabSize; i++)
    {
        values[i] = i * 10;
        assert(arraylist_add(listInt, &(values[i])) == true);
        size++;
    }
    assert(arraylist_size(listInt) == size);

    for (size_t i = 0; i < tabSize; i++)
    {
        assert(*(int *)arraylist_get(listInt, i) == values[i]);
    }

    for (size_t i = 0; i < tabSize / 4; i++)
    {
        assert(*(int *)arraylist_removeAt(listInt, 0) == values[i]);
        size--;
    }
    assert(arraylist_size(listInt) == size);

    free(values);
    arraylist_free(listInt);
}

void test_arraylist_set_listNULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_set(listInt, 0, 0) == false);
}

void test_arraylist_set_elementNULL()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_set_elementNULL(): NULL\n");
        exit(1);
    }
    assert(arraylist_set(listInt, NULL, 0) == false);
    arraylist_free(listInt);
}

void test_arraylist_set_negIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL)
    {
        perror("test_arraylist_set_negIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_set(listInt, value2, -1) == false);
    assert(*(int *)arraylist_get(listInt, 0) == *value1);

    free(value1);
    free(value2);

    arraylist_free(listInt);
}

void test_arraylist_set_sizeIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL)
    {
        perror("test_arraylist_set_sizeIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_set(listInt, value2, size) == false);
    assert(*(int *)arraylist_get(listInt, 0) == *value1);

    free(value1);
    free(value2);

    arraylist_free(listInt);
}

void test_arraylist_set_zeroIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL)
    {
        perror("test_arraylist_set_zeroIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_set(listInt, value2, 0) == true);
    assert(*(int *)arraylist_get(listInt, 0) == *value2);

    free(value1);
    free(value2);

    arraylist_free(listInt);
}

void test_arraylist_set_endIndex()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    if (listInt == NULL || value1 == NULL || value2 == NULL)
    {
        perror("test_arraylist_set_endIndex(): NULL\n");
        exit(1);
    }
    size_t size = 0;
    *value1 = 42;
    *value2 = 10;

    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;
    assert(arraylist_addAt(listInt, value1, 0) == true);
    size++;

    assert(arraylist_set(listInt, value2, size - 1) == true);
    assert(*(int *)arraylist_get(listInt, size - 1) == *value2);

    free(value1);
    free(value2);

    arraylist_free(listInt);
}

void test_arraylist_set()
{
    size_t tabSize = 100;

    ArrayList *listInt = arraylist_create(sizeof(int *));

    int *values = malloc(sizeof(int) * tabSize);
    if (listInt == NULL || values == NULL)
    {
        perror("test_arraylist_set(): NULL\n");
        exit(1);
    }
    size_t size = 0;

    for (size_t i = 0; i < tabSize; i++)
    {
        values[i] = i;
        assert(arraylist_addAt(listInt, &(values[i]), size) == true);
        size++;
    }
    assert(arraylist_size(listInt) == size);

    for (size_t i = 0; i < tabSize; i++)
    {
        values[i] = i * 10;
        assert(arraylist_set(listInt, &(values[i]), i) == true);
    }
    assert(arraylist_size(listInt) == size);

    for (size_t i = 0; i < tabSize; i++)
    {
        assert(*(int *)arraylist_get(listInt, i) == values[i]);
    }
    assert(arraylist_size(listInt) == size);

    free(values);
    arraylist_free(listInt);
}

static int compare(const void *elt1, const void *elt2)
{
    int *i1 = (int *)elt1;
    int *i2 = (int *)elt2;

    return ((*i1) - (*i2));
}

void test_arraylist_sort_listNULL()
{
    ArrayList *listInt = NULL;
    assert(arraylist_sort(listInt, compare) == false);
}

void test_arraylist_sort_comparNULL()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_sort_comparNULL(): NULL\n");
        exit(1);
    }
    assert(arraylist_sort(listInt, NULL) == false);
    arraylist_free(listInt);
}

void test_arraylist_sort()
{
    ArrayList *listInt = arraylist_create(sizeof(int *));
    if (listInt == NULL)
    {
        perror("test_arraylist_sort_comparNULL(): NULL\n");
        exit(1);
    }
    assert(arraylist_sort(listInt, compare) == true);
    arraylist_free(listInt);
}