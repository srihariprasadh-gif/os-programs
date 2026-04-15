//Create a new process by invoking the appropriate system call. Get the process identifier of the currently running process and its respective parent using system calls and display the same using a C program.
#include<stdio.h>
#include<unistd.h> 
int main()
{
printf("Process ID: %d\n", getpid() );
printf("Parent Process ID: %d\n", getpid() );
return 0;
}
 