#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "caesar_cipher.h"

// Function to validate and retrieve a valid encryption shift
int check_encrypting_shift()
{
    int shift;
    char str[1024];
    char *p_end;
    printf("Encrypting shift: ");
    
    // Loop until a valid positive integer input is provided
    while (1) 
    {
        fgets(str, sizeof(str), stdin);
        shift = strtol(str, &p_end, 10);
        
        // Check if the input is a valid number within the shift range (0-25)
        if (*p_end == '\n' && shift > 0 && shift < 26) {
            break;
        }
        printf("Invalid encrypting shift. Enter again:\nEncrypting shift: ");
    }
    return shift;
}

// Function to validate and retrieve a valid decryption shift
int check_decrypting_shift()
{
    int shift;
    char str[1024];
    char *p_end;
    printf("Decrypting shift: ");
    
    // Loop until a valid negative integer input is provided
    while (1) 
    {
        fgets(str, sizeof(str), stdin);
        shift = strtol(str, &p_end, 10);
        
        // Check if the input is a valid number within the shift range (-25 to 0)
        if (*p_end == '\n' && shift < 0 && shift > -26) {
            break;
        }
        printf("Invalid decrypting shift. Enter again:\nDecrypting shift: ");
    }
    return shift;
}

// Function to perform the Caesar cipher encryption/decryption for a character
char convert_caesar_cipher(char c, int shift)
{
    if (isalpha(c))
    {
        c = toupper(c);
        char base = 'A';
        c = (c - base + shift + 26) % 26 + base; // Shifted value [0-25]
    }
    return c;
}

// Function to perform Caesar cipher encryption/decryption on a file
void encrypt_and_decrypt(int shift)
{
    FILE *p_file;
    FILE *p_file_result;
    char p_file_name[100];
    char p_file_name_result[100];

    // Prompt user for input and output file names
    printf("Enter file to open: ");
    fgets(p_file_name, 100, stdin);
    p_file_name[strcspn(p_file_name, "\n")] = '\0';
    printf("Enter file to save result: ");
    fgets(p_file_name_result, 100, stdin);
    p_file_name_result[strcspn(p_file_name_result, "\n")] = '\0';

    // Open input and output files
    p_file = fopen(p_file_name, "r");
    p_file_result = fopen(p_file_name_result, "w");

    // Check if files are opened successfully
    if (p_file == NULL)
    {
        printf("Cannot open file.");
        exit(1);
    }
    if (p_file_result == NULL)
    {
        printf("Cannot open file to save result.");
        exit(1);
    }
    
    // Process each character in the input file
    char c;
    while ((c = fgetc(p_file)) != EOF)
    {
        char encrypt_c = convert_caesar_cipher(c, shift);
        
        // Write encrypted/decrypted character to the output file
        if (fputc(encrypt_c, p_file_result) == EOF)
        {
            printf("Error writing to file.");
            exit(1);
        }
    }
    
    // Close files
    fclose(p_file);
    fclose(p_file_result);
}
