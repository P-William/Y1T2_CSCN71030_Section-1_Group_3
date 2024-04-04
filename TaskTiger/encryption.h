#pragma once

/**
 * Encrypts a message using XOR encryption with a given key.
 *
 * @param message The message to be encrypted.
 * @param key The encryption key.
 * @return A dynamically allocated string containing the encrypted message.
 * @note The caller is responsible for freeing the memory allocated for the returned string.
 * @warning Once encrypted, data is no long ensured to be printable characters, it is just raw binary data
 */
char* encrypt(const char* message, const char* key);
/**
 * Decrypts an encrypted message using the same key.
 *
 * @param encryptedMessage The encrypted message.
 * @param key The encryption key.
 * @return A dynamically allocated string containing the decrypted message.
 * @note The caller is responsible for freeing the memory allocated for the returned string.
 */
char* decrypt(const char* encryptedMessage, const char* key);

/**
 * @brief Encodes data into base64 format.
 *
 * This function takes an input buffer of binary data and encodes it into base64 format.
 *
 * @param data Pointer to the input buffer containing binary data.
 * @param outputLength Pointer to a size_t variable to store the length of the encoded data.
 * @return A dynamically allocated buffer containing the base64 encoded data. It is the responsibility of the caller to free this memory.
 *         Returns NULL if memory allocation fails.
 * @note Caller is responsible for freeing memory
 */
char* base64Encode(const unsigned char* data, size_t* outputLength);
/**
 * @brief Decodes base64 encoded data.
 *
 * This function takes a base64 encoded string and decodes it into binary data.
 *
 * @param data Pointer to the null-terminated string containing base64 encoded data.
 * @param outputLength Pointer to a size_t variable to store the length of the decoded data.
 * @return A dynamically allocated buffer containing the decoded binary data. It is the responsibility of the caller to free this memory.
 *         Returns NULL if memory allocation fails or if the input length is not valid for base64 encoding.
 * @note Caller is responsible for freeing memory
 */
unsigned char* base64Decode(const char* data, size_t* outputLength);