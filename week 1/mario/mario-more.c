#include <cs50.h>
#include <stdio.h>

// my solution

int main(void)
{

    int h;

    do
    {
        h = get_int("Height: ");
    }

    while (h < 1 || h > 8);

    for (int rows = h; rows > 0; rows--)
    {

        for (int spaces = rows - 1; spaces > 0; spaces--)
        {
            printf(" ");
        }

        for (int hashes = 0; hashes <= h - rows; hashes++)
        {
            printf("#");
        }

        printf("  ");

        for (int hashes = 0; hashes <= h - rows; hashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}



// One of the most popular solution.

// int main(void)
// {
//     int height;

//     do
//     {
//         height = get_int("Height: ");
//     }

//     while (height < 1 || height > 8);

//     for (int r = 0; r < height; r++)
//     {

//         for (int c = 0; c < height + r + 3; c++)
//         {

//             if (c == height || c == height + 1 || r + c < height - 1)
//             {
//                 printf(" ");
//             }

//             else
//             {
//                 printf("#");
//             }
//         }

//         printf("\n");
//     }
// }




