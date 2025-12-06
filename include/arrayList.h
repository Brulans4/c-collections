#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>
#include <stdint.h>

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
ArrayList *arraylist_create(int typeSize);

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
ArrayList *arraylist_createInitSize(int typeSize, int initialSize);

/**
 * @brief Returns the number of elements currently stored in the ArrayList.
 *
 * @param list Pointer to the ArrayList.
 * @return Number of elements in the list.
 */
size_t arraylist_size(const ArrayList *list);

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
 * @param list Pointer to the ArrayList.
 * @param element Pointer to the element to add. The function copies
 *        `typeSize` bytes from this pointer.
 *
 * @note The element pointer must refer to initialized memory and must not be NULL.
 * @note A reallocation may occur; all previously returned raw data pointers become invalid.
 */
void arraylist_Add(ArrayList *list, void *ellement);

#endif // ARRAY_LIST_H