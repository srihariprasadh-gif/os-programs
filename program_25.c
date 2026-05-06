#include <stdio.h>

int main()
{
    int n, i;
    int block[20];

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter disk block numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &block[i]);
    }

    printf("\nLinked Allocation:\n");

    for(i = 0; i < n - 1; i++)
    {
        printf("Block %d -> points to Block %d\n", block[i], block[i + 1]);
    }

    printf("Block %d -> NULL\n", block[n - 1]);

    printf("\nDirectory Information:\n");
    printf("First Block = %d\n", block[0]);
    printf("Last Block  = %d\n", block[n - 1]);

    return 0;
}



