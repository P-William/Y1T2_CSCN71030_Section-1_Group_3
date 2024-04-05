#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"
#include "user.h"

//bool firstPrint = true;

void DisplayMainMenu(User user) {
	
	//if (firstPrint) {
		printColoredStringAdvanced(ORANGE, NO_BG, BOLD, "Welcome to Task Tiger!\nNever forget a task again!\n");
		printf("User: %s \n", user.username);
		//firstPrint = false;
	//}
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