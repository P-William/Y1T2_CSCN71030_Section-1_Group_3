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
 * Encodes data into Base64 format.
 *
 * @param data The data to be encoded.
 * @return A dynamically allocated string containing the Base64 encoded data.
 * @note The caller is responsible for freeing the memory allocated for the returned string.
 */
char* base64Encode(const unsigned char* data);
/**
 * Decodes Base64 encoded data.
 *
 * @param data The Base64 encoded data.
 * @return A dynamically allocated buffer containing the decoded data.
 * @note The caller is responsible for freeing the memory allocated for the returned buffer.
 */
unsigned char* base64Decode(const char* data)