
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "MainMenu.h"
#include "folderAPI.h"

int main(void) {
	Folder folder = CreateFolderFromUser();
	EditFolder(&folder);

	MainMenu();


	return 0;
}