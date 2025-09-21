// Simulate genetic inheritance of blood type
#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srandom(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // Allocate memory for new person
    person *child = malloc(sizeof(person));
    if (child == NULL)
    {
        return NULL;
    }

    // If more generations left
    if (generations > 1)
    {
        // Recursively build parents
        child->parents[0] = create_family(generations - 1);
        child->parents[1] = create_family(generations - 1);

        // Alleles come from parents randomly
        child->alleles[0] = child->parents[0]->alleles[rand() % 2];
        child->alleles[1] = child->parents[1]->alleles[rand() % 2];
    }
    else
    {
        // No parents in oldest generation
        child->parents[0] = NULL;
        child->parents[1] = NULL;

        // Assign random alleles
        child->alleles[0] = random_allele();
        child->alleles[1] = random_allele();
    }

    return child;
}

// Free `p` and all ancestors of `p`
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    // Free parents first
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free current person
    free(p);
}

// Print each family member and their alleles
void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    // Indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Labels
    if (generation == 0)
    {
        printf("Child (Gen %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Gen %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Gen %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Recurse
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele
char random_allele()
{
    int r = random() % 3;
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

