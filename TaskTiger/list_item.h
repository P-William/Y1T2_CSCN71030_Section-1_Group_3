#pragma once

#include "task.h"
#include "folder.h"

typedef enum Type {
	NONE,
	TASK,
	FOLDER
} Type;

typedef union Item {
	Task task;
	Folder folder;
} Item;

typedef struct ListItem {
	Type type;
	Item item;
} ListItem;


ListItem createListItemFromTask(Task);
ListItem createListItemFromFolder(Folder);

bool equalListItem(ListItem, ListItem);

ListItem copyListItem(ListItem src);
bool copyListItemInPlace(ListItem* dest, ListItem src);

void debugPrintListItem(ListItem);