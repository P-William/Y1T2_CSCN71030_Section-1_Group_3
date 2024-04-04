#include "userAPI.h"

int GetPointsFromUser(User* user)
{
	return user->points;
}

void SetUsernameFromUser(User* user) {
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Username");

	char newUsername[USERNAME_LENGTH];
	getStringFromUser(USERNAME_LENGTH, newUsername, "\nPlease enter a username:");
	setUsername(user, newUsername);
}

void SetPasswordFromUser(User* user)
{
	printColoredStringAdvanced(YELLOW, NO_BG, BOLD, "\nSet Password");
	
	char newPassword[MAX_PASSWORD_LENGTH];
	getStringFromUser(MAX_PASSWORD_LENGTH, newPassword, "\nPlease enter a password:");
	setPassword(user, newPassword);
}

List* GetTasksFromDate(User* user, Date date)
{
	List* foundTasks = createList();
	FolderNode* currentFolder = user->folders.head;

	while (currentFolder != NULL) {
		List* currentTasks = currentFolder->folder.list;

		for (int i = 0; i < currentTasks->size; i++) {
			if (equalDate(currentTasks->arr[i].date, date)) {
				append(foundTasks, currentTasks->arr[i]);
			}
		}
	}

	return foundTasks;
}

bool DateHasTask(User* user, Date date)
{
	List* foundTasks = createList();
	FolderNode* currentFolder = user->folders.head;

	while (currentFolder != NULL) {
		List* currentTasks = currentFolder->folder.list;

		for (int i = 0; i < currentTasks->size; i++) {
			if (equalDate(currentTasks->arr[i].date, date)) {
				return true;
			}
		}
	}

	return false;
}