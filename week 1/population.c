#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int current_numb;

    do
    {
        current_numb = get_int("Start size: ");
    }

    while (current_numb < 9);

    // TODO: Prompt for end size

    int end_numb;

    do
    {
        end_numb = get_int("End size: ");
    }

    while (end_numb < current_numb);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;

    while (current_numb < end_numb)
    {

        current_numb = current_numb + (current_numb / 3) - (current_numb / 4);
        years++;
    }

    // TODO: Print number of years

    printf("Years: %i\n", years);
}
