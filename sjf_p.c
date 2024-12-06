//sjf p
#include <stdio.h>
#include <limits.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, min_index = 0;
    while (complete < n) {
        int min_remaining = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (rt[j] > 0 && rt[j] < min_remaining) {
                min_remaining = rt[j];
                min_index = j;
            }
        }
        rt[min_index]--;
        if (rt[min_index] == 0) {
            complete++;
            wt[min_index] = t + 1 - bt[min_index];
        }
        t++;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt);
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

    findavgTime(processes, n, burst_time);
    return 0;
}
