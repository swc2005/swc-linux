#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

pid_t pid;
pid=fork();
if(pid<0)
{
perror("fork");
return 0;
}

else if(pid==0)

{

printf("i am deamon\n");
sleep(10);
}
else
{
exit(0);
}
}	


