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

int main()
{
	int N, P, q, i;
	char logo[21];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &N, &P) && !(N == 0 && P == 0))
	{
		q = (int) ceil(N / (float) P);
		
		if(q > 20)
			q = 20;
		
		q -= 3;
		
		if(q < 3)
			q = 3;
		
		logo[0] = 'P';
		
		for(i = 1; i < q; i++)
			logo[i] = 'o';
		
		logo[i] = 'd';
		logo[++i] = 'l';
		logo[++i] = 'e';
		logo[++i] = '\0';
		
		printf("%s\n", logo);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}