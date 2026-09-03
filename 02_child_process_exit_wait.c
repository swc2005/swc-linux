#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
pid_t pid;
pid=fork();
if (pid<0)
	{
	perror("fork");
	return 1;
	}
else if (pid==0)
	{
	printf("我是子进程\n,PID=%d\n",getpid());
	sleep(2);
	printf("子进程退出\n");
 	exit(2);
	}
else
	{
	printf("我是父进程\n,PID=%d\n",getpid());
	int status;
	wait(&status);
	printf("子进程正常退出\n");
	if(WIFEXITED(status))
	{
	printf("子进程正常退出\n");
	printf("退出值=%d\n",WEXITSTATUS(status));
	}
	}
	return 0;
}

