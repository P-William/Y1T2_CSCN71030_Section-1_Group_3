
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

#include "encryption.h"


// XOR: If the corresponding bits in the two inputs are different, the result is 1, otherwise, it's 0.
// meaning applying XOR operation with the same key again decrypts the message.
char* encrypt(const char* message, const char* key) {
    size_t messageLength = strlen(message);
    size_t keyLength = strlen(key);
    char* encryptedMessage = (char*)malloc(messageLength + 1);

    // Iterate over each character in the message
    for (size_t i = 0; i < messageLength; i++) {
        // Perform XOR operation between the current character of the message and the corresponding character of the key.
        // The modulo operation ensures that if the key is shorter than the message, it will be repeated cyclically
        encryptedMessage[i] = message[i] ^ key[i % keyLength];
    }
    // Add null terminator
    encryptedMessage[messageLength] = '\0';

    return encryptedMessage;
}
char* decrypt(const char* encryptedMessage, const char* key) {
    return encrypt(encryptedMessage, key);
}

const char base64CharSet[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

char* base64Encode(const unsigned char* data) {
    size_t inputLength = strlen(data);

    // Calculate the length of the output data
    size_t outputLength = 4 * ((inputLength + 2) / 3); // Ceiling division

    char* encodedData = (char*)malloc(outputLength + 1); // Allocate memory for encoded data
    if (encodedData == NULL) {
        fprintf(stderr, "Failed memory allocation for base64 encode\n");
        return NULL;
    }


    for (size_t i = 0, j = 0; i < inputLength;) {
        // Extract three octets from the input data or pad with zeros if necessary
        uint32_t octetA;
        if (i < inputLength) {
            octetA = data[i++];
        }
        else {
            octetA = 0;
        }

        uint32_t octetB;
        if (i < inputLength) {
            octetB = data[i++];
        }
        else {
            octetB = 0;
        }

        uint32_t octetC;
        if (i < inputLength) {
            octetC = data[i++];
        }
        else {
            octetC = 0;
        }

        // Combine three octets into a 24-bit triple
        uint32_t triple = 
            (octetA << 0x10) + // We use bitwise left shift to shift the bits of octetA all the way to the left of triple. This works because octetA is 8 bits, and we shift it by 0x10 (16 bits)
            (octetB << 0x08) + // Here we are shifting octetB left by 8 bits, effectively putting it in the second slot
            octetC; // finally no shift here, we just put it in the final 8 bit slot

        // Encode the triple into four base64 characters
        // Here we want to extract the first 6 bits, so we right shift by the index * 6. 
        // Then we preform an AND operation with 0x3F (00111111 in binary, or 63 in decimal), this lets us extract the 6 least significant digits using bit masking.
        // Effectively, we extract 6 bites and discard the higher order bits, ensuring that the result is within the range of 0 to 63.
        encodedData[j++] = base64CharSet[(triple >> 3 * 6) & 0x3F];
        encodedData[j++] = base64CharSet[(triple >> 2 * 6) & 0x3F];
        encodedData[j++] = base64CharSet[(triple >> 1 * 6) & 0x3F];
        encodedData[j++] = base64CharSet[triple & 0x3F];
    }

    // Add padding '=' characters if necessary to reach the 24 bits
    for (size_t i = 0; i < (3 - inputLength % 3) % 3; i++) {
        encodedData[outputLength - 1 - i] = '=';
    }

    // Null-terminate the encoded data
    encodedData[outputLength] = '\0';
    return encodedData;
}

int base64ValueLookup(char c) {
    // Return the decimal value of a base64 character
    // Check if the character is in the range of uppercase letters
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    // Check if the character is in the range of lowercase letters
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    }
    // Check if the character is a digit
    if (c >= '0' && c <= '9') {
        return c - '0' + 52;
    }
    // Check if the character is the '-' character
    if (c == '-') {
        return 62;
    }
    // Check if the character is the '_' character
    if (c == '_') {
        return 63;
    }
    return -1; // Return -1 for invalid characters
}

unsigned char* base64Decode(const char* data) {
    size_t inputLength = strlen(data);

    // Check if the input length is a multiple of 4
    if (inputLength % 4 != 0) {
        fprintf(stderr, "Invalid length for base64 encoding\n");
        return NULL; // Return NULL if the input length is not valid for base64 encoding
    }

    // Calculate the length of the output buffer
    size_t outputLength = inputLength / 4 * 3;

    // Adjust output length if padding characters are present
    if (data[inputLength - 1] == '=') {
        (outputLength)--;
    }
    if (data[inputLength - 2] == '=') {
        (outputLength)--;
    }

    // Allocate memory for the decoded data, plus one extra byte for null termination
    unsigned char* decodedData = (unsigned char*)malloc(outputLength + 1);
    if (decodedData == NULL) {
        fprintf(stderr, "Failed memory allocation for base64 decode\n");
        return NULL;
    }

    // Iterate over the input data
    for (size_t i = 0, j = 0; i < inputLength;) {
        // Extract four Base64 characters (sextets) from the input data
        uint32_t sextetA;
        if (data[i] == '=') {
            sextetA = 0;
            i++;
        }
        else {
            // If not padding, decode the Base64 character and store the result in sextet_a
            sextetA = base64ValueLookup(data[i++]);
        }

        uint32_t sextetB;
        if (data[i] == '=') {
            sextetB = 0;
            i++;
        }
        else {
            sextetB = base64ValueLookup(data[i++]);
        }

        uint32_t sextetC;
        if (data[i] == '=') {
            sextetC = 0;
            i++;
        }
        else {
            sextetC = base64ValueLookup(data[i++]);
        }

        uint32_t sextet_d;
        if (data[i] == '=') {
            sextet_d = 0;
            i++;
        }
        else {
            sextet_d = base64ValueLookup(data[i++]);
        }

        // Combine the four sextets into a 24-bit triple by bit shifting into it's respective position
        uint32_t triple = (sextetA << 3 * 6) + (sextetB << 2 * 6) + (sextetC << 1 * 6) + (sextet_d << 0 * 6);

        // Decode the triple into three bytes and store in the array
        // We decode the 24 bit triple into three bytes by shifting and bit masking each byte
        // Each byte being 8 bits and a triple containing 3 bytes
        if (j < outputLength) {
            // first byte we get by shifting the triple right by 16 bits to extract the most significant byte
            // We use bit masking to mask all bits except the 8 we want. We do masking through the AND operation using 0xFF (11111111 in binary).
            decodedData[j++] = (triple >> 2 * 8) & 0xFF;
        }
        if (j < outputLength) {
            // second we shift by 8 bits
            decodedData[j++] = (triple >> 1 * 8) & 0xFF;
        }
        if (j < outputLength) {
            // We don't need to shift the last since it occupies space at the end of the triple
            decodedData[j++] = triple & 0xFF;
        }
    }

    // Null-terminate the decoded data
    decodedData[outputLength] = '\0';
    return decodedData;
}