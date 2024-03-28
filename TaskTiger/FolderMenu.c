#include <stdio.h>
#include <stdbool.h>
#include "DisplayFolderMenu.h"

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
bool FolderMenu() {
	DisplayFolderMenu();//changed up to here <
	bool inMenu = true;
	char input = { 0 };
	while (inMenu) {
		bool inputCheck = getCharFromUser(&input, "Please enter your choice: ");
		if (!inputCheck) {
			printf("error taking input.\n");
		}

		switch (input) {
		case 'a':
			DisplayAllFolders(); //create
			break;
		case 'b':
			SelectFolder(); //create
			break;
		case 'c':
			CreateFolder(); //create
			break;
		case 'd':
			EditFolder(); //create
			break;
		case 'e':
			DeleteFolder(); //create
			break;

		case 'w': //back
			MainMenu(); 
			break;
		case 'q': //quit
			SaveAndQuit();
			inMenu = false;
		}

	}