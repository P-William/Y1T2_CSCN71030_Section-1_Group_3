#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

void DisplayTaskMenu() {

	printf("-----------------------------------------------\n");
	printf("		Task Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) View Tasks\n");
	printf("b) Mark Task as Complete\n"); //award tiger points!
	printf("c) Create Task\n");
	printf("d) Edit Task\n");
	printf("e) Delete Task\n");
	printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "w) Back\n\n");
}