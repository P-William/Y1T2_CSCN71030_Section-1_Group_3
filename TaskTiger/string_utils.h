#pragma once

#include <stdbool.h>

/**
 * strcmp wrapper that returns a bool
 */
bool stringCompare(const char*, const char*);
/**
 * Compare two strings case-insensitively.
 *
 * @param str1 Pointer to the first null-terminated string to be compared.
 * @param str2 Pointer to the second null-terminated string to be compared.
 * @return Returns `true` if the strings are equal (ignoring case); otherwise, returns `false`.
 */
bool stringCompareI(const char*, const char*);

/**
 * Converts the input string to uppercase in place.
 * @param str The input string to be converted to uppercase
 */
void stringToUpper(char*);
/**
 * Copies the input string and converts the copy to uppercase.
 * @param input The input string to be copied and converted to uppercase
 * @param output The output string where the converted uppercase string will be stored
 */
void stringToUpperCopy(const char* input, char* output);
/**
 * Converts the input string to lowercase in place.
 * @param str The input string to be converted to lowercase
 */
void stringToLower(char*);
/**
 * Copies the input string and converts the copy to lowercase.
 * @param input The input string to be copied and converted to lowercase
 * @param output The output string where the converted lowercase string will be stored
 */
void stringToLowerCopy(const char* input, char* output);