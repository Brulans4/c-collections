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

/**
 * Inserts a boolean value at the specified index in the BoolArray.
 * All elements from the insertion index to the end of the array are shifted
 * one position to the right. The array automatically resizes if needed.
 *
 * @param bArray Pointer to the BoolArray.
 * @param value The boolean value to insert.
 * @param index The position at which the value should be inserted.
 *
 * @return true if the value was successfully inserted,
 *         false if bArray is NULL, index is out of bounds,
 *         memory allocation for shifting fails, or resize fails.
 */
bool boolarray_addAt(BoolArray *bArray, bool value, size_t index);

bool *boolarray_remove(BoolArray *bArray);

bool *boolarray_removeAt(BoolArray *bArray, size_t index);

/**
 * Retrieves the boolean value stored at the specified index.
 *
 * @param bArray Pointer to the BoolArray.
 * @param index The index of the element to retrieve.
 *
 * @return A pointer to a dynamically allocated boolean
 *         containing the value at the specified index,
 *         or NULL if bArray is NULL, index is out of range,
 *         or memory allocation fails.
 *
 * @warning The returned pointer MUST be freed by the caller.
 */
bool *boolarray_get(BoolArray *bArray, size_t index);

/**
 * Sets the boolean value at the specified index in the BoolArray.
 *
 * @param bArray Pointer to the BoolArray. Must not be NULL.
 * @param index The index to modify (0 <= index < size).
 * @param value The boolean value to store.
 *
 * @return true if the value was successfully stored,
 *         false if bArray is NULL or index is out of bounds.
 *
 * @note Updates only one bit inside the correct byte.
 */
bool boolarray_set(BoolArray *bArray, size_t index, bool value);

void boolarray_flip(BoolArray *bArray, size_t index);

#endif // BOOL_ARRAY_H