
/*
 * eatmem.c by Heikki Hannikainen
 *
 * free software - if it breaks, you get to keep both pieces
 *
 * released under the EVVKTVH / ICCLEIYSIUYA license
 * http://www.evvk.com/evvktvh.html
 *
 * Or the 2-clause BSD license, if you prefer.
 *
 * Eats N megabytes of memory, and writes to it to keep it
 * allocated. Run a couple copies eating (together) more memory
 * than you really have, and you'll have a nice swapping effect.
 * Useful for stress testing VM and IO.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	long bytes, loops, loopc;
	char *d;
	
	if (argc != 3) {
		fprintf(stderr, "usage: eatmem <megs> <loops>\n");
		return 1;
	}
	
	bytes = atol(argv[1]);
	loops = atol(argv[2]);
	printf("allocating %ld megs\n", bytes);
	bytes *= 1024*1024;
	
	d = malloc(bytes);
	if (!d) {
		fprintf(stderr, "out of memory!\n");
		return 2;
	}
	
	for (loopc = 0; loopc < loops; loopc++) {
		printf("writing 0...\n");
		memset(d, 0, bytes);
		printf("writing 1...\n");
		memset(d, 1, bytes);
	}
	
	return 0;
}
