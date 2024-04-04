#pragma once

#include <stdbool.h>
#include <stdlib.h>

//bool writeStringToFile(FILE* fp, const char* string, const char* key);
//bool writeIntToFile(FILE* fp, int integer, const char* key);
//
//bool getStringFromFile(FILE* fp, char* output, size_t outputMaxLength, const char* key);
//bool getIntFromFile(FILE* fp, int* output, const char* key);


/**
 * Writes a string to a file.
 *
 * @param fp Pointer to the FILE object to write to.
 * @param string The string to be written to the file.
 * @return True if the string was successfully written, false otherwise.
 */
bool writeStringToFile(FILE* fp, const char* string);
/**
 * Writes an integer to a file.
 *
 * @param fp Pointer to the FILE object to write to.
 * @param integer The integer to be written to the file.
 * @return True if the integer was successfully written, false otherwise.
 */
bool writeIntToFile(FILE* fp, int integer);



/**
 * Reads a string from a file.
 *
 * @param fp Pointer to the FILE object to read from.
 * @param output Pointer to the buffer where the string read from the file will be stored.
 * @param maxLength Maximum length of the string to read, including the null terminator.
 * @return True if the string was successfully read, false otherwise.
 */
bool getStringFromFile(FILE* fp, char* output, size_t maxLength);
/**
 * Reads an integer from a file.
 *
 * @param fp Pointer to the FILE object to read from.
 * @param output Pointer to the integer where the value read from the file will be stored.
 * @return True if the integer was successfully read, false otherwise.
 */
bool getIntFromFile(FILE* fp, int* output);