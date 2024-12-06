//fcfs
// Waiting Time Calculation:
// For the first process, the waiting time is 0 since it executes immediately.
// For subsequent processes, the waiting time is the sum of the burst times of all previous processes. The waiting time of a process is determined by the total time spent by the earlier processes in the queue.
// Turnaround Time Calculation:

// Turnaround time is calculated as the sum of the burst time and the waiting time for each process:
// TAT = BT + WT.
// Average Waiting and Turnaround Time:

// Once the waiting times and turnaround times for all processes are calculated, the averages are found by dividing the sum of all waiting times and turnaround times by the number of processes.


#include <stdio.h>
// Function to calculate waiting time for each process
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1]; // Waiting time of the current process
    }
}

// Function to calculate turnaround time for each process
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Turnaround time is the burst time + waiting time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Calculate TAT for each process
    }
}

// Function to calculate average waiting time and average turnaround time
void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    
    // Function calls to calculate waiting time and turnaround time
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    // Displaying the process details in a table format
    printf("Processes | Burst Time | Waiting Time | Turn-Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        // Printing the details for each process
        printf("   %d\t   |   %d\t   |   %d\t   |   %d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Calculating and displaying the average waiting time and turnaround time
    printf("\nAverage waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
}

int main() {
    int n;
    
    // Taking user input for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    // Taking user input for the process IDs and burst times
    printf("Enter the process IDs:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;  // Assuming process IDs start from 1
    }

    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    // Calling the function to calculate average times
    findAvgTime(processes, n, burst_time);

    return 0;
}