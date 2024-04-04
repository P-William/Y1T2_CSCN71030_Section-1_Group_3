//take username and password string form user, assign these values to the brand new user struct, return username string to main to be used to create .txt file
#include "user.h"
#include "input_handler.h"

User takeUserInfo(char* username, char* password) {

	getStringFromUser(USERNAME_LENGTH, username, "Please enter your username: ");
	getStringFromUser(MAX_PASSWORD_LENGTH, password, "Please enter your password: ");

	return createUser(username, password);
}