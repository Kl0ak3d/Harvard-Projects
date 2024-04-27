//Readability

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //input

    string input = get_string("Text: ");
    int n = strlen(input);

    //count

    int lettercount = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(input[i]))
        {
            lettercount++;
        }

    }
    //count the word by finding charecter before whitespace

    int wordcount = 1;
    for (int i = 0; i < n; i++)
    {
        if (isspace(input[i]) && isgraph(input[i + 1]))
        {
            wordcount++;
        }
    }
    //count sentences

    int sentcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(input[i]) && input[i + 1] == '.')
        {
            sentcount++;
        }
        else if (isalpha(input[i]) && input[i + 1] == '!')
        {
            sentcount++;
        }
        else if (isalpha(input[i]) && input[i + 1] == '?')
        {
            sentcount++;
        }
    }
    //calculating

    float l = (float) lettercount / wordcount * 100;
    float s = (float) sentcount / wordcount * 100;
    float grade = 0.0588 * l - 0.296 * s - 15.8;
    printf("%i %i %i\n", lettercount, wordcount, sentcount);

    //round up & print

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", (int)round(grade));
    }
    else
    {
        printf("Grade 16+\n");
    }
}
