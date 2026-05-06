#include <stdio.h>
#include <string.h>

int main()
{
    char files[20][20];
    int n = 0, choice;
    char fname[20];
    int i, found;

    while(1)
    {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n");
        printf("2. Display Files\n");
        printf("3. Search File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter file name: ");
                scanf("%s", fname);

                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(strcmp(files[i], fname) == 0)
                    {
                        found = 1;
                        break;
                    }
                }

                if(found)
                    printf("File already exists!\n");
                else
                {
                    strcpy(files[n], fname);
                    n++;
                    printf("File created!\n");
                }
                break;

            case 2:
                printf("\nFiles in Directory:\n");
                for(i = 0; i < n; i++)
                    printf("%s\n", files[i]);
                break;

            case 3:
                printf("Enter file name to search: ");
                scanf("%s", fname);

                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(strcmp(files[i], fname) == 0)
                    {
                        found = 1;
                        break;
                    }
                }

                if(found)
                    printf("File found!\n");
                else
                    printf("File not found!\n");
                break;

            case 4:
                printf("Enter file name to delete: ");
                scanf("%s", fname);

                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(strcmp(files[i], fname) == 0)
                    {
                        found = 1;
                        break;
                    }
                }

                if(found)
                {
                    for(int j = i; j < n - 1; j++)
                        strcpy(files[j], files[j + 1]);

                    n--;
                    printf("File deleted!\n");
                }
                else
                    printf("File not found!\n");

                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

