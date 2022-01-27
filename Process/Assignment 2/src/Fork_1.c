// Question[1]:  Running multiple fork system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

void printProcessDetails(char *processName, pid_t pid, pid_t ppid)
{
    wait(NULL);
    fprintf(stdout, "\nProcess Name:         %s\n", processName);
    fprintf(stdout, "Process ID:           %d\n", pid);
    fprintf(stdout, "Parent Process ID:    %d\n", ppid);
}


int main(int argc, char *argv[])
{
    // Prints The Process Details of the Main Executable Process
    printProcessDetails(argv[0], getpid(), getppid());
    pid_t pid = fork(); // Create the first child process

    if (pid == 0)
    {
        pid = fork(); // Create the second child process

        if(pid == 0)
        {
            printProcessDetails(strcat(argv[0]," -> Child Process 2"), getpid(), getppid());
        }
        
        else
        {
            printProcessDetails(strcat(argv[0], " -> Child Process 1"), getpid(), getppid());
        }
    }


    return EXIT_SUCCESS;
}
