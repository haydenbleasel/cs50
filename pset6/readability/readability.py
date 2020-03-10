from cs50 import get_string


def isAlpha(character):
    return character.lower() >= 'a' and character.lower() <= 'z'


def isWordTerminator(character):
    return character == ' ' or character == ','


def isSentenceTerminator(character):
    return character == '.' or character == '?' or character == '!'


def main():
    text = get_string("Text: ")

    letters = 0
    words = 0
    sentences = 0

    for i in range(len(text)):

        character = text[i]
        previousCharacter = character if i == 0 else text[i - 1]

        if isAlpha(character):
            letters += 1
        elif isWordTerminator(character) and isAlpha(previousCharacter):
            words += 1
        elif isSentenceTerminator(character) and isAlpha(previousCharacter):
            words += 1
            sentences += 1

    averageLettersPerHundredWords = letters / (words / 100.00)
    averageSentencesPerHundredWords = sentences / (words / 100.00)

    grade = (0.0588 * averageLettersPerHundredWords) - (0.296 * averageSentencesPerHundredWords) - 15.8

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(grade)}")


main()