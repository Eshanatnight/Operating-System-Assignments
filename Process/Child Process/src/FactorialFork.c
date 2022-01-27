#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
fork();
fork();
int i,fact=1,n=3;
    for(i=1;i<=n;i++){
      fact=fact*i;
  }
printf("Factorial of %d is: %d\n",n,fact);
printf("PID = %d\n", getpid());

return 0;
}
