#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int rc = fork();
	if (rc < 0) { //fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { //child
		//line below closes the standard output stream
		close(STDOUT_FILENO);
		//this is why the line below won't print
		printf("Print this CHILD.");
	} else { //parent
		printf("I'm the PARENT. Where's my child?\n");
	}
	return 0;
}
