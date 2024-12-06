//round robin
#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int t = 0;
    while (1) {
        int done = 1; // Check if all processes are completed
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0; // Not all processes are done
                if (rt[i] > quantum) {
                    t += quantum;
                    rt[i] -= quantum;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i]; // Waiting time
                    rt[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt, quantum);
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
    int processes[] = { 1, 2, 3 };
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = { 10, 5, 8 };
    int quantum = 3; // Time quantum

    findavgTime(processes, n, burst_time, quantum);
    return 0;
}
