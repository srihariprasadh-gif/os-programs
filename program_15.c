int main() {
    int n = 5; // number of processes
    int m = 3; // number of resource types

    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int avail[3] = {3, 3, 2};

    int need[5][3];
    int finish[5] = {0};
    int safeSeq[5];

    int i, j, k, count = 0;

    // Calculate Need matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Need Matrix:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i);
        for(j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Banker’s Algorithm
    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canRun = 1;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if(canRun == 1) {
                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in safe state.\n");
            printf("Deadlock may occur.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\n");
    printf("Safe Sequence: ");

    for(i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if(i != n - 1) {
            printf(" -> ");
        }
    }

    return 0;
}