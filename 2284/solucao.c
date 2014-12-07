#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MIN(a, b)	((a) < (b) ?  (a) : (b))
#define MAX(a, b)	((a) > (b) ?  (a) : (b))
#define ABS(a)		((a) <  0  ? -(a) : (a))
#define IMPAR(a)	((a)&1)
#define CTOI(a)		((a) - '0')
#define ITOC(a)		((a) + '0')

#define TRUE	1
#define FALSE	0

int primo(int);

int main()
{
	char word[21], i;
	int n;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", word) != EOF)
	{
		n = 0;
		
		for(i = 0; word[i] != '\0'; i++)
			if(word[i] >= 'a' && word[i] <= 'z')
				n += word[i] - 'a' + 1;
			else
				n += word[i] - 'A' + 27;
		
		if(primo(n))
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int primo(int N)
{
	int i, p = TRUE;
	
	for(i = 2; i < N && p == TRUE; i++)
		if((N % i) == 0)
			p = FALSE;
	
	return p;
}