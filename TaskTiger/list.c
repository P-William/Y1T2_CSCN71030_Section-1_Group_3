
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "string_utils.h"

#define INITAL_CAPACITY 10
#define CAPACITY_STEP 5

/**
* Realloc wrapper that returns a pointer to the original list of reallocation fails.
* @param arr pointer to the array to be resized
* @param newCapacity capacity of the new array
* 
* @return bool value of if the reallocation was successful or not
* @return returns a pointer to the new array if successful, otherwise returns the original array to prevent data loss
*/
bool realloc_s(Task* arr, size_t newCapacity) {
	Task* newArr = (Task*)realloc(arr, newCapacity);
	if (newArr == NULL) {
		fprintf(stderr, "Failed to realloc\n");
		return false;
	}
	arr = newArr;
	return true;
}

bool stepArraySize(List* list) {
	size_t newCapacity = (list->capacity + CAPACITY_STEP) * sizeof(Task);
	bool updatedArr = realloc_s(list->arr, newCapacity);
	if (!updatedArr) {
		fprintf(stderr, "Failed to append item due to reallocation failure\n");
		return false;
	}
	list->capacity = newCapacity;
	
	return true;
}

bool resizeArray(List* list, size_t newCapacity) {
	size_t newCap = newCapacity * sizeof(Task);
	bool updatedArr = realloc_s(list->arr, newCap);
	if (!updatedArr) {
		fprintf(stderr, "Failed to append item due to reallocation failure\n");
		return false;
	}
	list->capacity = newCap;

	return true;
}

List* createList() {
	List* list = (List*)malloc(sizeof(List));
	if (list == NULL) {
		fprintf(stderr, "Failed to allocate memory\n");
		return NULL;
	}

	list->arr = (Task*)malloc(sizeof(Task) * INITAL_CAPACITY);
	if (list->arr == NULL) {
		fprintf(stderr, "Failed to allocate memory for array\n");
		return NULL;
	}

	list->size = 0;
	list->capacity = INITAL_CAPACITY;

	return list;
}

List* copyList(const List* list) {
	List* newList = createList();
	if (newList == NULL) {
		return NULL;
	}

	bool resized = resizeArray(newList, list->capacity);
	if (!resized) {
		fprintf(stderr, "Failed to resize list\n");
		return NULL;
	}

	newList->size = list->size;

	for (size_t i = 0; i < list->size; i++) {
		newList->arr[i] = copyTask(list->arr[i]);
	}

	return newList;
}

bool equalList(const List* listOne, const List* listTwo) {
	if (listOne == NULL || listTwo == NULL) {
		fprintf(stderr, "Cannot check null list for equality\n");
		return false;
	}

	if (listOne->size != listTwo->size) {
		return false;
	}
	if (listOne->capacity != listTwo->capacity) {
		return false;
	}

	for (size_t i = 0; i < listOne->size; i++) {
		bool isEqual = equalTask(listOne->arr[i], listTwo->arr[i]);
		if (!isEqual) {
			return false;
		}
	}

	return true;
}

bool append(List* list, Task task) {
	if (list == NULL) {
		fprintf(stderr, "Cannot append to NULL list\n");
		return false;
	}

	if (list->size == list->capacity) {
		bool resized = stepArraySize(list);
		if (!resized) {
			return false;
		}
	}

	list->arr[list->size++] = copyTask(task);
	return true;
}
bool insert(List* list, size_t index, Task task) {
	if (list == NULL) {
		fprintf(stderr, "Cannot insert to NULL list\n");
		return false;
	}
	if (index > list->size) {
		fprintf(stderr, "Cannot insert beyond current size\n");
		return false;
	}

	if (list->size == list->capacity) {
		bool resized = stepArraySize(list);
		if (!resized) {
			return false;
		}
	}

	for (size_t i = list->size; i > index; i--) {
		list->arr[i] = list->arr[i - 1];
	}

	list->arr[index] = task;
	list->size++;
	return true;
}

bool removeTask(List* list, Task task) {
	if (list == NULL) {
		fprintf(stderr, "Cannot set null list. Create a list using createList\n");
		return false;
	}

	for (size_t i = 0; i < list->size; i++) {
		bool match = equalTask(list->arr[i], task);
		if (match) {
			for (size_t j = i; j < (list->size - 1); j++) {
				list->arr[j] = list->arr[j + 1];
			}

			list->size--;
			return true;
		}
	}
	return false;
}
bool pop(List* list, size_t index) {
	if (list == NULL) {
		fprintf(stderr, "Cannot set null list. Create a list using createList\n");
		return false;
	}
	if (index > list->size) {
		fprintf(stderr, "Cannot set beyond current size\n");
		return false;
	}

	for (size_t i = index; i < (list->size - 1); i++) {
		list->arr[i] = list->arr[i + 1];
	}
	list->size--;

	return true;
}
bool clear(List* list) {
	if (list == NULL) {
		fprintf(stderr, "Cannot set null list. Create a list using createList\n");
		return false;
	}
	free(list->arr);
	free(list);
	list = createList();
	if (list == NULL) {
		return false;
	}
	return true;
}

