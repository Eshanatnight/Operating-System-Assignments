/*
Question:[4]
Program to create four processes (1 parent and 3 children) where they terminates in a sequence
as follows:
(a) Parent process terminates at last
(b) First child terminates before parent and after second child.
(c) Second child terminates after last and before first child.
(d) Third child terminates first.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void printProcessDetails(char *processName, int pid, int ppid, int pgid)
{
    wait(NULL);
    printf("\nProcess Name:         %s\n", processName);
    printf("Process ID:           %d\n", pid);
    printf("Parent Process ID:    %d\n", ppid);
    printf("Process Group ID:     %d\n", pgid);
}


int main()
{
    wait(NULL);

    pid_t pid;
    pid = fork();  // Fork from the patrent process

    if(pid == 0)
    {
        pid = fork(); // fork from the child process 1

        if(pid == 0)
        {
            pid = fork(); // fork from the child process 2

            if(pid == 0)
                printProcessDetails("Child Process 3", getpid(), getppid(), getpgrp());
                // Details of child process 3 as it terminates

            else
            {
                // Child process 2 terminates after child process 3
                // Details of child process 2 as it terminates
                printProcessDetails("Child Process 2", getpid(), getppid(), getpgrp());
            }
        }

        else
        {
            // Child process 1 terminates after child process 2
            // Details of child process 1 as it terminates
            printProcessDetails("Child Process 1", getpid(), getppid(), getpgrp());
        }
    }

    else
    {
        // Parent process terminates at last
        // Details of parent process as it terminates
        printProcessDetails("Parent Process", getpid(), getppid(), getpgrp());
    }

    return 0;
}