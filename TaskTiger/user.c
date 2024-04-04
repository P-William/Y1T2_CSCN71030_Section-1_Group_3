
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>

#include "user.h"
#include "file_io.h"
#include "string_utils.h"
#include "TigerAPI.h"

User createUser(const char* username, const char* password) {
	User newUser;
	strncpy(newUser.username, username, USERNAME_LENGTH);
	strncpy(newUser.passward, password, MAX_PASSWORD_LENGTH);
	newUser.points = 0;
	newUser.tiger = CreateTiger();
	return newUser;
}

bool equalUser(User userOne, User userTwo) {
	return (
		stringCompare(userOne.username, userTwo.username) &&
		stringCompare(userOne.passward, userTwo.passward) &&
		userOne.points == userTwo.points//&&
		//userOne.tigerStatus == userTwo.tigerStatus
	);
}

User copyUser(User src) {
	User newUser = createUser(src.username, src.passward);
	newUser.points = src.points;
	//newUser.tigerStatus = src.tigerStatus;
	return newUser;
}

bool copyUserInPlace(User* dest, User src) {
	if (dest == NULL) {
		fprintf(stderr, "Null pointer when trying to copy user\n");
		return false;
	}
	strncpy(dest->username, src.username, USERNAME_LENGTH);
	strncpy(dest->passward, src.passward, MAX_PASSWORD_LENGTH);
	dest->points = src.points;
	//dest->tigerStatus = src.tigerStatus;
	return true;
}

bool setUsername(User* user, const char* newUsername) {
	if (user == NULL || newUsername == NULL) {
		fprintf(stderr, "Setter failed, NULL user or name\n");
		return false;
	}
	strncpy(user->username, newUsername, USERNAME_LENGTH);
	return true;
}
bool setPassword(User* user, const char* newPassword) {
	if (user == NULL || newPassword == NULL) {
		fprintf(stderr, "Setter failed, NULL user or name\n");
		return false;
	}
	strncpy(user->passward, newPassword, MAX_PASSWORD_LENGTH);
	return true;
}

bool increasePoints(User* user, int amount) {
	if (user == NULL) {
		fprintf(stderr, "Setter failed, NULL User\n");
		return false;
	}
	user->points += amount;
	return true;
}
bool decreasePoints(User* user, int amount) {
	if (user == NULL) {
		fprintf(stderr, "Setter failed, NULL User\n");
		return false;
	}
	user->points -= amount;
	return true;
}
bool taskCompleted(User* user, Task task) {
	if (user == NULL) {
		fprintf(stderr, "Null user pointer passed\n");
		return false;
	}
	user->lastTaskCompletedDate = getCurrentDate();
	user->totalTasksCompleted += 1;
	increasePoints(user, 25);
	if (dateDifference(task.date, getCurrentDate()) >= 0) {
		user->tasksCompletedOnTime += 1;
		increasePoints(user, 50);
	}

	return true;
}

bool wipeProfile(User* user, bool youSure) {
	if (!youSure) {
		return false;
	}

	user->points = 0;
	user->totalTasksCompleted = 0;
	user->tasksCompletedOnTime = 0;
	user->lastTaskCompletedDate = getCurrentDate();
	//user->tigerStatus = HAPPY;
	return true;
}

void printTigerStatus(TigerStatus status, bool newLine) {
	switch (status) {
	case HUNGRY:
		printf("Hungry");
		break;
	case SAD:
		printf("Sad");
		break;
	case HAPPY:
		printf("Happy");
		break;
	default:
		break;
	}
	if (newLine) {
		printf("\n");
	}
}
void printTigerStatusU(User user, bool newLine) {
	//printTigerStatus(user.tigerStatus, newLine);
}

bool saveUser(FILE* fp, User user) {
	if (fp == NULL) {
		fprintf(stderr, "Null file pointer passed\n");
		return false;
	}

	writeStringToFile(fp, user.username);
	writeStringToFile(fp, user.passward);
	writeIntToFile(fp, user.points);
	writeIntToFile(fp, user.totalTasksCompleted);
	writeIntToFile(fp, user.tasksCompletedOnTime);
	saveDate(fp, user.lastTaskCompletedDate);
	writeIntToFile(fp, user.tigerStatus);

	return true;
}
User loadUser(FILE* fp) {
	if (fp == NULL) {
		fprintf(stderr, "Null file pointer passed\n");
		exit(-1);
	}

	User newUser;

	getStringFromFile(fp, newUser.username, USERNAME_LENGTH);
	getStringFromFile(fp, newUser.passward, MAX_PASSWORD_LENGTH);
	getIntFromFile(fp, &newUser.points);
	getIntFromFile(fp, &newUser.totalTasksCompleted);
	getIntFromFile(fp, &newUser.tasksCompletedOnTime);
	newUser.lastTaskCompletedDate = loadDate(fp);
	getIntFromFile(fp, (int*)&newUser.tigerStatus);

	return newUser;
}


void debugPrintUser(User user) {
	printf("=== DEBUG PRINT USER ===\n");
	printf("Username: %s\n", user.username);
	printf("Password: %s\n", user.passward);
	printf("Points: %d\n", user.points);
	//printTigerStatus(user.tigerStatus, true);
}