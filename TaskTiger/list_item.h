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

/**
 * Creates a ListItem from a Task.
 * @param task The Task to create the ListItem from.
 * @return The created ListItem.
 */
ListItem createListItemFromTask(Task);
/**
 * Creates a ListItem from a Folder.
 * @param folder The Folder to create the ListItem from.
 * @return The created ListItem.
 */
ListItem createListItemFromFolder(Folder);

/**
 * Checks if two ListItems are equal.
 * @param item1 The first ListItem.
 * @param item2 The second ListItem.
 * @return True if the ListItems are equal, false otherwise.
 */
bool equalListItem(ListItem, ListItem);

/**
 * Copies a ListItem.
 * @param src The source ListItem to copy.
 * @return The copied ListItem.
 */
ListItem copyListItem(ListItem src);
/**
 * Copies a ListItem in place.
 * @param dest Pointer to the destination ListItem.
 * @param src The source ListItem to copy.
 * @return True if the copy was successful, false otherwise.
 */
bool copyListItemInPlace(ListItem* dest, ListItem src);

void debugPrintListItem(ListItem);