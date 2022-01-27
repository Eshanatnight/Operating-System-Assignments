/*
Question:[3]
Write a C program to create a child process and allow the parent to display “parent process with
process id” and the child to display “child process with its process id and its Parent process id ”
on the screen.
*/

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
        printf("Child Process Details: \n");
        printf("I am the child process\n");
        printf("My PID is %d\n", getpid());
        printf("My Parent PID is %d\n", getppid());
    }

else if (pid > 0)
    {
        // Used the wait function to wait for the child process to finish

        wait(NULL);
        printf("\n\nChild Process Terminated...\n");
        printf("Parent Process Details: \n");
        printf("I am the parent process\n");
        printf("My PID is %d\n", getpid());

    }

    else
        printf("There was an error in creating the Child Proces\n");


    return 0;
}