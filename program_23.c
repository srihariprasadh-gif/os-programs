#include <stdio.h>

int main()
{
    int n, i, search;

    printf("Enter number of records: ");
    scanf("%d", &n);

    int record[n];

    printf("Enter records:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &record[i]);
    }

    printf("Enter record position to access: ");
    scanf("%d", &search);

    if(search < 1 || search > n)
    {
        printf("Invalid record position!\n");
        return 0;
    }

    printf("\nReading records sequentially:\n");

    for(i = 0; i < search; i++)
    {
        printf("Record %d = %d\n", i + 1, record[i]);
    }

    printf("\nRequired record found: Record %d = %d\n",
           search, record[search - 1]);

    return 0;
}








