// 1: Sort the queue of disk requests in ascending order.
// 2: If the direction is `up`:
// 3: Process requests greater than the current position in ascending order.
// 	4: 	If the disk head reaches the highest cylinder or the highest request, move the head to the first cylinder (position 0).
// 	5: 	Process remaining requests in ascending order (starting from the lowest request).
// 	6: 	 Else if the direction is `down`:
// 	7: 	Process requests less than or equal to the current position in descending order.
// 8:   If the disk head reaches the lowest cylinder or the lowest request, move the head to the highest cylinder (last cylinder).
// 	9: 	Process remaining requests in descending order (starting from the highest request).
//    10: 	   Process requests less than or equal to the current position in descending order.
// 11.	For each serviced request, calculate the distance from the current position to the request and add it to `totalHeadMovement`. Update `currentPosition` to the request's position.
// 12.	Output the sequence of requests serviced and `totalHeadMovement`.

#include <stdio.h>
#include <stdlib.h>
#define DISK_SIZE 200
void sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void cscan(int arr[], int n, int head)
{
    int seek_count = 0;
    int distance, cur_track;
    int left[n], right[n];
    int left_count = 0, right_count = 0;
    int seek_sequence[2 * n];
    int seq_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < head)
        {
            left[left_count++] = arr[i];
        }
        if (arr[i] > head)
        {
            right[right_count++] = arr[i];
        }
    }
    sort(left, left_count);
    sort(right, right_count);
    for (int i = 0; i < right_count; i++)
    {
        cur_track = right[i];
        seek_sequence[seq_index++] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    seek_count += (DISK_SIZE - 1);
    head = 0;
    for (int i = 0; i < left_count; i++)
    {
        cur_track = left[i];
        seek_sequence[seq_index++] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is:\n");
    for (int i = 0; i < seq_index; i++)
    {
        printf("%d\n", seek_sequence[i]);
    }
}

int main()
{
    int n, head;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the disk request positions: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    cscan(arr, n, head);
    return 0;
}
