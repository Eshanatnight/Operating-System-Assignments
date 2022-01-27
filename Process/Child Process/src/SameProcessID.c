#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(void)
{
 pid_t xx;
 int n;
 char *argv[] = { "-d 1", NULL };
 // argument list terminated by a NULL pointer. Read execve(2).
 char *argp[] = { "TERM=linux", NULL };
 // environment list terminated by a NULL pointer. Read execve(2).
printf( "parent: My pid = %u \n", getpid() );	 // main(parent) tries to create a new process
 xx = fork();
if( xx == -1 ) { perror("fork-1"); exit(1); }
 if ( xx == 0 ) // 1st-child process
 {
 printf("1st-child: My pid = %u \n", getpid() );
 printf("1st-child: My ppid = %u \n", getppid() );
 sleep(20);
 printf("1st-child: Executing /usr/bin/top %s \n", argv[0]);
 sleep(2);
 n = execve ("/usr/bin/top", argv, argp);
 if( n == -1 ) { perror("execve"); }
 // [execve] never returns if successful
 printf("[execve] ERROR!\n");
 exit(2);
 }
 // parent process , parent again tries to create a new process
 xx = fork();
 if( xx == -1 ) { perror("fork-2"); exit(3); }
 if ( xx == 0 ) // 2nd-child process
 {
 printf( "2nd-child: My pid = %d \n",getpid() );
 printf( "2nd-child: My ppid = %d \n",getppid() );
 printf( "2nd-child: Executing shell script [./s1]\n" );
 n = execl("./s1", NULL );
 if( n == -1 ) { perror("execl"); }
// [execl] never returns if successful
 printf("[execl ERROR !\n");
 exit(4);
 }
//parent process
 wait(NULL);
 wait(NULL);
 return 0;
}
