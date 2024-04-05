#include <stdio.h>
#include "string_utils.h"
void DisplayTigerMenu() {
	printf("-----------------------------------------------\n");
	printf("		Tiger Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) Pet Tiger\n");
	printf("b) Feed Tiger\n"); 
	printf("c) Check on Tiger's Mood\n");
	printf("d) Rename Tiger\n");
	printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "w) Back\n\n");

}