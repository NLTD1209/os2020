#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	printf("main before fork \n");
	int pid1 = fork();
	if (pid1 == 0)
	{
		printf("child process, launching ps -ef\n");
		char *args[] = {"bin/ps","-ef", NULL};
		execvp("/bin/ps",args);//child 1
	}
	else 
	{
		printf("I am parent after fork(), child is %d\n", pid1 );// parent 1
		wait(NULL);
		int pid2 = fork();
		if (pid2 == 0)
		{
			printf("child process, launching free -h\n");
			char *args[] = {"free", "-h", NULL};
			execvp("free", args); // child 2
		}
		else
		{
			wait(NULL);
			printf("I am parent after fork(), child is %d\n", pid2 ); // parent 2
		}
	}
	return 0;
}