/*
Question: [2]
A program to create a child process
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
    }

else if (pid > 0)
    {
        // Used the wait function to wait for the child process to finish
        wait(NULL);
        printf("\n\nParent Process Details: \n");
        printf("I am the parent process\n");
        printf("Waiting for child to terminate...\n");
    }

    else
        printf("There was an error in creating the Child Proces\n");


    return 0;
}