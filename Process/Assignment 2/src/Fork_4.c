// Question[4]: Check the output by using getpid to get the process ids of different process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
    {
        fprintf(stdout, "Child Process Details: \n");
        fprintf(stdout, "I am the child process\n");
        fprintf(stdout, "My PID is %d\n", getpid());
        fprintf(stdout, "My Parent PID is %d\n", getppid());
    }

    else if (pid > 0)
    {
        // Used the wait function to wait for the child process to finish

        wait(NULL);
        fprintf(stdout, "\n\nChild Process Terminated...\n");
        fprintf(stdout, "Parent Process Details: \n");
        fprintf(stdout, "I am the parent process\n");
        fprintf(stdout, "My PID is %d\n", getpid());

    }

    else
        fprintf(stderr, "There was an error in creating the Child Proces\n");


    return 0;
}