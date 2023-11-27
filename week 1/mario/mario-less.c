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
        
        printf("\n");
    }
}


// one of the popular solution

// int main(void)
// {

//     int height;

//     do
//     {
//         height = get_int("Height: ");
//     }

//     while (height < 1 || height > 8);

//     for (int c = 0; c < height; c++)
//     {

//         for (int r = 0; r < height; r++)
//         {

//             if (c + r < height - 1)
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
