#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
int main()

{

pid_t pid;

int fd;

time_t now;

char buf[256];

int len;

pid=fork();

if (pid<0)

{

perror("fork");

return EXIT_FAILURE;

}

if (pid>0)

{

printf("父进程退出，子进程继续创建守护进程\n");

exit(EXIT_SUCCESS);

}

if (setsid()==-1)

{

perror("setsid");

exit(EXIT_FAILURE);

}

pid=fork();

if (pid<0)

{

perror("fork");
exit(EXIT_FAILURE);

}

if (pid>0)

{

exit(EXIT_SUCCESS);

}

if (chdir("/")==-1)

{
perror("chdir");

exit(EXIT_FAILURE);

}

umask(0);

close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);

fd=open("/tmp/daemon.log",O_WRONLY |
O_CREAT | O_APPEND,0644);

if (fd==-1)

{

exit(EXIT_FAILURE);

}

while(1)

{


now=time(NULL);

len=snprintf(buf,sizeof(buf),"daemon running,PID=%d,time=%s",getpid(),ctime(&now));


if(write(fd,buf,len)==-1)

{

close(fd);

exit(EXIT_FAILURE);

}

sleep(5);

}

close(fd);

return EXIT_SUCCESS;
}
