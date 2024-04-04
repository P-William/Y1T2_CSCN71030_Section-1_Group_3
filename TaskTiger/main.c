
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "MainMenu.h"
#include "taskAPI.h"

int main(void) {
	// fake setup
	FolderList folderlist = createFolderList();

	MainMenu(&folderlist);


	return 0;
}