#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Hello\n");

    string user_name = get_string("What's your name? ");

    printf("Hello, %s.\n", user_name);
    
}
