#pragma once

#include <stdbool.h>

#include "folder.h"

typedef struct FolderNode {
	Folder folder;
	struct FolderNode* next;
} FolderNode, * pFolderNode;

typedef struct FolderList {
	FolderNode* head;
} FolderList;

/**
 * Creates an empty folder list.
 * @return Empty FolderList.
 * @note Caller is responsible for calling destroyFolderList
 */
FolderList createFolderList();

/**
 * Copies a folder list.
 * @param src The source folder list to copy.
 * @return Copied FolderList.
 * @note Caller is responsible for calling destroyFolderList
 */
FolderList copyFolderList(FolderList src);

/**
 * Checks if a folder list is empty.
 * @param list The folder list to check.
 * @return True if the folder list is empty, false otherwise.
 */
bool isEmptyFolderList(FolderList);

/**
 * Checks if two folder lists are equal.
 * @param listOne The first folder list.
 * @param listTwo The second folder list.
 * @return True if the folder lists are equal, false otherwise.
 */
bool equalFolderList(FolderList, FolderList);

/**
 * Gets the size of a folder list.
 * @param list The folder list to get the size of.
 * @return The size of the folder list.
 */
int getFolderListSize(FolderList);

/**
 * Adds a folder to the beginning of the folder list.
 * @param list Pointer to the folder list to which the folder is added.
 * @param folder The folder to add.
 * @return True if the folder was successfully added, false otherwise.
 */
bool addFolder(FolderList*, Folder);
/**
 * Removes a folder from the folder list.
 * @param list Pointer to the folder list from which the folder is removed.
 * @param folder The folder to remove.
 * @return True if the folder was successfully removed, false otherwise.
 */
bool removeFolder(FolderList*, Folder);

/**
 * Destroys a folder list, freeing all allocated memory.
 * @param list Pointer to the folder list to destroy.
 */
void destroyFolderList(FolderList*);

void debugPrintFolderList(FolderList);