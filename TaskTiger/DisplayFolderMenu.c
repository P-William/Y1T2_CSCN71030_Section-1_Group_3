#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

void DisplayFolderMenu() {

	printf("-----------------------------------------------\n");
	printf("		Folder Menu\n");
	printf("-----------------------------------------------\n");
	printf("a) View Folders\n"); 
	printf("b) Select Folder To View Tasks\n");
	printf("c) Create Folder\n");
	printf("d) Edit Folder\n");
	printf("e) Delete Folder\n");
	printColoredStringAdvanced(WHITE, NO_BG, ITALIC, "w) Back\n\n");
}