#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt); // function

int main(void) // value

{
    int number = get_positive_int("Height: "); // positive number

    for (int height = 0; height < number; height++) //height
    {
        for (int spaces = number - height - 2; spaces >= 0; spaces--) // spaces
        {
            printf(" ");
        }

        for (int row = 0; row <= height; row++) //left pyramid
        {
            printf("#");
        }

        printf("  ");
        for (int row2 = 0; row2 <= height; row2++) //right pyramid
        {
            printf("#");
        }

        printf("\n");
    }
}

int get_positive_int(string prompt) // function

{
    int number; // integer
    do
    {
        number = get_int("%s", prompt); // Integer
    }
    
    while (number < 1 || number > 8); // range
    return number; //return
}
