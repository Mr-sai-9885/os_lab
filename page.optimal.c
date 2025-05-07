#include <stdio.h>
#include <stdbool.h>

// Function to check if a page is already in frames
bool isInFrames(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page)
            return true;
    }
    return false;
}

// Function to find the best frame to replace (farthest future use)
int findOptimal(int pages[], int totalPages, int frames[], int frameCount, int currentIndex) {
    int farthest = currentIndex;
    int indexToReplace = -1;

    for (int i = 0; i < frameCount; i++)
    {
        int j;
        for (j = currentIndex; j < totalPages; j++)
        {
            if (frames[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    indexToReplace = i;
                }
                break;
            }
        }
        if (j == totalPages)  // page not used again
            return i;
    }

    return (indexToReplace == -1) ? 0 : indexToReplace;
}

int main() {
    int pages[50], frames[10],replaceIndex;
    int totalPages, frameCount;
    int pageFaults = 0;

    printf("Enter total number of pages: ");
    scanf("%d", &totalPages);

    printf("Enter the page reference string:\n");
    for (int i = 0; i < totalPages; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    // Initialize all frames as empty (-1)
    for (int i = 0; i < frameCount; i++)
    {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for (int i = 0; i < totalPages; i++)
    {
        if (!isInFrames(frames, frameCount, pages[i]))
        {
            // If frames are not full, use the next free one
            if (i < frameCount)
            {
                replaceIndex = i;
            }
            else
            {
                // Choose best page to replace using optimal logic
                replaceIndex = findOptimal(pages, totalPages, frames, frameCount, i + 1);
            }

            frames[replaceIndex] = pages[i];
            pageFaults++;
        }

        // Show frame content
        printf("%d\t", pages[i]);
        for (int j = 0; j < frameCount; j++)
        {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
