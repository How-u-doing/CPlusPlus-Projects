/* Word counting program, by K&R C */
/* bare-bones version of UNIX program 'wc' */
#include <stdio.h>

#define IN  1    /* inside a word */
#define OUT 0    /* outside a word */ 

/* count lines, words, and characters in input */
int main(int argc, char* argv[])
{
	int c, nl, nw, nc, state;
	FILE* fp;

	// complile: gcc file_wc.c -o file_wc
	// Linux command line: ./file_wc input.txt
	if (!(fp=fopen(argv[1], "r"))) {
		perror("Error opening file!\n");
	}

	state = OUT;
	nl = nw = nc = 0;
	while ((c = fgetc(fp)) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}