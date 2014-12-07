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

int cmp(const void *, const void *);

int main()
{
	int N, K, i;
	char nomes[100][21];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d %d", &N, &K);
	
	for(i = 0; i < N; i++)
		scanf("%s", nomes[i]);
	
	qsort(nomes, N, sizeof(nomes[0]), cmp);
	
	printf("%s\n", nomes[K - 1]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int cmp(const void *p1, const void *p2)
{
	char *i = (char *) p1, *j = (char *) p2;
	
	return strcmp(i, j);
}