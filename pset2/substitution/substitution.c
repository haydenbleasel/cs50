#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Return whether the character is alphanumeric...
bool isAlpha(character)
{

    // ... if it is between a-z or A-Z
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

// Return whether the character is a number...
bool isNumber(character)
{

    // ... if it is between 0-9
    return character >= 48 && character <= 57;
}

int main(int argc, string argv[])
{

    // If there are not enough arguments...
    if (argc != 2)
    {

        // ... print error and quit.
        printf("Please enter one command-line argument\n");
        return 1;
    }

    // Extract argument from argument vector
    string arg = argv[1];

    string lowercaseAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string uppercaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int argumentLength = strlen(arg);

    if (argumentLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // For every character in the argument...
    for (int i = 0; i < argumentLength; i++)
    {

        // cast it to an integer
        int character = (int)(arg[i]);

        // If the character is a duplicate...
        for (int j = (i + 1); j < (argumentLength - i - 1); j++)
        {
            if (character == (int) arg[j])
            {
                // ... print usage example and quit.
                printf("Please enter a key without duplicate letters: %i, %i\n", character, arg[j]);
                return 1;
            }
        }

        // if that character is not a valid letter...
        if (!isAlpha(character))
        {

            // ... print usage example and quit.
            printf("Usage: ./substitution key %i\n", character);
            return 1;
        }

    }

    // Get the plaintext string from user
    string plaintext = get_string("plaintext: ");

    // Print the beginning of the ciphertext response
    printf("ciphertext: ");

    // For every character in the plaintext string...
    for (int i = 0; i < strlen(plaintext); i++)
    {

        // ... cast the character as an integer
        int number = (int) plaintext[i];

        // If the integer represents an alphanumeric character...
        if (isAlpha(number))
        {

            // If uppercase, find character index in uppercaseAlphabet;
            if (number >= 65 && number <= 90)
            {
                for (int j = 0; j < strlen(uppercaseAlphabet); j++)
                {
                    if ((int) uppercaseAlphabet[j] == number)
                    {
                        printf("%c", toupper(arg[j]));
                    }

                }
            }
            else
            {
                for (int j = 0; j < strlen(lowercaseAlphabet); j++)
                {

                    if ((int) lowercaseAlphabet[j] == number)
                    {
                        printf("%c", tolower(arg[j]));
                    }

                }
            }
        }
        else
        {
            printf("%c", number);
        }
    }

    // Start a new line
    printf("\n");

    // No errors
    return 0;
}