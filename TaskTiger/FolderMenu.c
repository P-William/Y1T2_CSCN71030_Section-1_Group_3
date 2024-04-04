#include <stdio.h>
#include <stdbool.h>
#include "FolderMenu.h"
#include "DisplayFolderMenu.h"
#include "input_handler.h"
#include "FolderAPI.h"

/*printf("-----------------------------------------------\n");
	printf("				Folder Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) View Folders\n"); 
	printf("b) Select Folder To View Tasks\n");
	printf("c) Create Folder\n");
	printf("d) Edit Folder\n");
	printf("e) Delete Folder\n");
	
	printf("\nw) Back\n");
	printf("q) Save and Quit\n");*/
bool FolderMenu(FolderList* fl) {
	DisplayFolderMenu();
	bool inMenu = true;
	char input = { 0 };
	while (inMenu) {
		bool inputCheck = getCharFromUser(&input, "Please enter your choice: ");
		if (!inputCheck) {
			printf("error taking input.\n");
		}

		switch (input) {
		case 'a':
			//DisplayAllFolders(); //create
			break;
		case 'b':
			//SelectFolder(); //create
			break;
		case 'c':
			addFolder(fl, CreateFolderFromUser()); //CreateFolder(); //create
			break;
		case 'd':
			EditFolder(searchFolder(fl)); //EditFolder(); //create
			break;
		case 'e':
			destroyFolder(*(searchFolder(fl))); //DeleteFolder(); //create
			break;

		case 'w': //back
			return true;
			break;
		case 'q': //quit
			//SaveAndQuit();
			inMenu = false;
		}

	}
}