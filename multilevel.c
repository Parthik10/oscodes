//multilevel
#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[], int queue) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (i < queue) {
            wt[i] = t;
            t += bt[i];
        } else {
            wt[i] = t;
            t += bt[i];
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int queue) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt, queue);
    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;
    printf("Processes | Burst Time | Waiting Time | Turn-Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t   |   %d\t   |   %d\t   |   %d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
}

int main() {
    int processes[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = { 10, 5, 8, 12, 6 };
    int high_priority_queue = 3; // Number of processes in high priority queue

    findavgTime(processes, n, burst_time, high_priority_queue);
    return 0;
}
