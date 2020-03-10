#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    // Go over each of the rows in the image
    for (int h = 0; h < height; h++)
    {

        // Go over each of the columns in the image
        for (int w = 0; w < width; w++)
        {

            // At the current index, get the pixel
            RGBTRIPLE pixel = image[h][w];

            // Get the red, blue and green values
            int red = pixel.rgbtRed;
            int blue = pixel.rgbtBlue;
            int green = pixel.rgbtGreen;

            // Calculate the average colour
            int average = round((red + blue + green) / 3.00);

            // Set the RGB values of the pixel to the average
            image[h][w].rgbtRed = average;
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    // Go over each of the rows in the image
    for (int h = 0; h < height; h++)
    {

        // Go over each of the columns in the image
        for (int w = 0; w < width; w++)
        {

            // At the current index, get the pixel
            RGBTRIPLE pixel = image[h][w];

            // Get the red, blue and green values
            int red = pixel.rgbtRed;
            int blue = pixel.rgbtBlue;
            int green = pixel.rgbtGreen;

            // Calculate sepia colours
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // Set the RGB values to their sepia counterparts
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtGreen = sepiaGreen;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    int halfWidth = width / 2;

    // Go over each of the rows in the image
    for (int h = 0; h < height; h++)
    {

        // Go over each of the columns in the image
        for (int w = 0; w < halfWidth; w++)
        {

            // At the current index, get the pixel
            RGBTRIPLE pixel = image[h][w];

            // Swap the red values with the appropriate flipped pixel
            image[h][w].rgbtRed = image[h][width - 1 - w].rgbtRed;
            image[h][width - 1 - w].rgbtRed = pixel.rgbtRed;

            // Swap the green values with the appropriate flipped pixel
            image[h][w].rgbtGreen = image[h][width - 1 - w].rgbtGreen;
            image[h][width - 1 - w].rgbtGreen = pixel.rgbtGreen;

            // Swap the blue values with the appropriate flipped pixel
            image[h][w].rgbtBlue = image[h][width - 1 - w].rgbtBlue;
            image[h][width - 1 - w].rgbtBlue = pixel.rgbtBlue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*image2)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    // Go over each of the rows in the image
    for (int h = 0; h < height; h++)
    {

        // Go over each of the columns in the image
        for (int w = 0; w < width; w++)
        {

            // At the current index, get the pixel
            RGBTRIPLE pixel = image[h][w];

            // Get the surrounding pixels

            float count = 1.00;
            int red = pixel.rgbtRed;
            int blue = pixel.rgbtBlue;
            int green = pixel.rgbtGreen;

            // Add the above pixel to the totals
            if (h > 0)
            {
                RGBTRIPLE pixelUp = image[h - 1][w];

                red += pixelUp.rgbtRed;
                green += pixelUp.rgbtGreen;
                blue += pixelUp.rgbtBlue;
                count++;
            }

            // Add the below pixel to the totals
            if (h < height - 1)
            {
                RGBTRIPLE pixelDown = image[h + 1][w];

                red += pixelDown.rgbtRed;
                green += pixelDown.rgbtGreen;
                blue += pixelDown.rgbtBlue;
                count++;
            }

            // Add the left pixel to the totals
            if (w > 0)
            {
                RGBTRIPLE pixelLeft = image[h][w - 1];

                red += pixelLeft.rgbtRed;
                green += pixelLeft.rgbtGreen;
                blue += pixelLeft.rgbtBlue;
                count++;
            }

            // Add the right pixel to the totals
            if (w < width - 1)
            {
                RGBTRIPLE pixelRight = image[h][w + 1];

                red += pixelRight.rgbtRed;
                green += pixelRight.rgbtGreen;
                blue += pixelRight.rgbtBlue;
                count++;
            }

            // Add the top-left pixel to the totals
            if (w > 0 && h > 0)
            {
                RGBTRIPLE pixelLeftUp = image[h - 1][w - 1];

                red += pixelLeftUp.rgbtRed;
                green += pixelLeftUp.rgbtGreen;
                blue += pixelLeftUp.rgbtBlue;
                count++;
            }

            // Add the top-right pixel to the totals
            if (w < width - 1 && h > 0)
            {
                RGBTRIPLE pixelRightUp = image[h - 1][w + 1];

                red += pixelRightUp.rgbtRed;
                green += pixelRightUp.rgbtGreen;
                blue += pixelRightUp.rgbtBlue;
                count++;
            }

            // Add the bottom-left pixel to the totals
            if (w > 0 && h < height - 1)
            {
                RGBTRIPLE pixelLeftDown = image[h + 1][w - 1];

                red += pixelLeftDown.rgbtRed;
                green += pixelLeftDown.rgbtGreen;
                blue += pixelLeftDown.rgbtBlue;
                count++;
            }

            // Add the bottom-right pixel to the totals
            if (w < width - 1 && h < height - 1)
            {
                RGBTRIPLE pixelRightDown = image[h + 1][w + 1];

                red += pixelRightDown.rgbtRed;
                green += pixelRightDown.rgbtGreen;
                blue += pixelRightDown.rgbtBlue;
                count++;
            }

            // Calculate the blurred colour from the totals
            int blurredRed = round(red / count);
            int blurredGreen = round(green / count);
            int blurredBlue = round(blue / count);

            // Set the pixel's colour to the blurred colour
            image2[h][w].rgbtRed = blurredRed;
            image2[h][w].rgbtGreen = blurredGreen;
            image2[h][w].rgbtBlue = blurredBlue;
        }
    }

    // Go over each of the rows in the image
    for (int h = 0; h < height; h++)
    {

        // Go over each of the columns in the image
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = image2[h][w].rgbtRed;
            image[h][w].rgbtGreen = image2[h][w].rgbtGreen;
            image[h][w].rgbtBlue = image2[h][w].rgbtBlue;
        }
    }

    return;
}