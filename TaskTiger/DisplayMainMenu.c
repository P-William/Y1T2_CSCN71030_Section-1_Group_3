#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"
#include "user.h"
#include "Calendar.h"
#include "tigerAPI.h"

bool firstPrint = true;

void DisplayMainMenu(User* user) {
	
	if (firstPrint) {
		printColoredStringAdvanced(ORANGE, NO_BG, BOLD, "\nWelcome to Task Tiger!\nNever forget a task again!\n\n");
		printf("User: %s \n", user->username);
		firstPrint = false;
	}

	printf("Your calendar for this month:\n(Days with tasks due will appear green)\n");
	print_calendar(*user, getCurrentDate());

	DetermineTigerMood(user);
	printf("Your tiger is ");
	printTigerStatus(user->tiger.tigerMood, true);

	printf("You have %d points.\n", user->points);




	//DISPLAY PERSONALIZED GREETINGS / 
	//bool firstPrint = true;
	//if(firstView) DisplayGreeting();
	//DisplayGreeting includes logo/drawing, welcome message with name?
	
	//if(newUser) newUser();
	//get username, password

	//DisplayReminders();

	//DisplayTigerStatus();


	printf("-----------------------------------------------\n");
	printf("		Main Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) View Folder Menu\n");
	printf("b) Task Tiger\n");
	printf("c) View Calendar\n");
	printf("d) Settings\n");
	printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "q) Save and Quit\n\n");
}