#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "task.h"

typedef enum SortOrder {
	ASCENDING,
	DESCENDING
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
	Task* arr;
} List;

/**
 * Creates and initializes a new list.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation fails.
 * @note The caller is responsible for calling destroyList
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
  * @note The caller is responsible for calling destroyList
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

/**
 * Filter a list of tasks by title.
 *
 * @param list Pointer to the list of tasks to filter.
 * @param title The title to filter by.
 * @return A new list containing tasks with titles matching the provided title. NULL if the input list is NULL or memory allocation fails.
 * @note The caller is responsible for calling destroyList
 */
List* filterByTitle(const List*, const char* title);
/**
 * Filter a list of tasks by status.
 *
 * @param list Pointer to the list of tasks to filter.
 * @param status The status to filter by.
 * @return A new list containing tasks with status matching the provided status. NULL if the input list is NULL or memory allocation fails.
 * @note The caller is responsible for calling destroyList
 */
List* filterByStatus(const List*, Status);
/**
 * Filter a list of tasks by priority.
 *
 * @param list Pointer to the list of tasks to filter.
 * @param priority The priority to filter by.
 * @return A new list containing tasks with priority matching the provided priority. NULL if the input list is NULL or memory allocation fails.
 * @note The caller is responsible for calling destroyList
 */
List* filterByPriority(const List*, Priority);

/**
 * Filters a list of items by a specific date.
 * @param list Pointer to the list to be filtered.
 * @param date The date to filter by.
 * @return A new list containing only the items from the original list
 *         that have the specified date. Returns NULL if the input list is NULL
 *         or if memory allocation fails.
 * @note The caller is responsible for calling destroyList
 */
List* filterByDate(const List*, Date);

/**
 * Filters a list of items by the number of days remaining until their date.
 * @param list Pointer to the list to be filtered.
 * @param daysRemaining The maximum number of days remaining.
 * @return A new list containing only the items from the original list
 *         that have a date within the specified number of days remaining.
 *         Returns NULL if the input list is NULL or if memory allocation fails.
 * @note The caller is responsible for calling destroyList
 */
List* filterByDateTimeRemaining(const List*, int daysRemaining);

/**
 * Sorts a list of tasks by a specified key in the specified order.
 *
 * @param list Pointer to the list of tasks to sort.
 * @param key The key by which to sort the tasks (TITLE, STATUS, PRIORITY, DATE).
 * @param order The order in which to sort the tasks (ASCENDING or DESCENDING).
 * @return true if sorting is successful, false if an error occured
 */
bool sortList(List*, SortKey, SortOrder);

/**
 * Destroys a list, freeing the memory and rendering it unusable
 * @param list to destroy 
*/
void destroyList(List*);

/**
 * Saves a list of tasks to a file.
 *
 * @param fp Pointer to the FILE object to write to.
 * @param list Pointer to the List structure to be saved.
 * @return True if the task list was successfully saved, false otherwise.
 */
bool saveList(FILE* fp, const List*);
/**
 * Loads a list of tasks from a file.
 *
 * @param fp Pointer to the FILE object to read from.
 * @return Pointer to the List structure loaded from the file.
 */
List* loadList(FILE* fp);

void debugPrintList(const List*);