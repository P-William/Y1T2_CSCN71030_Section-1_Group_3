//take user, open file, save user, return
#include "saveAndQuit.h"

bool saveAndQuit(User user) {
	//create filename by appending username with ".txt"
	char buff[USERNAME_LENGTH + 4];
	snprintf(buff, sizeof(buff), "%s.txt",user.username);

	FILE* fp = fopen(buff, "w");
	if (fp == NULL) {
		printf("Error opening file. Please try again. \n");
		return false;
	}

	bool success = saveUser(fp, user);
	fclose(fp);
	return success;
}

