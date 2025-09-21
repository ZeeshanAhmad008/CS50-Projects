#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check argument count
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Ensure key is numeric
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert key to int and normalize
    int key = atoi(argv[1]) % 26;

    // Get plaintext
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    // Encrypt
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                printf("%c", (plain[i] - 'A' + key) % 26 + 'A');
            }
            else
            {
                printf("%c", (plain[i] - 'a' + key) % 26 + 'a');
            }
        }
        else
        {
            printf("%c", plain[i]); // Non-letters unchanged
        }
    }
    printf("\n");
}

