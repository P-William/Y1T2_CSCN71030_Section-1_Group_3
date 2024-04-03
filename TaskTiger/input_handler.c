
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "input_handler.h"

#define MAX_INPUT_LENGTH 20
#define BASE 10

bool getIntFromUser(int* output, const char* prompt, ...) {
    va_list args;
    va_start(args, prompt);

    vprintf(prompt, args); // Use vprintf to handle variable arguments
    printf("\n> ");

    va_end(args);

    char input[MAX_INPUT_LENGTH];
    char* endptr;


    char* result = fgets(input, MAX_INPUT_LENGTH, stdin);
    if (result == NULL) {
        return false;
    }

    int number = (int)strtol(input, &endptr, BASE);
    if (input == endptr) {
        return false;
    }

    *output = number;
    return true;
}

bool getCharFromUser(char* outputChar, const char* prompt, ...) {

    va_list args;
    va_start(args, prompt);

    vprintf(prompt, args); // Use vprintf to handle variable arguments
    printf("\n> ");

    va_end(args);

    // char + newline from fgets + null terminator
    char input[3];

    char* result = fgets(input, sizeof(input), stdin);
    if (result != NULL) {
        // confirm they haven't entered more than one character. (strlen ignoring the \0 and fgets including \n)
        if (strlen(input) == 2 && input[1] == '\n') {
            *outputChar = input[0];
            return true;
        }
    }

    return false;
}

bool getStringFromUser(int maxLength, char* output, const char* prompt, ...) {
    va_list args;
    va_start(args, prompt);

    vprintf(prompt, args); // Use vprintf to handle variable arguments
    printf("\n> ");

    va_end(args);

    char* tempString = (char*)malloc(maxLength * sizeof(char));
    if (tempString == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return false;
    }

    char* result = fgets(tempString, maxLength, stdin);
    if (result == NULL) {
        fprintf(stderr, "Failed to get input\n");
        free(tempString);
        return false;
    }

    // remove the \n from fgets
    char* newLine = strchr(tempString, '\n');
    if (newLine != NULL) {
        *newLine = '\0';
    }

    strncpy(output, tempString, maxLength);

    free(tempString);
    return true;
}

bool getIntFromUserWithRange(int min, int max, int* output, const char* prompt, ...) {
    va_list args;
    va_start(args, prompt);

    vprintf(prompt, args); // Use vprintf to handle variable arguments
    printf("\n> ");

    va_end(args);

    char input[MAX_INPUT_LENGTH];
    char* endptr;

    char* result = fgets(input, MAX_INPUT_LENGTH, stdin);
    if (result == NULL) {
        return false;
    }

    int number = (int)strtol(input, &endptr, BASE);
    if (input == endptr) {
        return false;
    }
    if (number > max || number < min) {
        return false;
    }

    *output = number;
    return true;
}
