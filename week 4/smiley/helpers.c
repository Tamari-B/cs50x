#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    for (int r = 0; r < height; r++) // r --> rows
    {
        for (int c = 0; c < width; c++) // c --> columns
        {
            // Identify black pixels
            int black_pix = image[r][c].rgbtRed == 0 && image[r][c].rgbtGreen == 0 && image[r][c].rgbtBlue == 0;

            // Change all black pixels into a tone purple
            if (black_pix == 1)
            {
                image[r][c].rgbtRed = 125;
                image[r][c].rgbtGreen = 20;
                image[r][c].rgbtBlue = 70;
            }
        }
    }
}
