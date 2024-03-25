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

FolderList createFolderList();

FolderList copyFolderList(FolderList src);

bool isEmptyFolderList(FolderList);

bool equalFolderList(FolderList, FolderList);

int getFolderListSize(FolderList);

bool addFolder(FolderList*, Folder);
bool removeFolder(FolderList*, Folder);

void destroyFolderList(FolderList*);

void debugPrintFolderList(FolderList);