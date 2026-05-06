#include <stdio.h>

int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, k, page_faults = 0;
    int count = 0, found, pos, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check if page already exists
        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                count++;
                time[j] = count;  // update recent use
                break;
            }
        }

        // Page fault
        if(found == 0)
        {
            min = time[0];
            pos = 0;

            // Find least recently used
            for(j = 1; j < f; j++)
            {
                if(time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            count++;
            time[pos] = count;
            page_faults++;
        }

        // Print frames
        printf("%d\t", pages[i]);
        for(k = 0; k < f; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}

