#include "folderAPI.h"

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TaskMenu.h"

Folder CreateFolderFromUser()
{
	Folder newFolder = createFolder("");

	// Get folder name
	RenameFolder(&newFolder);

	return newFolder;
}

void RenameFolder(Folder* folder) {
	if (stringCompare(folder->name, "")) {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Folder Name");
	}
	else {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Folder Name | ");
		printColoredStringAdvanced(ORANGE, NO_BG, ITALIC, folder->name);
	}

	getStringFromUser(TASK_TITLE_LENGTH, folder->name, "\nPlease enter a name:");
}

void EditFolder(Folder* folder) {
	bool editing = true;

	while (editing) {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nEdit Folder | ");
		printColoredStringAdvanced(ORANGE, NO_BG, ITALIC, folder->name);
		printf("\n");

		printf("a) Rename\n");
		printf("b) Delete\n");
		printColoredStringAdvanced(B_GREY, NO_BG, ITALIC, "c) Back\n\n");

		char selection;
		while (!getCharFromUser(&selection, "Please make a selection:")) {}

		switch (selection)
		{
		case 'a':
			RenameFolder(folder);
			break;
		case 'b':
			destroyFolder(*folder);
			editing = false;
			break;
		case 'c':
			editing = false;
		}
	}
}

Folder* searchFolder(FolderList* fl) {
	char folderName[FOLDER_NAME_LENGTH];
	getStringFromUser(FOLDER_NAME_LENGTH, folderName, "Enter the name of the folder you wish to find:");

	FolderNode* current = fl->head;

	while (current != NULL) {
		if (stringCompare(current->folder.name, folderName)) return &(current->folder);

		current = current->next;
	}

	return NULL;
}


void SelectFolder(FolderList* fl) {
	Folder* foundFolder = searchFolder(fl);

	if (foundFolder == NULL) {
		printColoredString(RED, "Folder not found.\n");
		return;
	}

	//TaskMenu(foundFolder);
}

void PrintFolders(FolderList* fl)
{
	FolderNode* current = fl->head;

	while (current != NULL) {
		printf("Folder: %s", current->folder.name);
		current = current->next;
	}
}