//priority
#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[]) {
    int complete = 0, t = 0, min_priority;
    int rt[n];
    
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    while (complete < n) {
        min_priority = -1;
        for (int j = 0; j < n; j++) {
            if (rt[j] > 0 && (min_priority == -1 || priority[j] < priority[min_priority])) {
                min_priority = j;
            }
        }
        t += rt[min_priority];
        wt[min_priority] = t - bt[min_priority];
        rt[min_priority] = 0;
        complete++;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt, priority);
    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;
    printf("Processes | Burst Time | Waiting Time | Turn-Around Time | Priority\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t   |   %d\t   |   %d\t   |   %d\t   |   %d\n", processes[i], bt[i], wt[i], tat[i], priority[i]);
    }
    printf("\nAverage waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
}

int main() {
    int processes[] = { 1, 2, 3 };
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = { 10, 5, 8 };
    int priority[] = { 2, 1, 3 }; // Lower number = higher priority

    findavgTime(processes, n, burst_time, priority);
    return 0;
}
