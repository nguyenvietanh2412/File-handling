#include "caesar_cipher.h"

int main()
{
    int choice;
    
    // Loop to continuously prompt the user for action
    while(1)
    {
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character
        
        switch (choice)
        {
        case 1:
            // Call the encryption function with the encrypting shift obtained from the user
            encrypt_and_decrypt(check_encrypting_shift());
            break;
        case 2:
            // Call the decryption function with the decrypting shift obtained from the user
            encrypt_and_decrypt(check_decrypting_shift());
            break;
        case 0:
            // Exit the program when the user selects '0'
            return 0;
            break;
        default:
            // Handle invalid choices gracefully
            printf("Invalid choice. Please select a valid option.\n");
            break;
        }
    }
    
    return 0;
}
