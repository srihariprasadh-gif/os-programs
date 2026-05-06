#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, size, direction;
    int request[20], i, j, temp;
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

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

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

    printf("\nSCAN Order:\n");

    if(direction == 1) // moving right
    {
        // Move right
        for(i = 0; i < n; i++)
        {
            if(request[i] >= head)
            {
                printf("%d -> ", request[i]);
                total_movement += abs(request[i] - head);
                head = request[i];
            }
        }

        // Go to end
        total_movement += abs((size - 1) - head);
        head = size - 1;

        // Move left
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] < head)
            {
                printf("%d -> ", request[i]);
                total_movement += abs(request[i] - head);
                head = request[i];
            }
        }
    }
    else // moving left
    {
        // Move left
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] <= head)
            {
                printf("%d -> ", request[i]);
                total_movement += abs(request[i] - head);
                head = request[i];
            }
        }

        // Go to start
        total_movement += abs(head - 0);
        head = 0;

        // Move right
        for(i = 0; i < n; i++)
        {
            if(request[i] > head)
            {
                printf("%d -> ", request[i]);
                total_movement += abs(request[i] - head);
                head = request[i];
            }
        }
    }

    printf("\nTotal Head Movement = %d\n", total_movement);

    return 0;
}

