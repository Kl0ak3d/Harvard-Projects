#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height = get_int("Height: ");

    // Loop over rows
    for (int i = 0; i < height; i++) {
        // Print spaces for left pyramid
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        // Print hashes for left pyramid
        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        // Print gap between pyramids
        printf("  ");

        // Print hashes for right pyramid
        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        printf("\n");
    }
}
