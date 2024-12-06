// 1: Sort the queue of disk requests in ascending order.
// 2: Divide the requests into two groups:
// 3: Requests less than or equal to the current position.
// 4: 	Requests greater than the current position.
// 5: 	If the direction is `up`:
// 6: 	Process requests greater than the current position in ascending order.
// 7: 	If the disk head reaches the highest cylinder or the highest request, reverse direction.
// 8: 	Process remaining requests in descending order.
// 9: 	Else if the direction is `down`:
// 10: 	   Process requests less than or equal to the current position in descending order.
// 11. 	If the disk head reaches the lowest cylinder or the lowest request, reverse direction.
// 12. 	Process remaining requests in ascending order.
// 13. 	For each serviced request, calculate the distance from the current position to the request and add it to `totalHeadMovement`. Update `currentPosition` to the request's position.
// 14. 	Output the sequence of requests serviced and `totalHeadMovement`.

#include <stdio.h>
#include <stdlib.h>

void scanDiskScheduling(int requests[], int n, int head, int diskSize)
{
    int totalMovement = 0;
    int i;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (requests[j] > requests[j + 1])
            {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    int direction = (head < diskSize / 2) ? 1 : 0;
    printf("\nSCAN Disk Scheduling (Direction: %s):\n", (direction == 1) ? "High to Low" : "Low to High");
    if (direction == 1)
    {
        for (i = 0; i < n; i++)
        {
            if (requests[i] >= head)
            {
                totalMovement += abs(head - requests[i]);
                printf("Seek movement from %d to %d, Seek: %d\n", head, requests[i], abs(head - requests[i]));
                head = requests[i];
            }
        }
        totalMovement += abs(head - (diskSize - 1));
        printf("Move from %d to %d, Seek movement: %d\n", head, diskSize - 1, abs(head - (diskSize - 1)));
        head = diskSize - 1;
        for (i = n - 1; i >= 0; i--)
        {
            if (requests[i] < head)
            {
                totalMovement += abs(head - requests[i]);
                printf("Seek movement from %d to %d, Seek: %d\n", head, requests[i], abs(head - requests[i]));
                head = requests[i];
            }
        }
    }
    else
    {
        for (i = n - 1; i >= 0; i--)
        {
            if (requests[i] <= head)
            {
                totalMovement += abs(head - requests[i]);
                printf("Seek movement from %d to %d, Seek: %d\n", head, requests[i], abs(head - requests[i]));
                head = requests[i];
            }
        }
        totalMovement += abs(head - 0);
        printf("Move from %d to 0, Seek movement: %d\n", head, abs(head - 0));
        head = 0;
        for (i = 0; i < n; i++)
        {
            if (requests[i] > head)
            {
                totalMovement += abs(head - requests[i]);
                printf("Seek movement from %d to %d, Seek: %d\n", head, requests[i], abs(head - requests[i]));
                head = requests[i];
            }
        }
    }
    printf("Total seek movement: %d\n", totalMovement);
}

int main()
{
    int n, head, diskSize;
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

    printf("Enter the disk size (e.g., 200 for cylinders 0 to 199): ");
    scanf("%d", &diskSize);

    scanDiskScheduling(requests, n, head, diskSize);

    return 0;
}
