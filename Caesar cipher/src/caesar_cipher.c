#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include "caesar_cipher.h"

int check_encrypting_shift()
{
    // int shift;
    // printf("Enter your shift to encrypt:");
    // while (scanf("%d",&shift) != 1 || shift < 0)
    // {
    //     printf("Invalid!\nEnter your shift to encrypt:");
    //     while (getchar() != '\n');
    // }
    // getchar();
    // return shift;

    int shift;
    char str[1024];
    char *p_end;
    printf("Encrypting shift: ");
    // Loop until a valid positive integer input is provided
    while (1) 
    {
        fgets(str, sizeof(str), stdin);
        shift = strtol(str, &p_end, 10);
        if (*p_end == '\n' && shift >= 0 && shift < 26) {
            break;
        }
        printf("Invalid encrypting shift. Enter again:\nID: ");
    }
    return shift;
}

int check_decrypting_shift()
{
    int shift;
    char str[1024];
    char *p_end;
    printf("Decrypting shift: ");
    // Loop until a valid positive integer input is provided
    while (1) 
    {
        fgets(str, sizeof(str), stdin);
        shift = strtol(str, &p_end, 10);
        if (*p_end == '\n' && shift <= 0 && shift > -26) {
            break;
        }
        printf("Invalid decrypting shift. Enter again:\nID: ");
    }
    return shift;
}
char convert_caesar_cipher(char c, int shift)
{
    if (isalpha(c))
    {
        c = toupper(c);
        char base = 'A';
        c = (c - base + shift) % 26 + base;
    }
    return c;
}

void encrypt_and_decrypt(int shift)
{
    FILE *p_file;
    FILE *p_file_result;
    char p_file_name[100];
    char p_file_name_result[100];

    printf("Enter file to encrypt: ");
    fgets(p_file_name, 100, stdin);
    p_file_name[strcspn(p_file_name, "\n")] = '\0';
    printf("Enter file to save encryption:");
    fgets(p_file_name_result, 100, stdin);
    p_file_name_result[strcspn(p_file_name_result, "\n")] = '\0';

    p_file = fopen(p_file_name, "r");
    p_file_result = fopen(p_file_name_result, "w");

    if (p_file == NULL)
    {
        printf("Cannot open file to encrypt.");
        exit(1);
    }
    if (p_file_result == NULL)
    {
        printf("Cannot open file to save encryption.");
        exit(1);
    }
    char c;
    while ((c = fgetc(p_file)) != EOF)
    {
        char encrypt_c = convert_caesar_cipher(c, shift);
        if (fputc(encrypt_c, p_file_result) == EOF)
        {
            printf("Error writing to file.");
            exit(1);
        }
    }
    fclose(p_file);
    fclose(p_file_result);
}