/*
Question [1]: Write a program to show the use of exec() system call. 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    fprintf(stdout, "Question: Write a program to show the use of exec() system call.\n\n");
    pid_t pid;
    int status;
    pid = fork();
    if(pid == 0)
    {
        execl("/bin/ls", "ls", "-la", NULL);
    }

    else
    {
        wait(&status);
    }

    char response;

    fprintf(stdout, "Want to run the Python Interpreter? (Y/N)\n");
    scanf("%c", &response);

    if (response == 'Y' || response == 'y' )
    {
        char *programName = "ls";
        char *arg1 = "-lh";
        char *arg2 = "./";

        execlp("python3", "python3", NULL);
    }

    return 0;
}