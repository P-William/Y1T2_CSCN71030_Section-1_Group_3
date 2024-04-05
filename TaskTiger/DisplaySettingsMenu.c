#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

void DisplaySettingsMenu() {

	printf("-----------------------------------------------\n");
	printf("		Settings Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) Change Username\n");
	printf("b) Change Password\n"); 
	printf("c) Reset Save File\n");
	printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "w) Back\n\n");
}