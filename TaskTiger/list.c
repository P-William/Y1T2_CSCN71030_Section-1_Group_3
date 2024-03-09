
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define INITAL_CAPACITY 10
#define CAPACITY_STEP 5

/**
* Realloc wrapper that returns a pointer to the original list of reallocation fails.
* @param arr pointer to the array to be resized
* @param newSize size of the new array
* 
* @return returns a pointer to the new array if successful, otherwise returns the original array
*/
bool realloc_s(ListItem** arr, size_t newSize) {
	ListItem* newArr = (ListItem*)realloc(arr, newSize);
	if (newArr == NULL) {
		fprintf(stderr, "Failed to realloc\n");
		return false;
	}
	*arr = newArr;
	return true;
}

bool resizeArray(List* list) {
	size_t newSize = (list->capacity + CAPACITY_STEP) * sizeof(ListItem);
	bool updatedArr = realloc_s(list->arr, newSize);
	if (!updatedArr) {
		fprintf(stderr, "Failed to append item due to reallocation failure\n");
		return false;
	}
	list->capacity = newSize;
	
	return true;
}

List createList() {
	List list;
	list.arr = (ListItem*)malloc(sizeof(ListItem) * INITAL_CAPACITY);
	if (list.arr == NULL) {
		fprintf(stderr, "Failed to allocate memory\n");
		exit(-1);
	}
	list.size = 0;
	list.capacity = INITAL_CAPACITY;
	return list;
}

bool append(List* list, ListItem item) {
	if (list == NULL) {
		fprintf(stderr, "Cannot append to NULL list\n");
		return false;
	}

	if (list->size == list->capacity) {
		bool resized = resizeArray(list);
		if (!resized) {
			return false;
		}
	}

	list->arr[list->size++] = copyListItem(item);
	return true;
}
bool insert(List* list, size_t index, ListItem item) {
	if (index > list->size) {
		fprintf(stderr, "Cannot insert beyond current size\n");
		return false;
	}

	if (list->size == list->capacity) {
		bool resized = resizeArray(list);
		if (!resized) {
			return false;
		}
	}

	for (int i = list->size; i > index; i--) {
		list->arr[i] = list->arr[i - 1];
	}

	list->arr[index] = item;
	list->size++;
	return true;
}

bool removeItem(List* list, ListItem item) {

}
bool pop(List* list, size_t index) {

}
bool clear(List* list) {

}

bool set(List* list, size_t index, ListItem item) {

}

size_t size(List list) {
	return list.size;
}
bool isEmpty(List list) {
	return (list.size == 0);
}

bool contains(List list, ListItem item) {
	for (int i = 0; i < (list.size - 1); i++) {
		bool match = equalListItem(list.arr[i], item);
		if (match) {
			return true;
		}
	}
	return false;
}

void debugPrintList(List list) {
	for (int i = 0; i < (list.size - 1); i++) {
		debugPrintListItem(list.arr[i]);
	}
}