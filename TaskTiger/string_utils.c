

#include <ctype.h>
#include <string.h>

#include "string_utils.h"

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