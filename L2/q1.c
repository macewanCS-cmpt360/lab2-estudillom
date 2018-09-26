#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int a = 100;
	int rc = fork();
	printf("Initial value of a: %d\n", a);
	if (rc < 0) { //fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { //child
		//value of a is inherited till here.
		a = 50;
		// value of a changed after the line above
		printf("child value of a: %d\n", a);
	} else { //parent
		//value of a inherited till here.
		a = 75;
		//value of a changed after the line above
		printf("parent value of a: %d\n", a);
	}
	printf("Final value of a: %d\n", a);
	return 0;
}
