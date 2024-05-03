//Plurality Problem Set
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//number of candidates
#define MAX 9

//Name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

//Array
candidate candidates[MAX];

//Number
int candidate_count;

//Function
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    //Check
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    //Populate array
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    //Loop over
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        //Check
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    //Display winner
    print_winner();

}

//Update vote
bool vote(string name)
{
    // TODO
    //Search for mathing canditate name
    for (int i = 0; i < candidate_count; i++){
        if(strcmp(candidates[i].name, name) == 0){
            candidates[i].votes += 1;
            return true;
        }
    }

    return false;
}

// Print the winner
void print_winner(void)
{
    // TODO
    int maxvotes = 0;
    //Find highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }
    // print winners
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

   return;

}
