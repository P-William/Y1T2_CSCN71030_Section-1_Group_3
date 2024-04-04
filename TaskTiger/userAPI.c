#include "userAPI.h"
#include "string_utils.h"
#include "input_handler.h"

int GetPointsFromUser(User* user)
{
	return user->points;
}

void SetUsernameFromUser(User* user) {
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Username");

	char newUsername[USERNAME_LENGTH];
	getStringFromUser(USERNAME_LENGTH, newUsername, "\nPlease enter a username:");
	setUsername(user->username, newUsername);
}

void SetPasswordFromUser(User* user)
{
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Password");
	
	char newPassword[MAX_PASSWORD_LENGTH];
	getStringFromUser(MAX_PASSWORD_LENGTH, newPassword, "\nPlease enter a username:");
	setPassword(user, newPassword);
}