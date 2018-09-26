#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
	open("q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork();
	if (rc < 0) { //fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { //child
		/*the child can access the file descriptor returned by open*/
		char *myargs[3];
		myargs[0] = strdup("echo");
		myargs[1] = strdup("child\n");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
	} else { //parent
		/*the parent can access the file descriptor returned by open*/
		char *myargs[3];
		myargs[0] = strdup("echo");
		myargs[1] = strdup("parent\n");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
	}
	//when both processes are writing to the file concurrently,
	//which ever runs first will write on the file first
	return 0;
}
