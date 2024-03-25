
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "folder.h"
#include "string_utils.h"


Folder createFolder(const char* name) {
	Folder newFolder;
	strncpy(newFolder.name, name, FOLDER_NAME_LENGTH);
	newFolder.list = createList();
	if (newFolder.list == NULL) {
		fprintf(stderr, "Failed memory allocation for Folder\n");
		exit(-1);
	}
	return newFolder;
}

bool equalFolder(Folder f1, Folder f2) {
	return (
		stringCompare(f1.name, f2.name) &&
		equalList(f1.list, f2.list)
	);
}

Folder copyFolder(Folder src) {
	Folder newFolder = createFolder(src.name);
	newFolder.list = copyList(src.list);
	return newFolder;
}

bool setName(Folder* folder, const char* newName) {
	if (folder == NULL || newName == NULL) {
		return false;
	}
	strncpy(folder->name, newName, FOLDER_NAME_LENGTH);
	return true;
}

void destroyFolder(Folder folder) {
	destroyList(folder.list);
}

void debugPrintFolder(Folder f) {
	printf("=== DEBUG PRINT FOLDER ===\n");
	printf("Name: %s\n", f.name);
	debugPrintList(f.list);
}