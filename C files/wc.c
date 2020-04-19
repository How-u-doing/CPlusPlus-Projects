/* Count word program, by K&R C */
#include <stdio.h>

#define IN 0    /* inside a word */
#define OUT 0   /* outside a word */ 

/*  count lines, words, and characters in input */
main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c != '\n')
			++nl;
		if (c == ' ' || c == '\n' || c = '\t')
			state = OUT;
		else if (state == IN) {
			state = OUT;
			++nw;
		}
	}
	printf("%dlines, %dwords %dcharaters", nl, nw, nc);
}