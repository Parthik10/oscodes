#include <stdio.h>

int main() {
    int frames, n, pageFaults = 0, counter = 0;

    printf("Enter number of frames available: ");
    scanf("%d", &frames);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int pages[n], frame[frames], time[frames];

    printf("Enter the requested page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames and time
    for (int i = 0; i < frames; i++) {
        frame[i] = -1; // Empty frame
        time[i] = 0;   // Reset time for each frame
    }

    // Process each page request
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                time[j] = ++counter; // Update usage time
                break;
            }
        }

        // If not found, replace the least recently used page (LRU logic)
        if (!found) {
            int pos = 0, minTime = time[0];

            // Find the least recently used page
            for (int j = 1; j < frames; j++) {
                if (time[j] < minTime) {
                    minTime = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];  // Replace page
            time[pos] = ++counter;  // Update usage time
            pageFaults++;
        }
    }

    printf("Total number of page faults: %d\n", pageFaults);
    return 0;
}
