#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    // For each of the candidates...
    for (int i = 0; i < candidate_count; i++)
    {

        // 1. get the current candidate
        candidate currentCandidate = candidates[i];

        // 2. if the current candidate's name is <name>
        if (strcmp(name, currentCandidate.name) == 0)
        {

            // 3. increment their votes
            candidates[i].votes++;

            // 4. this was a valid vote (candidate exists)
            return true;
        }

    }

    // Candidate does not exist
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    // 1. go through the array of candidates (start at 1)
    for (int i = 0; i < candidate_count - 1; i++)
    {

        // go through the array again, minus one
        for (int j = 0; j < candidate_count - i - 1; j++)
        {

            // 2. get this candidate (j)
            candidate currentCandidate = candidates[j];

            // 3. get the next candidate
            candidate nextCandidate = candidates[j + 1];

            // 4. if current candidate's votes < next candidate's votes
            if (currentCandidate.votes < nextCandidate.votes)
            {

                // 5. moving nextCandidate into temporary storage
                candidate temporaryCandidate = currentCandidate;

                // 6. moving currentCandidate into nextCandidate
                candidates[j] = nextCandidate;

                // 7. moving temporary storage into currentCandidate
                candidates[j + 1] = temporaryCandidate;


            }

        }
    }

    // Find the winning candidate
    candidate candidateWinner = candidates[0];

    for (int i = 0; i < candidate_count; i++)
    {

        // if this candidate's votes = the winner's votes,
        if (candidateWinner.votes == candidates[i].votes)
        {
            // print them
            printf("%s\n", candidates[i].name);
        }
    }

    // TODO
    return;
}

