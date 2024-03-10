#pragma once

#include <stdlib.h>

#include "list_item.h"

typedef struct List {
	size_t size;
	size_t capacity;
	ListItem* arr;
} List;

/**
 * Creates and initializes a new list.
 *
 * @return A newly created list.
 */
List createList();

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
 */
size_t size(List);
/**
 * Checks if the list is empty.
 *
 * @param list The list.
 * @return true if the list is empty, false otherwise.
 */
bool isEmpty(List);

/**
 * Checks if the list contains the specified item.
 *
 * @param list The list.
 * @param item The item to be checked.
 * @return true if the item is found, false otherwise.
 */
bool contains(List, ListItem);


void debugPrintList(List);