
#include <stdio.h>
#include <string.h>

int main()
{
    char user[10][20], file[10][10][20];
    int fileCount[10];
    int u = 0, choice, i, j;
    char uname[20], fname[20];

    for(i = 0; i < 10; i++)
        fileCount[i] = 0;

    while(1)
    {
        printf("\n--- Two Level Directory ---\n");
        printf("1. Create User Directory\n");
        printf("2. Create File\n");
        printf("3. Display Directory\n");
        printf("4. Search File\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter user directory name: ");
                scanf("%s", uname);

                strcpy(user[u], uname);
                fileCount[u] = 0;
                u++;

                printf("User directory created!\n");
                break;

            case 2:
                printf("Enter user directory name: ");
                scanf("%s", uname);

                for(i = 0; i < u; i++)
                {
                    if(strcmp(user[i], uname) == 0)
                    {
                        printf("Enter file name: ");
                        scanf("%s", fname);

                        strcpy(file[i][fileCount[i]], fname);
                        fileCount[i]++;

                        printf("File created!\n");
                        break;
                    }
                }

                if(i == u)
                    printf("User directory not found!\n");

                break;

            case 3:
                printf("\nDirectory Structure:\n");

                for(i = 0; i < u; i++)
                {
                    printf("\nUser: %s\n", user[i]);

                    for(j = 0; j < fileCount[i]; j++)
                    {
                        printf("  %s\n", file[i][j]);
                    }
                }
                break;

            case 4:
                printf("Enter user directory name: ");
                scanf("%s", uname);

                printf("Enter file name to search: ");
                scanf("%s", fname);

                for(i = 0; i < u; i++)
                {
                    if(strcmp(user[i], uname) == 0)
                    {
                        for(j = 0; j < fileCount[i]; j++)
                        {
                            if(strcmp(file[i][j], fname) == 0)
                            {
                                printf("File found!\n");
                                break;
                            }
                        }

                        if(j == fileCount[i])
                            printf("File not found!\n");

                        break;
                    }
                }

                if(i == u)
                    printf("User directory not found!\n");

                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
