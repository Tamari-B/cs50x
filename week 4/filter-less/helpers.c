#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++) // r --> rows
    {
        for (int c = 0; c < width; c++) // c --> columns
        {
            // Avarage values (<-- must be the whole number so the round function is necessary)
            int avg = round((float) (image[r][c].rgbtRed + image[r][c].rgbtGreen + image[r][c].rgbtBlue) / 3);

            // Image to grayscale
            image[r][c].rgbtRed = image[r][c].rgbtGreen = image[r][c].rgbtBlue = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int r = 0; r < height; r++) // r --> rows
    {
        for (int c = 0; c < width; c++) // c --> columns
        {

            // the Original red, green, blue values

            int red = image[r][c].rgbtRed;
            int green = image[r][c].rgbtGreen;
            int blue = image[r][c].rgbtBlue;

            // Sepia algorithm

            // The resulting red, green, and blue values must be whole numbers

            int sepiaR = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaG = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaB = round(0.272 * red + 0.534 * green + 0.131 * blue);

            // The resulting red, green, and blue values must be between 0 and 255, inclusive

            if (sepiaR > 255)
            {
                sepiaR = 255;
            }
            if (sepiaG > 255)
            {
                sepiaG = 255;
            }
            if (sepiaB > 255)
            {
                sepiaB = 255;
            }

            // Image to sepia
            image[r][c].rgbtRed = sepiaR;
            image[r][c].rgbtGreen = sepiaG;
            image[r][c].rgbtBlue = sepiaB;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++) // r --> row
    {
        int opposite_c = width - 1; // opposite_c -->

        for (int c = 0; c < opposite_c; c++, opposite_c--) // c --> column

        {

            RGBTRIPLE tempor = image[r][c];
            image[r][c] = image[r][opposite_c];
            image[r][opposite_c] = tempor;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy_img[height][width];

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            copy_img[r][c] = image[r][c]; // copying image into copy_img, pixel by pixel
        }
    }

    return;
}
