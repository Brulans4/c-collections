#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Opaque structure representing a dynamic array (ArrayList).
 */
typedef struct ArrayList ArrayList;

/**
 * @brief Creates a new ArrayList for elements of a given size.
 *
 * Allocates memory for an ArrayList and initializes it with a default
 * initial capacity of 4. The elements will be stored as raw bytes
 * with each element of size `typeSize`.
 *
 * @ref For more details about the default initial capacity of 4 read docs/arrayList.md
 *
 * @param typeSize Size in bytes of a single element in the list.
 * @return Pointer to a newly created ArrayList, or NULL if memory allocation fails.
 */
ArrayList *arraylist_create(size_t typeSize);

/**
 * @brief Creates a new ArrayList for elements of a given size with a specified initial capacity.
 *
 * Allocates memory for an ArrayList and initializes it with the specified
 * initial capacity. The elements will be stored as raw bytes with each
 * element of size `typeSize`.
 *
 * @param typeSize Size in bytes of a single element in the list.
 * @param initialSize Initial capacity of the ArrayList.
 * @return Pointer to a newly created ArrayList, or NULL if memory allocation fails.
 */
ArrayList *arraylist_createInitSize(size_t typeSize, size_t initialSize);

/**
 * Frees all memory used by the ArrayList.
 *
 * This function frees both the internal data array and the ArrayList structure itself.
 * After calling this function, the pointer to the ArrayList becomes invalid and
 * should not be used.
 *
 * @param list Pointer to the ArrayList to be freed. If NULL, the function does nothing.
 */
void arraylist_free(ArrayList *list);

/**
 * @brief Returns the number of elements currently stored in the ArrayList.
 *
 * @param   list Pointer to the ArrayList.
 * @return  Number of elements in the list.
 */
size_t arraylist_size(const ArrayList *list);

/**
 * Checks whether the given ArrayList is empty.
 *
 * @param   list the ArrayList instance to check.
 * @return  true if the list is empty.
 *          false otherwise.
 */
bool arraylist_empty(const ArrayList *list);

/**
 * @brief Adds an element to the end of the ArrayList.
 *
 * Copies the bytes of the element pointed to by `element` into the internal
 * storage of the list. The element must have the same size as the type size
 * specified when the list was created.
 *
 * If the internal storage is full, the list automatically grows.
 * The resize strategy is:
 *  - double the capacity while it is <= 1024,
 *  - increase by a factor of 1.3 once capacity > 1024.
 *
 * @ref For more details about the resize strategy read docs/arrayList.md
 *
 * @param list      Pointer to the ArrayList.
 * @param element   Pointer to the element to add. The function copies
 *                  `typeSize` bytes from this pointer.
 *
 * @note The element pointer must refer to initialized memory and must not be NULL.
 * @note A reallocation may occur; all previously returned raw data pointers become invalid.
 */
bool arraylist_add(ArrayList *list, void *ellement);

/**
 * @brief Inserts an element into the ArrayList at the specified index.
 *
 * Shifts all elements from the given index onwards one position to the right
 * to make room for the new element. If the index is greater than or equal
 * to the current size of the list, the function does nothing.
 *
 * If the internal storage is full, the list automatically grows.
 * The resize strategy is:
 *  - double the capacity while it is <= 1024,
 *  - increase by a factor of 1.3 once capacity > 1024.
 *
 * @param list      Pointer to the ArrayList in which the element will be inserted.
 * @param element   Pointer to the element to be inserted. The element data is copied
 *                  into the list, so the original memory can be freed or reused
 *                  after the call.
 * @param index     Position at which the element should be inserted. Valid values
 *                  are 0 to list->size - 1. If index >= list->size, no insertion occurs.
 */
bool arraylist_addAt(ArrayList *list, void *element, size_t index);

/**
 * Removes and returns the first element of the ArrayList.
 *
 * Shifts all remaining elements one position to the left to fill the gap.
 * If the list is empty, the function returns NULL. The removed element is
 * copied into a newly allocated memory block, which the caller is responsible
 * for freeing.
 *
 * @param list  Pointer to the ArrayList from which the element will be removed.
 * @return      Pointer to a copy of the removed element, or NULL if the list is empty
 *              or memory allocation fails.
 */
void *arraylist_remove(ArrayList *list);

/**
 * Removes and returns the element at the specified index of the ArrayList.
 *
 * Shifts all subsequent elements one position to the left to fill the gap.
 * If the index is out of bounds or the list is empty, the function returns NULL.
 * The removed element is copied into a newly allocated memory block, which
 * the caller is responsible for freeing.
 *
 * @param list  Pointer to the ArrayList from which the element will be removed.
 * @param index Position of the element to remove. Valid values are 0 to list->size - 1.
 * @return      Pointer to a copy of the removed element, or NULL if the list is empty,
 *              the index is invalid, or memory allocation fails.
 */
void *arraylist_removeAt(ArrayList *list, size_t index);

/**
 * Returns a copy of the element at the specified index in the ArrayList.
 *
 * If the index is out of bounds or the list is empty, the function returns NULL.
 * The element is copied into a newly allocated memory block, so the caller is
 * responsible for freeing the returned memory.
 *
 * @param list  Pointer to the ArrayList from which to get the element.
 * @param index Position of the element to retrieve. Valid values are 0 to list->size - 1.
 * @return      Pointer to a copy of the element at the given index, or NULL if the list
 *              is empty, the index is invalid, or memory allocation fails.
 */
void *arraylist_get(ArrayList *list, size_t index);

#endif // ARRAY_LIST_H