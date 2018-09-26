#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int rc = fork();
	if (rc < 0) { //fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { //child
		printf("hello\n");
	} else { //parent
		//in order to make sure child process finishes first
		sleep(1);
		//it is possible to not use wait()
		printf("goodbye\n");
	}
	return 0;
}
