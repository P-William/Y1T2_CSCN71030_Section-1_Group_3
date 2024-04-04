
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "user.h"
#include "task.h"
#include "list.h"
#include "MainMenu.h"
#include "taskAPI.h"
#include "takeUserInfo.h"
#include "string.h"

int main(int argc, char* argv[]) {

	if (argc == 1) { //no file name passed, create new file
		//take usernmane and password input, store and then name the filename as username
		char username[USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
		User user = takeUserInfo(username, password);

		//create filename by appending username with ".txt"
		char buff[USERNAME_LENGTH + 4];
		snprintf(buff, sizeof(buff), "%s.txt", username);

		FILE* new_file_handle = fopen(buff, "w");

		MainMenu(user);

	}
	if (argc == 2) { //existing filename passed
		FILE* fp = fopen(argv[1], "r");
		if (fp == NULL) {
			printf("Error opening file. Please try again. \n");
			return 1;
		}

		//load from file
		User user = loadUser(fp);

		MainMenu(user);

	}

	return 0;
}