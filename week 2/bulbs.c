#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int toDecimal, toBinary[BITS_IN_BYTE];
int bulbs(void);
int messageToBinary(void);
int output(void);
void print_bulb(int bit);

int main(void)
{
    // TODO
    output();
}

int output(void)
{
    string message = get_string("Message: "); // get message from a user

    for (int i = 0; i < strlen(message); i++) // message to ASCII
    {
        toDecimal = message[i];
        messageToBinary(); // call the function that converts message to binary
        bulbs(); // get and print bulbs
    }
    return true;
}

// message to binary
int messageToBinary(void)
{

    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        toBinary[i] = toDecimal % 2;
        toDecimal /= 2;
    }

    return true;
}

// count bulbs
int bulbs(void)
{

    int bulbs = BITS_IN_BYTE - 1;

    while (0 <= bulbs)
    {
        print_bulb(toBinary[bulbs]);
        bulbs--;
    }

    printf("\n");
    return true;
}

// print the bulbs
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
