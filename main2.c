#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
    printf("=====================================\n");
    printf(" Linux Process Demo\n");
    printf("=====================================\n");

    /* 显示当前进程信息 */
    printf("当前进程PID  : %d\n", getpid());
    printf("父进程PPID   : %d\n", getppid());

    printf("\n准备创建子进程...\n\n");

    /* 创建子进程 */
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return -1;
    }

    /* 子进程 */`
    if (pid == 0)
    {
        printf("========== 子进程 ==========\n");
        printf("fork返回值 : %d\n", pid);
        printf("子进程PID  : %d\n", getpid());
        printf("父进程PPID : %d\n", getppid());

        for(int i = 1; i <= 5; i++)
        {aa
            printf("【子进程】模拟AI识别... 第%d次\n", i);
            sleep(1);
        }

        printf("子进程结束\n");
    }
    /* 父进程 */
    else
    {
        printf("========== 父进程 ==========\n");
        printf("fork返回值(子进程PID): %d\n", pid);
        printf("父进程PID : %d\n", getpid());
        printf("父进程PPID: %d\n", getppid());

        for(int i = 1; i <= 5; i++)
        {
            printf("【父进程】模拟串口发送... 第%d次\n", i);
            sleep(1);
        }

        printf("父进程结束\n");
    }

    printf("程序退出 PID=%d\n", getpid());

    return 0;
}
