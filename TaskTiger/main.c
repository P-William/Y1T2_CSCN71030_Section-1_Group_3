
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "folderAPI.h"

int main(void) {
	Folder folder = CreateFolderFromUser();
	EditFolder(&folder);

	return 0;
}