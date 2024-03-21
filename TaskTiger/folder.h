#pragma once


#include "list.h"
#include "task.h"

#define FOLDER_NAME_LENGTH 128


typedef struct Folder {
	char name[FOLDER_NAME_LENGTH];
	List list;
} Folder;

Folder createFolder(const char* name);

bool equalFolder(Folder, Folder);

Folder copyFolder(Folder src);
bool copyFolderInPlace(Folder* dest, Folder src);

void debugPrintFolder(Folder);