#include <stdio.h>


void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int rt[n]; // Remaining burst time array initialized
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];              // Initialize remaining burst time with burst time (initially equal)
    }

    int complete = 0, t = 0, min_index; // Complete: count of completed processes, t: current time, min_index: index of the process with the shortest burst time

    while (complete < n) { // While there are processes to be completed
        min_index = -1; // Reset the minimum index for each iteration
        for (int j = 0; j < n; j++) { // Traverse all processes to find the one with the smallest remaining burst time
            if (rt[j] > 0 && (min_index == -1 || rt[j] < rt[min_index])) { 
                min_index = j; // Update the index of the shortest job
            }
        }
        // After the process with minimum burst time is selected:
        t += rt[min_index]; // Add its burst time to the current time
        wt[min_index] = t - bt[min_index]; // Calculate waiting time: total time elapsed - burst time
        rt[min_index] = 0; // Mark this process as completed by setting its remaining burst time to 0
        complete++; // Increment the number of completed processes
    }
}

// Function to calculate the turnaround time for each process
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
    }
}

// Function to calculate and print the average waiting time and turnaround time
void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n]; // Arrays for waiting time and turnaround time
    findWaitingTime(processes, n, bt, wt); // Function call to calculate waiting time
    findTurnAroundTime(processes, n, bt, wt, tat); // Function call to calculate turnaround time

    float total_wt = 0, total_tat = 0; // Variables to store total waiting time and total turnaround time
    printf("Processes | Burst Time | Waiting Time | Turn-Around Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i]; // Accumulate total waiting time
        total_tat += tat[i]; // Accumulate total turnaround time
        // Print the details for each process: Process ID, Burst Time, Waiting Time, Turnaround Time
        printf("   %d\t   |   %d\t   |   %d\t   |   %d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and display the average waiting time and average turnaround time
    printf("\nAverage waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
}

int main() {
    // Hardcoded process IDs and burst times for testing
    int processes[] = { 1, 2, 3 }; // Process IDs
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes
    int burst_time[] = { 10, 5, 8 }; // Burst times of processes

    // Call the function to compute and display average waiting time and turnaround time
    findavgTime(processes, n, burst_time);
    return 0;
}
