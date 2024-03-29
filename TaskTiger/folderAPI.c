#include "folderAPI.h"

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

Folder CreateFolderFromUser()
{
	Folder newFolder = createFolder("");

	// Get folder name
	RenameFolder(&newFolder);

	return newFolder;
}

void RenameFolder(Folder* folder) {
	if (stringCompare(folder->name, "")) {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\Set Folder Name");
	}
	else {
		printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\Set Folder Name | ");
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