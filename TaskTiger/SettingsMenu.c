#include <stdio.h>
#include <stdbool.h>
#include "SettingsMenu.h"
#include "DisplaySettingsMenu.h"
#include "input_handler.h"


/*	printf("-----------------------------------------------\n");
	printf("				Settings Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) Change Username\n");
	printf("b) Change Password\n"); 
	printf("c) Homepage Reminder Settings\n");
	printf("d) Reset Save File\n");

	printf("\nw) Back\n");
	printf("q) Save and Quit\n");*/

bool SettingsMenu() {
	DisplaySettingsMenu();
	bool inMenu = true;
	char input = { 0 };
	while (inMenu) {
		bool inputCheck = getCharFromUser(&input, "Please enter your choice: ");
		if (!inputCheck) {
			printf("error taking input.\n");
		}

		switch (input) {
		case 'a':
			//ChangeUsername();
			break;
		case 'b':
			//ChangePassword();
			break;
		case 'c':
			//ReminderSettings();
			break;
		case 'd':
			//ResetFile();
			break;


		case 'w': //back
			return true;
		case 'q': //quit
			//SaveAndQuit();
			inMenu = false;
		}

	}
}