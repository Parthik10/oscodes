#include <stdio.h>

int main() {
    int frames, n, pageFaults = 0, index = 0;

    printf("Enter number of frames available: ");
    scanf("%d", &frames);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int pages[n], frame[frames];

    printf("Enter the requested page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1; // Empty frame
    }

    // Process each page request
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found, replace the oldest page (FIFO logic)
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames; // Circular increment
            pageFaults++;
        }
    }

    printf("Total number of page faults: %d\n", pageFaults);
    return 0;
}
