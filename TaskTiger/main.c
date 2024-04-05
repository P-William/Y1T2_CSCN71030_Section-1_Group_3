
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "user.h"
#include "task.h"
#include "list.h"
#include "MainMenu.h"
#include "taskAPI.h"
#include "takeUserInfo.h"
#include "string.h"
#include "saveAndQuit.h"

int main(int argc, char* argv[]) {
	/*
	if (argc == 1) { //no file name passed, create new file
		//take usernmane and password input, store and then name the filename as username
		char username[USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
		User user = takeUserInfo(username, password);

		//create filename by appending username with ".txt"
		char buff[USERNAME_LENGTH + 4];
		snprintf(buff, sizeof(buff), "%s.txt", username);

		//IF IT DOESNT WORK?

		FILE* fp = fopen(buff, "w");

		fclose(fp);

		MainMenu(user);

		saveAndQuit(user); //IF WE WNAT TO SAVE AND QUIT FROM EVERY MENU, HOW?? EXIT(0)?

	}
	if (argc == 2) { //existing filename passed
		FILE* fp = fopen(argv[1], "r");
		if (fp == NULL) {
			printf("Error opening file. Please try again. \n");
			return 1;
		}

		//load from file
		User user = loadUser(fp);
		fclose(fp);

		MainMenu(user);

		if (saveAndQuit(user) == false) {
			printf("Error SAVING file. gg. \n");
			return 1;
		}

	}
	*/
	User user = createUser("william", "ethan");
	Folder folder = createFolder("william");
	Task task = createTask("ETHAN");
	task.date = createDate(5, 4, 2024);
	append(folder.list, task);
	addFolder(&user.folders, folder);

	Task task2 = createTask("new");
	task2.date = createDate(10, 4, 2024);
	append(folder.list, task2);
	addFolder(&user.folders, folder);

	MainMenu(user);

	return 0;
}