//banker algo & detect deadlock
#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

int alloc[P][R], max[P][R], avail[R], need[P][R];

bool isSafe() {
    int work[R], finish[P] = {0};
    for (int i = 0; i < R; i++) work[i] = avail[i];

    for (int count = 0; count < P; ) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int j = 0; j < R; j++)
                    if (need[p][j] > work[j]) {
                        canAllocate = false; break;
                    }
                if (canAllocate) {
                    for (int j = 0; j < R; j++)
                        work[j] += alloc[p][j];
                    finish[p] = 1; count++; found = true;
                }
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R) 
            scanf("%d", &alloc[i][j]);
    
    printf("Enter max matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R)
            scanf("%d", &max[i][j]);
    
    printf("Enter available resources:\n");
    for (int i = 0; i < R; i++) scanf("%d", &avail[i]);

    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    if (isSafe())
        printf("System is in a safe state.\n");
    else
        printf("System is not in a safe state.\n");

    return 0;
}
