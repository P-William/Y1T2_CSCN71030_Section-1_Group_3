
#include <stdio.h>
#include <stdlib.h>

#include "file_io.h"
#include "folder_list.h"

FolderList createFolderList() {
	FolderList newList = {
		.head = NULL
	};
	return newList;
}

FolderList copyFolderList(FolderList src) {
	FolderList dest = createFolderList();
	pFolderNode current = src.head;

	while (current != NULL) {
		addFolder(&dest, current->folder);
		current = current->next;
	}

	return dest;
}

bool isEmptyFolderList(FolderList list) {
	return (list.head == NULL);
}

bool equalFolderList(FolderList listOne, FolderList listTwo) {
	pFolderNode currentOne = listOne.head;
	pFolderNode currentTwo = listTwo.head;

	while (currentOne != NULL && currentTwo != NULL) {
		if (!equalFolder(currentOne->folder, currentTwo->folder)) {
			return false;
		}
	}
	return (currentOne == NULL && currentTwo == NULL);
}

size_t getFolderListSize(FolderList list) {
	pFolderNode current = list.head;
	size_t count = 0;

	while (current != NULL) {
		current = current->next;
		count++;
	}

	return count;
}

pFolderNode createFolderNode(Folder folder) {
	pFolderNode newNode = (pFolderNode)malloc(sizeof(FolderNode));
	if (newNode == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}
	newNode->folder = copyFolder(folder);
	newNode->next = NULL;
	return newNode;
}

bool addFolder(FolderList* list, Folder folder) {
	pFolderNode newNode = createFolderNode(folder);
	if (newNode == NULL) {
		return false;
	}
	newNode->next = list->head;
	list->head = newNode;
	return true;
}
bool removeFolder(FolderList* list, Folder folder) {
	pFolderNode current = list->head;
	pFolderNode prev = NULL;

	if (current != NULL && equalFolder(current->folder, folder)) {
		list->head = current->next;
		destroyList(current->folder.list);
		free(current);
		return true;
	}

	while (current != NULL && !equalFolder(current->folder, folder)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		return false;
	}

	prev->next = current->next;
	destroyList(current->folder.list);
	free(current);
	return true;
}

void destroyFolderList(FolderList* list) {
	pFolderNode current = list->head;
	while (current != NULL) {
		pFolderNode temp = current;
		current = current->next;
		free(temp);
	}
	list->head = NULL;
}

bool saveFolderList(FILE* fp, FolderList folderList) {
	if (fp == NULL) {
		fprintf(stderr, "Null file pointer passed\n");
		return false;
	}

	pFolderNode current = folderList.head;

	fprintf(fp, "%llu\n", getFolderListSize(folderList));

	while (current != NULL)	{
		saveFolder(fp, current->folder);
		current = current->next;
	}
	return true;
}
FolderList loadFolderList(FILE* fp) {
	if (fp == NULL) {
		fprintf(stderr, "Null file pointer passed\n");
		exit(-1);
	}

	int listSize;
	getIntFromFile(fp, &listSize);

	FolderList list = createFolderList();

	for (int i = 0; i < listSize; i++) {
		Folder folder = loadFolder(fp);
		addFolder(&list, folder);
	}

	return list;
}

void debugPrintFolderList(FolderList list) {
	pFolderNode current = list.head;
	while (current != NULL) {
		debugPrintFolder(current->folder);
		current = current->next;
	}
}