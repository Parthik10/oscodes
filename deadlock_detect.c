// // deadlock detect

// Algorithm Explanation (Deadlock Detection Algorithm):
// Input Data:

// Allocation Matrix (alloc): Number of resources of each type currently allocated to each process.
// Max Matrix (max): Maximum number of resources of each type a process may need.
// Available Vector (avail): Number of available resources of each type.
// Compute Need Matrix (need) as need[i][j] = max[i][j] - alloc[i][j].
// Initialization:

// work vector is initialized with the avail values.
// finish array is initialized to false for all processes (indicating no process is yet finished).
// Process Simulation:

// Repeat for all processes:
// Find an unfinished process (finish[p] == false) whose needs (need[p][j]) can be satisfied with the current available resources (work[j]).
// If such a process is found:
// Simulate that process completing by adding its allocated resources (alloc[p][j]) back to work.
// Mark that process as finished (finish[p] = true).
// Continue checking for other processes.
// If no such process is found in an iteration, declare a deadlock.
// Deadlock Detection:

// If all processes finish (finish[p] == true for all p), there is no deadlock.
// If some processes remain unfinished (finish[p] == false for any p), a deadlock exists.

#include <stdio.h>
#include <stdbool.h>

#define P 5 // Number of processes
#define R 3 // Number of resource types

// Global matrices and arrays
int alloc[P][R], max[P][R], avail[R], need[P][R];

// Function to check for deadlock
bool isDeadlocked()
{
    int work[R];         // Work array to simulate resource availability
    int finish[P] = {0}; // Finish array to track which processes have finished
    
    // Initialize work array with available resources
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    // Simulate process execution
    for (int count = 0; count < P;)
    {
        bool found = false; // Flag to check if at least one process can proceed

        // Iterate through each process
        for (int p = 0; p < P; p++)
        {
            if (!finish[p]) // Process has not finished yet
            {
                // Check if process p can proceed
                bool canProceed = true;
                for (int j = 0; j < R; j++)
                {
                    // If need exceeds available resources, process cannot proceed
                    if (max[p][j] - alloc[p][j] > work[j])
                    {
                        canProceed = false;
                        break;
                    }
                }

                if (canProceed)
                {
                    // Simulate process completion:
                    // Add allocated resources of process p to work array
                    for (int j = 0; j < R; j++)
                        work[j] += alloc[p][j];
                    
                    // Mark process as finished
                    finish[p] = 1;
                    count++;
                    found = true; // At least one process proceeded
                }
            }
        }

        // If no process could proceed in this iteration, deadlock exists
        if (!found)
            return true;
    }

    // If all processes finish successfully, no deadlock
    return false;
}

int main()
{
    // Input allocation matrix
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &alloc[i][j]);

    // Input max matrix
    printf("Enter max matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &max[i][j]);

    // Input available resources
    printf("Enter available resources:\n");
    for (int i = 0; i < R; i++)
        scanf("%d", &avail[i]);

    // Check if the system is in a deadlock
    if (isDeadlocked())
        printf("Deadlock detected.\n");
    else
        printf("No deadlock detected.\n");

    return 0;
}
