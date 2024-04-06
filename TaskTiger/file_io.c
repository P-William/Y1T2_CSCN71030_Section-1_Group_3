
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_io.h"
#include "string_utils.h"

#define BASE 10
//#define INT_SIZE_IN_CHARS 12 // –2147483648 + null terminator

//bool writeStringToFile(FILE* fp, const char* string, const char* key) {
//	char* encrpytedString = encrypt(string, key);
//	if (encrpytedString == NULL) {
//		return false;
//	}
//
//    printf("Ency: %s\n", encrpytedString);
//
//    size_t encodedSize;
//	char* encodedString = base64Encode(encrpytedString, &encodedSize);
//	if (encodedString == NULL) {
//		free(encrpytedString);
//		return false;
//	}
//
//    printf("encodedSize: %d\n", encodedSize);
//    printf("encodedString: %s\n", encodedString);
//
//    fprintf(fp, "%llu", encodedSize);
//	fprintf(fp, "%s\n", encodedString);
//
//	free(encrpytedString);
//	free(encodedString);
//
//	return true;
//}
//#pragma warning(disable: 6054)
//bool writeIntToFile(FILE* fp, int integer, const char* key) {
//
//	char string[INT_SIZE_IN_CHARS];
//	snprintf(string, INT_SIZE_IN_CHARS, "%d", integer);
//	string[INT_SIZE_IN_CHARS - 1] = '\0';
//
//	return writeStringToFile(fp, string, key);
//}
//#pragma warning(default: 6054)
//
//
//
//bool getStringFromFile(FILE* fp, char* output, size_t outputMaxLength, const char* key) {
//    size_t storedLength;
//    fscanf(fp, "%llu\n", &storedLength);
//    
//    char* buffer = (char*)malloc(sizeof(char) * storedLength);
//    if (buffer == NULL) {
//        fprintf(stderr, "Failed to allocate memory when loading string from file\n");
//        return false;
//    }
//
//    bool result = getStringFromStream(fp, buffer, storedLength);
//    if (!result) {
//        fprintf(stderr, "Failed to get string from file\n");
//        free(buffer);
//        return false;
//    }
//
//    size_t decodedLength;
//    unsigned char* decoded = base64Decode(buffer, &decodedLength);
//    if (decoded == NULL) {
//        free(buffer);
//        return false;
//    }
//
//    char* decryped = decrypt(decoded, key);
//    if (decryped == NULL) {
//        free(buffer);
//        free(decoded);
//        return false;
//    }
//
//    strncpy(output, decryped, outputMaxLength);
//    output[outputMaxLength - 1] = '\0';
//
//    free(buffer);
//    free(decoded);
//    free(decryped);
//    return true;
//}
//bool getIntFromFile(FILE* fp, int* output, const char* key) {
//    char buffer[INT_SIZE_IN_CHARS + 1];
//
//    bool result = getStringFromFile(fp, buffer, sizeof(buffer), key);
//    if (!result) {
//        return false;
//    }
//
//    char* endptr;
//    int number = (int)strtol(buffer, &endptr, BASE);
//    if (buffer == endptr) {
//        fprintf(stderr, "Failed string to integer conversion\n");
//        return false;
//    }
//
//    *output = number;
//    return true;
//}

bool writeStringToFile(FILE* fp, const char* string) {
    if (fp == NULL || string == NULL) {
        return false;
    }

    fprintf(fp, "%s\n", string);

    return true;
}
bool writeIntToFile(FILE* fp, int integer) {
    if (fp == NULL) {
        return false;
    }

    fprintf(fp, "%d\n", integer);

    return true;
}

bool getStringFromFile(FILE* fp, char* output, size_t maxLength) {
    char* tempString = (char*)malloc(maxLength * sizeof(char));
    if (tempString == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return false;
    }

    char* result = fgets(tempString, (int)maxLength, fp);
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

bool getIntFromFile(FILE* fp, int* output) {
    char buffer[CHARS_FOR_INT];
    bool result = getStringFromFile(fp, buffer, CHARS_FOR_INT);
    if (!result) {
        return false;
    }

    return stringToInt(buffer, output);
}