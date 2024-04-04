#include <stdio.h>
#include <stdbool.h>
#include "user.h"
#include "DisplayMainMenu.h"
#include "MainMenu.h"
#include "FolderMenu.h"
#include "SettingsMenu.h"
#include "input_handler.h"


/*
	printf("a) View Folder(s)\n"); //maybe italics "folders contain tasks"?
	printf("b) Task Tiger\n");
	printf("c) View Calendar\n");
	printf("d) Settings\n");
	printf("q) Save and Quit\n");
*/
//main menu takes FolderList and User as input?

bool MainMenu(User user) {
	DisplayMainMenu();
	bool inMenu = true;
	char input = { 0 };
	while (inMenu) {

		bool inputCheck = getCharFromUser(&input, "Please enter your choice: ");
		if (!inputCheck) {
			printf("error taking input.\n");
		}

		switch (input) {
		case 'a':
			FolderMenu(user.folders);
			break;
		case 'b':
			//TigerMenu();
			break;
		case 'c':
			//Calendar();
			break;
		case 'd':
			SettingsMenu();
			break;
		case 'q':
			//SaveAndQuit();
			inMenu = false;
			break;
		}
	}
}
