#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

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

    // Initialise K
    int k = 0;

    // For every character in the argument...
    for (int i = 0; i < strlen(arg); i++)
    {

        // cast it to an integer
        int character = (int)(arg[i]);

        // if that character is not a valid number...
        if (!isNumber(character))
        {

            // ... print usage example and quit.
            printf("Usage: ./caesar key %i\n", character);
            return 1;
        }

        // Otherwise, turn the character into a number and add it to K
        k += (character - 48) * pow(10, (strlen(arg) - 1 - i));
    }

    // Get the plaintext string from user
    string plaintext = get_string("plaintext: ");

    // Print the beginning of the ciphertext response
    printf("ciphertext: ");

    // Ensure K doesn't go beyond 26 characters
    while (k > 26)
    {
        k -= 26;
    }

    // For every character in the plaintext string...
    for (int i = 0; i < strlen(plaintext); i++)
    {

        // ... cast the character as an integer
        int number = (int) plaintext[i];

        // If the integer represents an alphanumeric character...
        if (isAlpha(number))
        {

            // Add K to the character
            number += k;

            // If the new number is more than 'z'...
            if (number > 122)
            {

                // ... start again at 'a'
                number = 96 + (number - 122);
            }

            // If the new number is more than 'Z' but less than 'a'...
            if (number > 91 && number < 97)
            {

                // ... start again at 'A'
                number = 64 + (number - 65);
            }
        }

        // Print out the encrypted character
        printf("%c", number);
    }

    // Start a new line
    printf("\n");

    // No errors
    return 0;
}