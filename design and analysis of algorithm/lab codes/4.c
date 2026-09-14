#include <stdio.h>

#define N 4

// Function to find the celebrity
int findCelebrity(int M[N][N])
{
    int candidate = 0;

    // Step 1: Find a possible celebrity
    for (int i = 1; i < N; i++)
    {
        // If candidate knows i,
        // candidate cannot be a celebrity
        if (M[candidate][i] == 1)
        {
            candidate = i;
        }
    }

    // Step 2: Verify the candidate
    for (int i = 0; i < N; i++)
    {
        if (i != candidate)
        {
            // Celebrity should know nobody
            // AND everybody should know celebrity

            if (M[candidate][i] == 1 ||
                M[i][candidate] == 0)
            {
                return -1;
            }
        }
    }

    // Candidate satisfies both conditions
    return candidate;
}

int main()
{
    int M[N][N] =
    {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int celebrity = findCelebrity(M);

    if (celebrity == -1)
    {
        printf("There is no celebrity.\n");
    }
    else
    {
        printf("Person %d is the celebrity.\n", celebrity);
    }

    return 0;
}