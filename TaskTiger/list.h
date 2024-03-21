#pragma once

#include <stdlib.h>

#include "task.h"



typedef enum SortKey {
	TITLE,
	STATUS,
	PRIORITY,
	DATE
} SortKey;

typedef struct List {
	size_t size;
	size_t capacity;
	Task* arr;
} List;

/**
 * Creates and initializes a new list.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation fails.
 */
List* createList();

 /**
  * Creates a copy of the provided list.
  *
  * Allocates memory for a new List structure and copies the content from the source list to the new list.
  *
  * @param list The source list to be copied.
  * @return A pointer to the new list containing the same elements as the source list,
  *         or NULL if memory allocation fails.
  */
List* copyList(const List*);

 /**
  * Checks if two lists are equal in size, capacity, and element values.
  *
  * @param listOne The first list for comparison.
  * @param listTwo The second list for comparison.
  * @return true if the lists are equal, false otherwise. 
  */
bool equalList(const List*, const List*);

/**
 * Appends an element to the end of the list.
 *
 * @param list Pointer to the list structure.
 * @param task The task to be appended.
 * @return true if successful, false otherwise.
 */
bool append(List*, Task);
/**
 * Inserts an element at the specified index in the list.
 *
 * @param list Pointer to the list structure.
 * @param index Index at which the element should be inserted.
 * @param task The task to be inserted.
 * @return true if successful, false otherwise.
 */
bool insert(List*, size_t index, Task);

/**
 * Removes the first occurrence of the specified task from the list.
 *
 * @param list Pointer to the list structure.
 * @param task The task to be removed.
 * @return true if the task was found and removed, false otherwise.
 */
bool removeTask(List*, Task);
/**
 * Removes the element at the specified index from the list.
 *
 * @param list Pointer to the list structure.
 * @param index Index of the element to be removed.
 * @return true if successful, false otherwise.
 */
bool pop(List*, size_t index);
/**
 * Clears the contents of the list.
 *
 * @param list Pointer to the list structure.
 * @return true if successful, false otherwise.
 */
bool clear(List*);

/**
 * Sets the element at the specified index in the list.
 *
 * @param list Pointer to the list structure.
 * @param index Index at which the element should be set.
 * @param task The task to be set.
 * @return true if successful, false otherwise.
 */
bool set(List*, size_t index, Task);

/**
 * Returns the number of elements in the list.
 *
 * @param list The list.
 * @return The number of elements in the list. 
 * @return Returns 0 if the list is NULL.
 */
size_t size(const List*);
/**
 * Checks if the list is empty.
 *
 * @param list The list.
 * @return true if the list is empty, false otherwise. 
 * @return Also returns false if the list is NULL.
 */
bool isEmpty(const List*);

/**
 * Checks if the list contains the specified task.
 *
 * @param list The list.
 * @param task The task to be checked.
 * @return true if the task is found, false otherwise.
 * @return Also returns false if the list is NULL.
 */
bool contains(const List*, Task);

void debugPrintList(const List*);