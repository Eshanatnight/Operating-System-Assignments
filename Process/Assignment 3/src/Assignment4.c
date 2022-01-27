/*
    Question[4]: Write a program to create a child process, make the parent process intelligent enough to re spawn a new child if somehow the existing child being terminated/killed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    fprintf(stdout, "Question: Write a program to create a child process, make the parent process intelligent enough to re spawn a new child if somehow the existing child being terminated/killed.\n");
    pid_t pid;

    for(int i = 0; i < 5; i++)
    {
        pid = fork();
        if(pid == 0)
        {
            fprintf(stdout, "Child process ID: %d\n", getpid());
            fprintf(stdout, "Parent Process ID: %d\n", getppid());
            sleep(2);
            if(i < 4) fprintf(stdout, "After 2 seconds, child process terminates\n\n\n");
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}