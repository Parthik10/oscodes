// 1: Initialize `totalHeadMovement` as 0.
// 2: Set `currentPosition` to the initial position of the disk head.
// 3: For each request in the queue of disk requests do:
// 4: 	Calculate the absolute distance between `currentPosition` and the request.
// 5: 	    Add this distance to `totalHeadMovement`.
// 6: 	Move the disk head to the request position by setting `currentPosition` to the request.
// 7: 	end for
// 8: 		Output the sequence of requests processed and the `totalHeadMovement`.

#include <stdio.h>
#include <stdlib.h>

void fcfsDiskScheduling(int requests[], int n, int head)
{
    int totalMovement = 0;
    printf("\nFCFS Disk Scheduling:\n");
    for (int i = 0; i < n; i++)
    {
        int movement = abs(requests[i] - head);
        totalMovement += movement;
        printf("Seek movement: %d\n", movement);
        head = requests[i];
    }
    printf("Total seek movement: %d\n", totalMovement);
}

int main()
{
    int n, head;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the request sequence:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    fcfsDiskScheduling(requests, n, head);

    return 0;
}
