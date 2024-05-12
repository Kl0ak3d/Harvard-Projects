// Simulate

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

    print_family(p, 0);

    free_family(p);
}

// Create a individual
person *create_family(int generations)
{

    person *p = malloc(sizeof(person));

    if (generations > 1)
    {
        // Create two new parents
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // Pointers
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);



        // Pointers
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];

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

    if (p == NULL)
    {
        return;
    }


    free_family(p->parents[0]);
    free_family(p->parents[1]);

    
    free(p);

}
