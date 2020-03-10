#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

// Return whether the character is alphanumeric...
bool isAlpha(character)
{

    // ... if it is between a-z or A-Z
    return (character >= 'a' && character <= 'z');
}

// Return whether the character is a word terminator...
bool isWordTerminator(character)
{

    // ... if it is a space or a comma
    return character == ' ' || character == ',';
}

// Return whether the character is a sentence terminator...
bool isSentenceTerminator(character)
{

    // ... if it is a period, question mark or exclamation mark
    return character == '.' || character == '?' || character == '!';
}

int main(void)
{

    // Get the text to analyse from the user
    string text = get_string("Text: ");

    // Initialise our counters
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // For every character in the given text...
    for (int i = 0; i < strlen(text); i++)
    {

        // ... determine the current character (and previous, if possible)
        char character = tolower(text[i]);
        char previousCharacter = (i == 0) ? character : tolower(text[i - 1]);

        // If the character is alphanumeric
        if (isAlpha(character))
        {

            // ... it's a letter.
            letters++;
        }

        // Otherwise, if the character is a valid word terminator...
        else if (isWordTerminator(character) && isAlpha(previousCharacter))
        {

            // ... we've just completed a word.
            words++;
        }

        // Otherwise, if the character is a valid sentence terminator...
        else if (isSentenceTerminator(character) && isAlpha(previousCharacter))
        {

            // we've just completed a word and a sentence.
            words++;
            sentences++;
        }
    }

    // Calculate the required factors for the Coleman-Liau index
    float averageLettersPerHundredWords = (float) letters / ((float) words / 100.00);
    float averageSentencesPerHundredWords = (float) sentences / ((float) words / 100.00);

    // Calculate the Coleman-Liau index
    float grade = (0.0588 * averageLettersPerHundredWords) - (0.296 * averageSentencesPerHundredWords) - 15.8;

    // Print the CL index as a grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(grade));
    }
}