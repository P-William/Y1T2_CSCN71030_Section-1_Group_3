
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#include "string_utils.h"

#define BASE 10

bool stringToInt(const char* string, int* output) {
    if (string == NULL || output == NULL) {
        fprintf(stderr, "Null pointer passed, cannot convert\n");
        return false;
    }

    char* endptr;

    int convertedNumber = (int)strtol(string, &endptr, BASE);
    if (string == endptr) {
        return false;
    }

    *output = convertedNumber;
    return true;
}
bool intToString(int integer, char* outputString, size_t outputSize) {
    if (outputString == NULL) {
        fprintf(stderr, "Cannot output to null pointer\n");
        return false;
    }
    if (outputSize < CHARS_FOR_INT) {
        fprintf(stderr, "Too small of output buffer provided, buffer must be of size %d or greater", CHARS_FOR_INT);
        return false;
    }

    snprintf(outputString, outputSize, "%d", integer);
    outputString[CHARS_FOR_INT - 1] = '\0';

    return true;
}

bool stringCompare(const char* str1, const char* str2) {
    return (strcmp(str1, str2) == 0);
}
bool stringCompareI(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (tolower(*str1) != tolower(*str2)) {
            return false;
        }
        str1++;
        str2++;
    }

    // Check if both strings have reached the end
    if (*str1 == '\0' && *str2 == '\0') {
        return true;
    }
    else {
        return false;
    }
}

void stringToUpper(char* str) {
    while (*str != '\0') {
        if (islower(*str)) {
            *str = toupper(*str);
        }
        str++;
    }
}
void stringToUpperCopy(const char* input, char* output) {
    strcpy(output, input);
    stringToUpper(output);
}

void stringToLower(char* str) {
    while (*str != '\0') {
        if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}
void stringToLowerCopy(const char* input, char* output) {
    strcpy(output, input);
    stringToLower(output);
}


void printEnclosedText(char symbol, int symbolPerSide, const char* string, ...) {
    va_list args;
    va_start(args, string);

    for (int i = 0; i < symbolPerSide; i++) {
        printf("%c", symbol);
    }
    printf(" ");

    vprintf(string, args);

    printf(" ");
    for (int i = 0; i < symbolPerSide; i++) {
        printf("%c", symbol);
    }
    printf("\n");

    va_end(args);
}

void printEnclosedTextNL(char symbol, int symbolPerSide, bool newLine, const char* string, ...) {
    va_list args;
    va_start(args, string);
    printEnclosedText(symbol, symbolPerSide, string);
    if (newLine) {
        printf("\n");
    }
    va_end(args);
}


void printColoredStringAdvanced(TextColor color, BackgroundColor bgColor, TextTools tool, const char* string, ...) {
    const char RESET[] = "\033[0m";
    const char* TEXT_COLOR_CODES[] = {
        "", // none
        "\033[30m", // black
        "\033[31m", // red
        "\033[32m", // green
        "\033[33m", // orange
        "\033[34m", // blue
        "\033[35m", // prurple
        "\033[36m", // cyan
        "\033[37m", // white
        "\033[93m", // yellow
        "\033[90m", // grey
        "\033[95m", // pink
        "\033[37m", // bright grey
        "\033[91m", // bright red
        "\033[92m", // bright green
        "\033[94m", // bright blue
        "\033[96m", // bright cyan
    };
    const char* BG_COLOR_CODES[] = {
        "", // none
        "\033[40m", // black
        "\033[41m", // red
        "\033[42m", // green
        "\033[43m", // orange
        "\033[44m", // blue
        "\033[45m", // purple
        "\033[46m", // cyan
        "\033[47m" // bright grey
    };
    const char* TOOL_CODES[] = {
        "", // none
        "\033[01m", // bold
        "\033[03m", // italic
        "\033[04m", // underline
        "\033[09m" // strike through
    };


    va_list args;
    va_start(args, string);

    printf("%s%s%s", TEXT_COLOR_CODES[color], BG_COLOR_CODES[bgColor], TOOL_CODES[tool]);
    vprintf(string, args);
    printf("%s", RESET);

    va_end(args);
}

void printColoredString(TextColor color, const char* string, ...) {
    va_list args;
    va_start(args, string);
    printColoredStringAdvanced(color, NO_BG, NO_TOOL, string, args);
    va_end(args);
}