//feed, update hunger, get hunger, tiger mood
//create, name, save & load

#include <stdio.h>
#include <stdbool.h>
#include "TigerMenu.h"
#include "DisplayTigerMenu.h"
#include "DisplayTigerMenu.h"
#include "input_handler.h"
#include "tigerAPI.h"

/*printf("-----------------------------------------------\n");
	printf("				Task Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) Pet Tiger\n");
	printf("b) Feed Tiger\n"); //award tiger points!
	printf("c) Check on Tiger's Mood\n");
	printf("d) Rename Tiger\n");

	printf("\nw) Back\n");*/

bool TigerMenu(User* user) {
	if (stringCompare(user->tiger.name, "DEFAULT_TIGER_NAME")) {
		NameTiger(&user->tiger);
	}
	bool inMenu = true;
	char input = { 0 };
	while (inMenu) {
		DisplayTigerMenu(user);
		bool inputCheck = getCharFromUser(&input, "Please enter your choice: ");
		if (!inputCheck) {
			printf("error taking input.\n");
		}

		switch (input) {
		case 'a':
			petTiger();
			break;
		case 'b':
			FeedTiger(user);
			break;
		case 'c':
			DetermineTigerMood(user);
			printf("Your tiger is ");
			printTigerStatus(user->tiger.tigerMood, true);
			break;
		case 'd':
			NameTiger(&user->tiger);
			break;


		case 'w': //back
			return true;
			break;

		}

	}
	return true;
}