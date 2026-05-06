#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, size, i, j, temp;
    int request[20];
    int total_movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // Sort requests
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nC-SCAN Order:\n");

    // Move right (higher values)
    for(i = 0; i < n; i++)
    {
        if(request[i] >= head)
        {
            printf("%d -> ", request[i]);
            total_movement += abs(request[i] - head);
            head = request[i];
        }
    }

    // Go to end of disk
    total_movement += abs((size - 1) - head);
    head = size - 1;

    // Jump to beginning (0)
    total_movement += abs(head - 0);
    head = 0;

    // Continue servicing remaining requests
    for(i = 0; i < n; i++)
    {
        if(request[i] < head)
        {
            printf("%d -> ", request[i]);
            total_movement += abs(request[i] - head);
            head = request[i];
        }
    }

    printf("\nTotal Head Movement = %d\n", total_movement);

    return 0;
}

