
#include <stdio.h>
#include <stdlib.h>

#include "list_item.h"



ListItem createListItemFromTask(Task task) {
	ListItem newItem;
	newItem.type = TASK;
	newItem.item.task = copyTask(task);
	return newItem;
}
ListItem createListItemFromFolder(Folder folder) {
	ListItem newItem;
	newItem.type = FOLDER;
	newItem.item.folder = copyFolder(folder);
	return newItem;
}

bool equalListItem(ListItem item1, ListItem item2) {
	if (item1.type != item2.type) {
		return false;
	}

	if (item1.type == FOLDER) {
		return equalFolder(item1.item.folder, item2.item.folder);
	}
	if (item2.type == TASK) {
		return equalTask(item1.item.task, item2.item.task);
	}
	return false;
}

#pragma warning(disable: 6001)
ListItem copyListItem(ListItem src) {
	if (src.type == NONE) {
		fprintf(stderr, "Cannot copy list item of type NONE\n");
		exit(-1);
	}

	ListItem newItem;

	if (src.type == TASK) {
		newItem.type = TASK;
		newItem.item.task = copyTask(src.item.task);
	}
	else if (src.type == FOLDER) {
		newItem.type = FOLDER;
		newItem.item.folder = copyFolder(src.item.folder);
	}
	return newItem;
}
#pragma warning(default: 6001)
bool copyListItemInPlace(ListItem* dest, ListItem src) {
	if (src.type == NONE) {
		fprintf(stderr, "Cannot copy list item of type NONE\n");
		return false;
	}

	if (src.type == TASK) {
		dest->type = src.type;
		copyTaskInPlace(&dest->item.task, src.item.task);
	}
	else if (src.type == FOLDER) {
		dest->type = src.type;
		copyFolderInPlace(&dest->item.folder, src.item.folder);
	}
	return true;
}

void debugPrintListItem(ListItem item) {
	if (item.type == NONE) {
		fprintf(stderr, "Cannot print list item of type NONE\n");
		return;
	}

	if (item.type == TASK) {
		debugPrintTask(item.item.task);
	}
	else if (item.type == FOLDER) {
		debugPrintFolder(item.item.folder);
	}
}