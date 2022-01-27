// Question[5]: Running multiple Child processes using fork().

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{
    pid_t pid;

    for(int i = 0; i < 5; i++)
    {
        printf("\n\n\n");
        pid = fork();

        if(pid == 0)
        {
            printf("Child Process ID                      : %d\n", getpid());
            printf("Parent Process \"%s\" ID(of Child): %d\n", argv[0], getppid());
            exit(0);
        }
        else if(pid > 0)
        {
            wait(NULL);
        }
        else
        {
            printf("Fork Failed\n");
            exit(1);
        }
    }

    printf("Parent Process \"%s\" ID: %d\n",argv[0], getpid());

    return 0;

}