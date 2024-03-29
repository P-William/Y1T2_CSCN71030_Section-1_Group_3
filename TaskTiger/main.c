
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "MainMenu.h"
#include "taskAPI.h"

int main(void) {
	Task task = CreateTaskFromUser();

	MainMenu();


	return 0;
}