#pragma once

#include <stdlib.h>

#include "list_item.h"

typedef struct List {
	size_t size;
	size_t capacity;
	ListItem* arr;
} List;

List createList();

bool append(List*, ListItem);
bool insert(List*, size_t index, ListItem);

bool removeItem(List*, ListItem);
bool pop(List*, size_t index);
bool clear(List*);

bool set(List*, size_t index, ListItem);

size_t size(List);
bool isEmpty(List);

bool contains(List, ListItem);

void debugPrintList(List);