#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    // get the card number
    long card_num;

    do
    {
        card_num = get_long("Number: ");
    }

    while (card_num < 0);

    // get length of the card number
    int num_length = 0;
   
    while (num > 0)
    {
        num /= 10;
        num_length++;
    }

    // get the first digit of the card number from start
    int first_digit = card_num / pow(10, num_length - 1);

    // get the first 2 digits of the card number from start
    int first_two_digits = card_num / pow(10, num_length - 2);

    int digit1, digit2;

    // get a sum of the card number's second-to-last digit multiplied by 2

    int sum_1 = 0;                   // sum of the second-to-last digits
    long card_num_1 = card_num / 10; // card number without last digit
    int card_num_digits1 = 0;        // second-to-last digits

    while (card_num_1 > 0)
    {
        card_num_digits1 = card_num_1 % 10;
        card_num_digits1 *= 2;
        card_num_1 /= 100;

        if (card_num_digits1 > 9)
        {
            digit1 = card_num_digits1 % 10;
            card_num_digits1 /= 10;
            digit2 = card_num_digits1 % 10;
            card_num_digits1 = digit1 + digit2;
        }

        sum_1 += card_num_digits1;
    }

    // get a sum of the card number's other digits

    int card_num_digits2 = 0; // other digits
    int sum_2 = 0;            // sum of other digit

    while (card_num > 0)
    {
        card_num_digits2 = card_num % 10;

        card_num /= 100;

        sum_2 += card_num_digits2;
    }

    // check card validity

    // check if total sum's last digit is equal 0

    int total_sum = sum_1 + sum_2;
    int sum_last_digit = total_sum % 10;

    // output

    if (num_length == 15 && (first_two_digits == 34 || first_two_digits == 37) && sum_last_digit == 0)
    {
        printf("AMEX\n");
    }
    else if (num_length == 16 &&
             (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 ||
              first_two_digits == 55) &&
             sum_last_digit == 0)

    {

        printf("MASTERCARD\n");
    }

    else if ((num_length == 13 || num_length == 16) && first_digit == 4 && sum_last_digit == 0)
    {

        printf("VISA\n");
    }
    else
    {

        printf("INVALID\n");
    }
}
