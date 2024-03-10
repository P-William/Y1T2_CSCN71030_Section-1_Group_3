

#include <stdio.h>
#include <string.h>

#include "user.h"
#include "string_utils.h"

User createUser(const char* username, const char* password) {
	User newUser;
	strncpy(newUser.username, username, USERNAME_LENGTH);
	strncpy(newUser.passward, password, MAX_PASSWORD_LENGTH);
	newUser.points = 0;
	newUser.tigerStatus = HAPPY;
	return newUser;
}

bool equalUser(User userOne, User userTwo) {
	return (
		stringCompare(userOne.username, userTwo.username) &&
		stringCompare(userOne.passward, userTwo.passward) &&
		userOne.points == userTwo.points &&
		userOne.tigerStatus == userTwo.tigerStatus
	);
}

User copyUser(User src) {
	User newUser = createUser(src.username, src.passward);
	newUser.points = src.points;
	newUser.tigerStatus = src.tigerStatus;
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
	dest->tigerStatus = src.tigerStatus;
	return true;
}



void printTigerStatus(TigerStatus status, bool newLine) {
	switch (status) {
	case GRUMPY:
		printf("Grumpy");
		break;
	case STRESSED:
		printf("Stressed");
		break;
	case ANXIOUS:
		printf("Anxious");
		break;
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
	printTigerStatus(user.tigerStatus, newLine);
}


void debugPrintUser(User user) {
	printf("=== DEBUG PRINT USER ===\n");
	printf("Username: %s\n", user.username);
	printf("Password: %s\n", user.passward);
	printf("Points: %d\n", user.points);
	printTigerStatus(user.tigerStatus, true);
}