bool set(List* list, size_t index, Task task) {
	if (list == NULL) {
		fprintf(stderr, "Cannot set null list. Create a list using createList\n");
		return false;
	}
	if (index > list->size) {
		fprintf(stderr, "Cannot set beyond current size\n");
		return false;
	}

	list->arr[index] = task;
	return true;
}

size_t size(const List* list) {
	if (list == NULL) {
		fprintf(stderr, "Cannot get size of null list\n");
		return 0;
	}
	return list->size;
}
bool isEmpty(const List* list) {
	if (list == NULL) {
		fprintf(stderr, "Cannot get size of null list\n");
		return false;
	}
	return (list->size == 0);
}

bool contains(const List* list, Task task) {
	if (list == NULL) {
		fprintf(stderr, "Cannot check null list\n");
		return false;
	}
	for (size_t i = 0; i < list->size; i++) {
		bool match = equalTask(list->arr[i], task);
		if (match) {
			return true;
		}
	}
	return false;
}


List* filterByTitle(const List* list, const char* title) {
	if (list == NULL) {
		fprintf(stderr, "Cannot filter null list\n");
		return NULL;
	}

	List* filteredList = createList();
	if (filteredList == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < list->size; i++) {
		if (stringCompare(list->arr[i].title, title)) {
			append(filteredList, list->arr[i]);
		}
	}

	return filteredList;
}

List* filterByStatus(const List* list, Status status) {
	if (list == NULL) {
		fprintf(stderr, "Cannot filter null list\n");
		return NULL;
	}

	List* filteredList = createList();
	if (filteredList == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < list->size; i++) {
		if (list->arr[i].status == status) {
			append(filteredList, list->arr[i]);
		}
	}

	return filteredList;
}
List* filterByPriority(const List* list, Priority priority) {
	printPriority(priority, true);
	if (list == NULL) {
		fprintf(stderr, "Cannot filter null list\n");
		return NULL;
	}

	List* filteredList = createList();
	if (filteredList == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < list->size; i++) {
		if (list->arr[i].priority == priority) {
			append(filteredList, list->arr[i]);
		}
	}

	return filteredList;
}

int compareTasksByTitle(const void* a, const void* b) {
	const Task* taskA = (const Task*)a;
	const Task* taskB = (const Task*)b;
	return strcmp(taskA->title, taskB->title);
}

int compareTasksByStatus(const void* a, const void* b) {
	const Task* taskA = (const Task*)a;
	const Task* taskB = (const Task*)b;
	return (taskA->status - taskB->status);
}

int compareTasksByPriority(const void* a, const void* b) {
	const Task* taskA = (const Task*)a;
	const Task* taskB = (const Task*)b;
	return (taskA->priority - taskB->priority);
}

int compareTasksByTitleDescending(const void* a, const void* b) {
	const Task* taskA = (const Task*)a;
	const Task* taskB = (const Task*)b;
	return strcmp(taskB->title, taskA->title);
}

int compareTasksByStatusDescending(const void* a, const void* b) {
	const Task* taskA = (const Task*)a;
	const Task* taskB = (const Task*)b;
	return (taskB->status - taskA->status);
}

int compareTasksByPriorityDescending(const void* a, const void* b) {
	const Task* taskA = (const Task*)a;
	const Task* taskB = (const Task*)b;
	return (taskB->priority - taskA->priority);
}

bool sortList(List* list, SortKey key, SortOrder order) {
	if (list == NULL) {
		fprintf(stderr, "Cannot sort null list\n");
		return false;
	}

	switch (key) {
	case TITLE:
		if (order == ASCENDING) {
			qsort(list->arr, list->size, sizeof(Task), compareTasksByTitle);
			break;
		}

		qsort(list->arr, list->size, sizeof(Task), compareTasksByTitleDescending);
		break;
	case STATUS:
		if (order == ASCENDING) {
			qsort(list->arr, list->size, sizeof(Task), compareTasksByStatus);
			break;
		}

		qsort(list->arr, list->size, sizeof(Task), compareTasksByStatusDescending);
		break;
	case PRIORITY:
		if (order == ASCENDING) {
			qsort(list->arr, list->size, sizeof(Task), compareTasksByPriority);
			break;
		}

		qsort(list->arr, list->size, sizeof(Task), compareTasksByPriorityDescending);
		break;
	default:
		break;
	}

	return true;
}

void destroyList(List* list) {
	free(list->arr);
}

void debugPrintList(const List* list) {
	for (int i = 0; i < list->size; i++) {
		debugPrintTask(list->arr[i]);
	}
}