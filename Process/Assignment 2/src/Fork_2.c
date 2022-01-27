// Question[2]: Use fork () system call to execute child and parent process to check the pids

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define std_err(x) fprintf(stderr , (x))

void printProcessDetails(char *processName, pid_t pid, pid_t ppid)
{
    wait(NULL);
    fprintf(stdout, "\nProcess Name:         %s\n", processName);
    fprintf(stdout, "Process ID:           %d\n", pid);
    fprintf(stdout, "Parent Process ID:    %d\n", ppid);
}


int main(int argc, char** argv)
{

    pid_t pid = fork(); // Create the first child process

    if (pid == 0)
    {
        pid_t pid = fork(); // Create the second child process before the child process 1 is terminated. 

        if (pid == 0)
        {
            printProcessDetails(strcat(argv[0], " -> Child Process 2"), getpid(), getppid());
        }

        else
        {
            printProcessDetails(strcat(argv[0], " -> Child Process 1"), getpid(), getppid());
        }
    }


    else
    {
        std_err("Fork Failure\n");
    }
    
    printProcessDetails(argv[0], getpid(), getppid());

    return EXIT_SUCCESS;
}