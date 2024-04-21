#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;
    do {
        height = get_int("Height: ");
        if (height == -1) {
            printf("Please enter a height greater than or equal to 0.\n");
        }
    } while (height <= -1);

    if (height == 2) {
        printf("Height: %d\n", height);
        printf(" #  #\n##  ##\n");
        return 0;
    }


    // Loop over rows
    for (int i = 0; i < height; i++) {
        // Print spaces for left pyramid
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        // Print blocks for left pyramid
        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        // Print gap between pyramids
        printf("  ");

        // Print blocks for right pyramid
        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}

