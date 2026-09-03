#include <stdio.h>
#include <unistd.h>

int main ()
{


	pid_t pid = fork();
if (pid<0)
{

	perror("fork");

	return 0;
}
else if (pid ==0)
{
while(1)
{

	printf("I'M THE CHILLD PROCESSS,pid=%d,FATHER PROCESS pid=%d\n",getpid(),getppid());


	}

}
else
{
while(1)
{
printf("I'M FATHER PROCESS,pid=%d,CHILD PID=%d\n",getpid(),pid);
sleep(1);


}



}
return 0;
}

