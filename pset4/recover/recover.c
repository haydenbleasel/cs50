#include <stdio.h>

#include <stdlib.h>

int main(int argc, char *argv[])
{

    // Determine standard byte count
    int BYTES = 512;

    // Enforce a single command-line argument
    if (argc != 2)
    {
        printf("Please enter a command-line argument\n");
        return 1;
    }

    // Open the memory card
    FILE *file = fopen(argv[1], "r");

    // Check if the file is valid
    if (!file)
    {
        printf("Please provide a valid file\n");
        return 1;
    }

    // Filename counter
    int counter = -1;

    // Repeat until end of card
    while (1)
    {

        // Create a new buffer
        unsigned char buffer[BYTES];

        // Read bytes from file into the buffer
        int items = fread(buffer, BYTES, 1, file);

        // If there are no items left to scan...
        if (!items)
        {

            // End the while loop
            break;
        }

        // If we find the start of a JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {

            // Increment the counter
            counter++;
        }

        // Create a new file
        char *filename = malloc(8);
        sprintf(filename, "%03i.jpg", counter);
        FILE *img = fopen(filename, "a");
        free(filename);

        // Write the buffer to the file
        fwrite(buffer, 1, BYTES, img);

        // Close the file
        fclose(img);
    }
}