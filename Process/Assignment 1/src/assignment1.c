/*
Question:[1]
A program to get some process related information’s,
Process ID of current process,
Process ID of parent process,
Real user ID of current process,
Effective user ID of current process,
Real group ID of current process,
Effective group ID of current process
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    pid_t porcess_id = getpid();
    pid_t parent_process_id = getppid();
    pid_t real_user_id = getuid();
    pid_t effective_user_id = geteuid();
    pid_t real_group_id = getgid();
    pid_t effective_group_id = getegid();



    printf("Process ID of current process:          %d\n", porcess_id);
    printf("Process ID of parent process:           %d\n", parent_process_id);
    printf("Real user ID of current process:        %d\n", real_user_id);
    printf("Effective user ID of current process:   %d\n", effective_user_id);
    printf("Real group ID of current process:       %d\n", real_group_id);
    printf("Effective group ID of current process:  %d\n", effective_group_id);
    return 0;
}