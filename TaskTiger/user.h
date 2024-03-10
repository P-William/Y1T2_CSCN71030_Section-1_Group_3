#pragma once

#include <stdbool.h>

#define USERNAME_LENGTH 128
#define MAX_PASSWORD_LENGTH 64

typedef enum TigerStatus {
	GRUMPY,
	STRESSED,
	ANXIOUS,
	HUNGRY,
	SAD,
	HAPPY
} TigerStatus;


typedef struct User {
	char username[USERNAME_LENGTH];
	char passward[MAX_PASSWORD_LENGTH];
	int points;
	TigerStatus tigerStatus;
} User;


User createUser(const char* username, const char* password);

bool equalUser(User, User);

User copyUser(User);

bool copyUserInPlace(User* dest, User src);




void printTigerStatus(TigerStatus, bool newLine);
void printTigerStatusU(User, bool newLine);


void debugPrintUser(User);