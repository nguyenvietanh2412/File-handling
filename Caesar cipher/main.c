#include "caesar_cipher.h"

int main()
{
    int choice;
    while(1)
    {
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("0. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            encrypt_and_decrypt(check_encrypting_shift());
            break;
        case 2:
            encrypt_and_decrypt(check_decrypting_shift());
        case 0: 
            return 0;
            break;
        default:
            break;
        }

    }
    return 0;
}