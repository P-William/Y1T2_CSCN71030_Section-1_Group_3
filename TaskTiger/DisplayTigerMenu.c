#include <stdio.h>
#include "string_utils.h"
#include "user.h"
void DisplayTigerMenu(User user) {
	printf("\nYour tiger %s says hi!\n\n", user.tiger.name);

	printf("-----------------------------------------------\n");
	printf("		Tiger Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) Pet Tiger\n");
	printf("b) Feed Tiger\n"); 
	printf("c) Check on Tiger's Mood\n");
	printf("d) Rename Tiger\n");
	printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "w) Back\n\n");

}