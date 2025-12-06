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



#endif // ARRAY_LIST_H