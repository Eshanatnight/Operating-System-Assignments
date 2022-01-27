/*
    Question[2]: Write a program to show how Zombie process can cause problem. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    fprintf(stdout, "Question: Write a program to show how Zombie process can cause problem.\n");
    pid_t pid;
    pid = fork();

    if (pid > 0)
    {
        fprintf(stdout, "Parent Process\n");
        sleep(50);
        fprintf(stdout, "After 50 seconds....\n");
        fprintf(stdout, "Parent Process Terminates\n");
    }

    else if(pid == 0)
    {
        fprintf(stdout, "In child process\n");
        fprintf(stdout, "Child Became a Zombie\n");
        exit(0);
        
    }

    return 0;
}