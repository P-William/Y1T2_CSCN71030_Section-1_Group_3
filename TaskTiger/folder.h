#pragma once

#include "task.h"

#define FOLDER_TITLE_LENGTH 128

typedef struct Folder {
	char name[FOLDER_TITLE_LENGTH];
	// TODO: add list
} Folder;

Folder createFolder(const char* title);

bool equalFolder(Folder, Folder);

Folder copyFolder(Folder src);
bool copyFolderInPlace(Folder* dest, Folder src);

void debugPrintFolder(Folder);