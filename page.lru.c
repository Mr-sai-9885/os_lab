#include <stdio.h>

int main() {
    int pages[50], frames[10], recent[10];
    int n, f, i, j, k, found, pos, pageFaults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames and recent-use tracker
    for (i = 0; i < f; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++)
    {
        found = 0;

        // Check if page is already in frames
        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                recent[j] = i; // Update recent use
                break;
            }
        }

        // If not found (page fault)
        if (!found)
        {
            pos = 0;

            // Find least recently used page's position
            for (j = 1; j < f; j++) {
                if (recent[j] < recent[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            recent[pos] = i;
            pageFaults++;
        }

        // Print current frame status
        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++)
        {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}

