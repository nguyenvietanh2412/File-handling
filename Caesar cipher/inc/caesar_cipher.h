#ifndef CAESAR_CIPHER_H_
#define CAESAR_CIPHER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Convert a character using the Caesar cipher with a given shift.
 *
 * @param c The character to be converted.
 * @param shift The shift value for the Caesar cipher.
 * @return The converted character.
 */
char convert_caesar_cipher(char c, int shift);

/**
 * Encrypt or decrypt a message using the Caesar cipher.
 *
 * @param shift The shift value for the Caesar cipher.
 */
void encrypt_and_decrypt(int shift);

/**
 * Prompt the user to enter a shift value and check condition for encryption.
 *
 * @return The shift value entered by the user.
 */
int check_encrypting_shift();

/**
 * Prompt the user to enter a shift value and check condition for decryption
 *
 * @return The shift value entered by the user.
 */
int check_decrypting_shift();

#endif // CAESAR_CIPHER_H_
