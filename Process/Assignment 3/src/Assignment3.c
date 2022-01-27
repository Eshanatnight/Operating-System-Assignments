/*
    Question[3]: Write a program to show the situation of a process to become an orphan. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    fprintf(stdout, "Question: Write a program to show the situation of a process to become an orphan.\n");
    pid_t pid = fork();

    if (pid < 0) fprintf(stderr, "Fork Failed\n");

    else if (pid > 0) fprintf(stdout, "In Parent Process\n");

    else if (pid == 0)
    {
        fprintf(stdout, "In Child Process\n");
        sleep(30);
        fprintf(stdout, "30 Seconds Later Child Process terminates\n");
    }

    return 0;
}