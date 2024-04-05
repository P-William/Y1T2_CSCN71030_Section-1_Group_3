#include <stdio.h>
#include <stdbool.h>
#include "SettingsMenu.h"
#include "DisplaySettingsMenu.h"
#include "input_handler.h"
#include "userAPI.h"


/*	printf("-----------------------------------------------\n");
	printf("			Settings Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) Change Username\n");
	printf("b) Change Password\n"); 
	printf("c) Reset Save File\n");

	printf("\nw) Back\n");*/

bool SettingsMenu(User* user) {

	bool inMenu = true;
	char input = { 0 };
	while (inMenu) {
		DisplaySettingsMenu();
		bool inputCheck = getCharFromUser(&input, "Please enter your choice: ");
		if (!inputCheck) {
			printf("error taking input.\n");
		}

		switch (input) {
		case 'a':
			SetUsernameFromUser(user);
			break;
		case 'b':
			SetPasswordFromUser(user);
			break;
		case 'c':
			wipeProfile(user, true);
			break;


		case 'w': //back
			return true;
		}

	}
}