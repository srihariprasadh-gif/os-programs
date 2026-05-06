#include <stdio.h>

int main()
{
    int n, i, indexBlock[20], choice;

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers (index block):\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &indexBlock[i]);
    }

    printf("\nIndex Block Entries:\n");
    for(i = 0; i < n; i++)
    {
        printf("Block %d -> %d\n", i + 1, indexBlock[i]);
    }

    printf("\nEnter block number to access: ");
    scanf("%d", &choice);

    if(choice < 1 || choice > n)
    {
        printf("Invalid block!\n");
    }
    else
    {
        printf("Block %d is stored at disk location %d\n",
               choice, indexBlock[choice - 1]);
    }

    return 0;
}

