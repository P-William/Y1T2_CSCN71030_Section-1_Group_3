#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "task.h"
#include "date.h"

#define USERNAME_LENGTH 128
#define MAX_PASSWORD_LENGTH 64

#define MAX_TIGER_NAME 128

typedef enum TigerStatus {
	SAD,
	HUNGRY,
	HAPPY
} TigerStatus;

typedef struct tiger {
	char name[MAX_TIGER_NAME];

	TigerStatus tigerMood;
	int hunger;
	Date lastFed;
	Date lastChecked;
} Tiger;

typedef struct User {
	char username[USERNAME_LENGTH];
	char passward[MAX_PASSWORD_LENGTH];
	int points;
	int totalTasksCompleted;
	int tasksCompletedOnTime;
	Date lastTaskCompletedDate;
	Tiger tiger;

} User;

/**
 * Creates a new user with the given username and password.
 * @param username The username for the new user.
 * @param password The password for the new user.
 * @return The newly created user.
 */
User createUser(const char* username, const char* password);

/**
 * Checks if two users are equal.
 * @param userOne The first user.
 * @param userTwo The second user.
 * @return true if the users are equal, false otherwise.
 */
bool equalUser(User, User);

/**
 * Creates a copy of a user.
 * @param src The user to copy.
 * @return The copy of the user.
 */
User copyUser(User);
/**
 * Copies a user into a destination user pointer.
 * @param dest Pointer to the destination user.
 * @param src The source user to copy.
 * @return true if the copy was successful, false if dest is NULL.
 */
bool copyUserInPlace(User* dest, User src);

/**
 * Sets the username of a user.
 * @param user Pointer to the user whose username to set.
 * @param newUsername The new username for the user.
 * @return true if the username was successfully set, false if user or newUsername is NULL.
 */
bool setUsername(User*, const char* newUsername);
/**
 * Sets the password of a user.
 * @param user Pointer to the user whose password to set.
 * @param newPassword The new password for the user.
 * @return true if the password was successfully set, false if user or newPassword is NULL.
 */
bool setPassword(User*, const char* newPassword);

/**
 * Increases the points of a user.
 * @param user Pointer to the user whose points to increase.
 * @param amount The amount by which to increase the points.
 * @return true if the points were successfully increased, false if user is NULL.
 */
bool increasePoints(User*, int amount);
/**
 * Decreases the points of a user.
 * @param user Pointer to the user whose points to decrease.
 * @param amount The amount by which to decrease the points.
 * @return true if the points were successfully decreased, false if user is NULL.
 */
bool decreasePoints(User*, int amount);
/**
 * Updates user statistics after completing a task.
 * @param user Pointer to the user.
 * @param task The task completed by the user.
 * @return true if the task completion was successfully updated, false if user is NULL.
 */
bool taskCompleted(User*, Task);

/**
 * Wipes user profile data.
 * @param user Pointer to the user.
 * @param youSure Flag indicating
 * @return true if the profile data was successfully wiped, false if youSure is false.
 */
bool wipeProfile(User*, bool youSure);


/**
 * Prints the tiger status to the standard output.
 * @param status The tiger status to print.
 * @param newLine Flag indicating whether to print a newline character.
 */
void printTigerStatus(TigerStatus, bool newLine);
/**
 * Prints the tiger status of a user to the standard output.
 * @param user The user whose tiger status to print.
 * @param newLine Flag indicating whether to print a newline character.
 */
void printTigerStatusU(User, bool newLine);

/**
 * Saves a user to a file.
 *
 * @param fp Pointer to the FILE object to write to.
 * @param user The User structure to be saved.
 * @return True if the user was successfully saved, false otherwise.
 */
bool saveUser(FILE* fp, User);
/**
 * Loads a user from a file.
 *
 * @param fp Pointer to the FILE object to read from.
 * @return The User structure loaded from the file.
 */
User loadUser(FILE* fp);


void debugPrintUser(User);