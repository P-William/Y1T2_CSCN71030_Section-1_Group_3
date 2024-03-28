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
		printColoredStringAdvanced(YELLOW, BG_BLACK, BOLD, "\Set Folder Name");
	}
	else {
		printColoredStringAdvanced(YELLOW, BG_BLACK, BOLD, "\Set Folder Name | ");
		printColoredStringAdvanced(ORANGE, BG_BLACK, ITALIC, folder->name);
	}

	getStringFromUser(TASK_TITLE_LENGTH, folder->name, "\nPlease enter a name:");
}

void EditFolder(Folder* folder) {
	bool editing = true;

	while (editing) {
		printColoredStringAdvanced(YELLOW, BG_BLACK, BOLD, "\nEdit Folder | ");
		printColoredStringAdvanced(ORANGE, BG_BLACK, ITALIC, folder->name);
		printf("\n");

		printf("a) Rename\n");
		printf("b) Delete\n");
		printColoredStringAdvanced(B_GREY, BG_BLACK, ITALIC, "c) Continue\n\n");

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