#pragma once

#include <stdio.h>
#include <stdbool.h>

/**
 * Gets an integer input from the user.
 *
 * @param output A pointer to the variable where the integer input will be stored.
 * @param prompt The message displayed to the user as a prompt.
 *
 * @return Returns true if a valid integer was successfully read from the user. Otherwise false.
 */
bool getIntFromUser(int* output, const char* prompt, ...);

/**
 * Gets an integer input from the user.
 *
 * @param min The minimum allowed value for the input.
 * @param max The maximum allowed value for the input.
 * @param displayLimits If the function should display the min and max value to the user after the prompt
 * @param output A pointer to the variable where the integer input will be stored.
 * @param prompt The message displayed to the user as a prompt.
 *
 * @return Returns true if a valid integer was successfully read from the user. Otherwise false.
 */
bool getIntFromUserWithRange(int min, int max, int* output, const char* prompt, ...);

/**
 * Prompts the user for a single character input.
 *
 * @param outputChar Pointer to a char variable where the input character will be stored.
 * @param prompt The message displayed to the user as a prompt.
 * @note outputChar won't modified unless input is successfully gathered.
 * @return Returns true if a single character was successfully read, otherwise false.
 */
bool getCharFromUser(char* outputChar, const char* prompt, ...);

/**
 * Prompts the user for a string input.
 *
 * @param maxLength The maximum length of the string to be read, including the null
 *        terminator.
 * @param output Pointer to a char array where the input string will be stored.
 * @param prompt The message displayed to the user as a prompt.
 *  * @note output won't modified unless input is successfully gathered.
 * @return Returns true if a string was successfully read, otherwise false.
 */
bool getStringFromUser(int maxLength, char* output, const char* prompt, ...);
