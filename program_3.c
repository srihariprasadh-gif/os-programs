#include<stdio.h>
int main()
{
int A[100][4];
int i, j, n, total = 0, index, temp;float
avg_wt, avg_tat;
printf("Enter number of process: ");
scanf("%d", &n);
printf("Enter Burst Time:\n");
for (i= 0; i <n; i++)
{
printf("P%d: ", i + 1);
scanf("%d", &A[i][1]);
A[i][0] = i + 1;
}
for (i = 0; i< n; i++) {
index = i;
for (j = i + 1; j < n; j++)
if (A[j][1] < A[index][1])
index = j;
temp = A[i][1];
A[i][1] =A[index][1];
A[index][1]= temp;

temp = A[i][0];
 A[i][0] =A[index][0];
 A[index][0]= temp;
}
A[0][2] = 0;
for (i = 1; i < n; i++) {
A[i][2] = 0;
for (j = 0; j < i; j++)
A[i][2] += A[j][1];
total += A[i][2];
}
for (j = i + 1; j < n; j++)
if (A[j][1] < A[index][1])
index = j;
temp = A[i][1];
 A[i][1] =A[index][1];
 A[index][1]= temp;

temp = A[i][0];
 A[i][0] =A[index][0];
 A[index][0]= temp;
}
A[0][2] = 0;
for (i = 1; i < n; i++) {
A[i][2] = 0;
for (j = 0; j < i; j++)
A[i][2] += A[j][1];
total += A[i][2];
}