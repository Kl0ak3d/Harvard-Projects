#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{

    srand(time(0));
    person *p = create_family(GENERATIONS);
    // Print family tree
    print_family(p, 0);
    // Free memory
    free_family(p);
}

// Create a individual
person *create_family(int generations)
{

    person *p = malloc(sizeof(person));

    if (generations > 1)
    {
        // Pointers
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        int v = rand() % 2;
        if(v == 0)
        {
            p->alleles[0] = p->parents[0]->alleles[0];
        }
        else
        {
            p->alleles[0] = p->parents[0]->alleles[1];
        }

        int k = rand() % 2;
        if(v == 0)
        {
            p->alleles[1] = p->parents[1]->alleles[0];
        }
        else
        {
            p->alleles[1] = p->parents[1]->alleles[1];
        }
    }


    else
    {
        // Pointers
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        // Pointers
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }


    return p;
}


void free_family(person *p)
{

    if(p == NULL)
    {
        return;
    }
    // Free Family
    if(p->parents[0] != NULL && p->parents[1] != NULL)
    {
        free_family(p->parents[0]);
        free_family(p->parents[1]);
    }

    // Free Child
    free(p);
}

// Print
void print_family(person *p, int generation)
{

    if (p == NULL)
    {
        return;
    }

    // Print
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Blood Type
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
