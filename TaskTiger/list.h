#pragma once

#include <stdlib.h>

#include "list_item.h"

/**
 * Function pointer type for defining filter functions.
 *
 * The filter function should take a pointer to a ListItem and return a boolean value.
 * If the function returns true, the item is considered a match; otherwise, it's not included.
 */
typedef bool (*FilterFunction)(const ListItem*);

typedef enum SortOrder {
	FOLDER_FIRST,
	TASK_FIRST
} SortOrder;

typedef enum SortKey {
	TITLE,
	STATUS,
	PRIORITY,
	DATE
} SortKey;

typedef struct List {
	size_t size;
	size_t capacity;
	ListItem* arr;
} List;

/**
 * Creates and initializes a new list.
 *
 * Allocates memory for a new List structure and its array of ListItems.
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
  * Compares two lists by checking their size, capacity, and the equality of each element.
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
 * @param item The item to be appended.
 * @return true if successful, false otherwise.
 */
bool append(List*, ListItem);
/**
 * Inserts an element at the specified index in the list.
 *
 * @param list Pointer to the list structure.
 * @param index Index at which the element should be inserted.
 * @param item The item to be inserted.
 * @return true if successful, false otherwise.
 */
bool insert(List*, size_t index, ListItem);

/**
 * Removes the first occurrence of the specified item from the list.
 *
 * @param list Pointer to the list structure.
 * @param item The item to be removed.
 * @return true if the item was found and removed, false otherwise.
 */
bool removeItem(List*, ListItem);
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
 * @param item The item to be set.
 * @return true if successful, false otherwise.
 */
bool set(List*, size_t index, ListItem);

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
 * Checks if the list contains the specified item.
 *
 * @param list The list.
 * @param item The item to be checked.
 * @return true if the item is found, false otherwise.
 * @return Also returns false if the list is NULL.
 */
bool contains(const List*, ListItem);


bool sortList(List*, SortOrder, SortKey);
List* sortListCopy(const List*, SortOrder, SortKey);

 /**
  * Filters a list based on a given filter function.
  *
  * Creates a new list containing only the items from the original list that match the
  * provided filter function.
  *
  * @param list Pointer to the original list to be filtered.
  * @param filter A filter function determining whether an item should be included.
  * @return A pointer to a new list containing only the items that match the filter function,
  *         or NULL if memory allocation fails or the input list is NULL.
  */
List* filterList(const List*, FilterFunction filter);

void debugPrintList(const List*);