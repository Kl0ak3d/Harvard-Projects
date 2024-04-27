//Caesar


#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //  prints error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //  checks if all the second argument contains digits
        string k = argv[1];
        for (int i = 0; i < strlen(k); i++)
        {
            if (isdigit(k[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;

            }
        }

        // converts second argument to int
        int myKey = atoi(k);

        //  plaintext to be ciphered
        string plaintext = get_string("Plaintext: ");

        //  convert to ciphertext
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]))
            {
                //  change base so that A is 0
                //  minus capital A ASCII value by 65 it becomes 0
                plaintext[i] = (plaintext[i] - 65);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 65);

            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] - 97);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 97);


            }
            if (isalpha(plaintext[i]) == 0)
            {
                plaintext[i] = plaintext[i];

            }
        }
        printf("Ciphertext: %s", plaintext);
        printf("\n");

    }

}
