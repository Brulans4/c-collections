#ifndef BOOL_ARRAY_H
#define BOOL_ARRAY_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct BoolArray;

/**
 * Creates a new empty BoolArray.
 *
 * @return A pointer to a newly allocated BoolArray, or NULL if memory allocation fails.
 */
BoolArray *boolarray_create();

/**
 * Frees all memory associated with the given BoolArray.
 * After this function is called, the pointer becomes invalid.
 *
 * @param bArray Pointer to the BoolArray to free. If NULL, the function does nothing.
 */
void boolarray_free(BoolArray *bArray);


/**
 * Returns the current number of elements in the BoolArray.
 *
 * @param bArray Pointer to the BoolArray.
 * @return The number of elements in the array, or -1 if bArray is NULL.
 */
size_t boolarray_size(const BoolArray *bArray);

/**
 * Checks if the BoolArray is empty.
 *
 * @param bArray Pointer to the BoolArray.
 * @return true if the array has no elements, false otherwise.
 */
bool boolarray_isEmpty(const BoolArray *bArray);

/**
 * Adds a boolean value to the end of the BoolArray.
 * The array automatically resizes its internal storage if needed.
 *
 * Each boolean is stored as a single bit within the underlying uint8_t array
 * to optimize memory usage.
 *
 * @param bArray Pointer to the BoolArray. Must not be NULL.
 * @param value The boolean value to add (true or false).
 * @return true if the value was successfully added, false if bArray is NULL
 *         or if resizing fails.
 *
 * @note Internally, each boolean is stored in a single bit. When the number of elements
 *       reaches the current capacity, the array is resized by calling `boolarray_resizeList`.
 *       This may involve allocating more memory, which can fail.
 */
bool boolarray_add(BoolArray *bArray, bool value);

bool boolarray_addAt(BoolArray *bArray, bool value, size_t index);

bool *boolarray_remove(BoolArray *bArray);

bool *boolarray_removeAt(BoolArray *bArray, size_t index);

bool *boolarray_get(BoolArray *bArray, size_t index);

bool boolarray_set(BoolArray *bArray, size_t index);

void boolarray_flip(BoolArray *bArray, size_t index);

#endif // BOOL_ARRAY_H