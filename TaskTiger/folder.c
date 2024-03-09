
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "folder.h"
#include "string_utils.h"


Folder createFolder(const char* name) {
	Folder newFolder;
	strncpy(newFolder.name, name, FOLDER_NAME_LENGTH);
	return newFolder;
}

bool equalFolder(Folder f1, Folder f2) {
	return (stringCompare(f1.name, f2.name));
}

Folder copyFolder(Folder src) {
	Folder newFolder = createFolder(src.name);
	return newFolder;
}
bool copyFolderInPlace(Folder* dest, Folder src) {
	if (dest == NULL) {
		fprintf(stderr, "Null pointer when trying to copy folder\n");
		return false;
	}
	strncpy(dest->name, src.name, FOLDER_NAME_LENGTH);
	return true;
}

void debugPrintFolder(Folder f) {
	printf("=== DEBUG PRINT FOLDER ===\n");
	printf("Name: %s\n", f.name);
}