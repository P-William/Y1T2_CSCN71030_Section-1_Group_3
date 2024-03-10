
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

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
bool realloc_s(ListItem** arr, size_t newCapacity) {
	ListItem* newArr = (ListItem*)realloc(arr, newCapacity);
	if (newArr == NULL) {
		fprintf(stderr, "Failed to realloc\n");
		return false;
	}
	*arr = newArr;
	return true;
}

bool stepArraySize(List* list) {
	size_t newCapacity = (list->capacity + CAPACITY_STEP) * sizeof(ListItem);
	bool updatedArr = realloc_s(list->arr, newCapacity);
	if (!updatedArr) {
		fprintf(stderr, "Failed to append item due to reallocation failure\n");
		return false;
	}
	list->capacity = newCapacity;
	
	return true;
}

bool resizeArray(List* list, size_t newCapacity) {
	size_t newCap = newCapacity * sizeof(ListItem);
	bool updatedArr = realloc_s(list->arr, newCap);
	if (!updatedArr) {
		fprintf(stderr, "Failed to append item due to reallocation failure\n");
		return false;
	}
	list->capacity = newCap;

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

List copyList(const List list) {
	List newList = createList();
	bool resized = resizeArray(&newList, list.capacity);
	if (!resized) {
		fprintf(stderr, "Failed to resize list\n");
		exit(-1);
	}
	newList.size = list.size;
	for (size_t i = 0; i < (list.size - 1); i++) {
		newList.arr[i] = copyListItem(list.arr[i]);
	}

	return newList;
}

bool equalList(const List listOne, const List listTwo) {
	if (listOne.size != listTwo.size) {
		return false;
	}
	if (listOne.capacity != listTwo.capacity) {
		return false;
	}

	for (size_t i = 0; i < (listOne.size - 1); i++) {
		bool isEqual = equalListItem(listOne.arr[i], listTwo.arr[i]);
		if (!isEqual) {
			return false;
		}
	}
	return true;
}

bool append(List* list, ListItem item) {
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

	list->arr[list->size++] = copyListItem(item);
	return true;
}
bool insert(List* list, size_t index, ListItem item) {
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

	list->arr[index] = item;
	list->size++;
	return true;
}

bool removeItem(List* list, ListItem item) {
	if (list == NULL) {
		fprintf(stderr, "Cannot set null list. Create a list using createList\n");
		return false;
	}

	for (size_t i = 0; i < list->size; i++) {
		bool match = equalListItem(list->arr[i], item);
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
	*list = createList();
	return true;
}

bool set(List* list, size_t index, ListItem item) {
	if (list == NULL) {
		fprintf(stderr, "Cannot set null list. Create a list using createList\n");
		return false;
	}
	if (index > list->size) {
		fprintf(stderr, "Cannot set beyond current size\n");
		return false;
	}

	list->arr[index] = item;
	return true;
}

size_t size(List list) {
	return list.size;
}
bool isEmpty(List list) {
	return (list.size == 0);
}

bool contains(List list, ListItem item) {
	for (size_t i = 0; i < list.size; i++) {
		bool match = equalListItem(list.arr[i], item);
		if (match) {
			return true;
		}
	}
	return false;
}

bool sortList(List* list, SortOrder order, SortKey key) {

}

List filterList(const List* list, FilterFunction filter) {
	List filteredList = createList();

	for (size_t i = 0; i < list->size; i++) {
		bool match = filter(&filteredList, list->arr[i]);
		if (match) {
			append(&filteredList, list->arr[i]);
		}
	}

	return filteredList;
}

void debugPrintList(List list) {
	for (int i = 0; i < list.size; i++) {
		debugPrintListItem(list.arr[i]);
	}
}