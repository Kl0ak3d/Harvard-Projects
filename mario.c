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
        printf("height: %d\n", height);
    } else {
        // Loop over rows
        for (int i = 0; i < height; i++) {
            // Spaces for left pyramid
            for (int j = 0; j < height - i - 1; j++) {
                printf(" ");
            }
            //Left pyramid
            for (int j = 0; j <= i; j++) {
                printf("#");
            }

            //Gap between pyramids
            printf("  ");

            //Right pyramid
            for (int j = 0; j <= i; j++) {
                printf("#");
            }

            printf("\n");
        }
    }
}
