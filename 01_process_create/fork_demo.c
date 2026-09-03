#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;

    printf("程序开始运行\n");
    printf("当前进程 PID：%d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("[子进程]\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }
    else
    {
        printf("[父进程]\n");
        printf("PID  = %d\n", getpid());
        printf("子进程 PID = %d\n", pid);
    }

    return 0;
}
