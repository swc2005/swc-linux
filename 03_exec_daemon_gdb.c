#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{
pid_t pid;
int status;
printf("父进程开始\nPID=%d\n",getpid());
pid=fork();
if (pid<0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid==0)
{
printf("子进程启动\n");
printf("PID=%d\n",getpid());
printf("准备执行ls....\n");
execlp("ls","ls","-l","-a",NULL);
perror("execlp");
exit(EXIT_FAILURE);
}
printf("父进程等待子进程.....\n");
if(waitpid(pid,&status,0)==-1)
{
printf("子进程正常退出\n");
printf("退出值=%d\n",WEXITSTATUS(status));
}
printf("父进程结束\n");
return 0;
}
