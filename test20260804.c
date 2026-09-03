#include <stdio.h>
#include <unistd.h>
int main ()
{
pid_t pid=fork();
printf("pid=%d\n",(int)pid);
printf("--------------");
if(pid>0)
{
printf("I AM FATHER PROCESS\n");
}
else if(pid==0)
{
printf("I AM CHILD PROCESS\n");
}
else if(pid<0)
{
perror("fork");
}
return 0;
}
