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
	int M, N, i, pontos[10000];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d %d", &N, &M);
	
	for(i = 0; i < N; i++)
		scanf("%d", &pontos[i]);
	
	qsort(pontos, N, sizeof(int), cmp);
	
	for(i = 0; i < M; i++)
		printf("%d\n", pontos[i]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int cmp(const void *p1, const void *p2)
{
	int *i = (int *) p1, *j = (int *) p2;
	
	if(*i == *j)
		return 0;
	else if(*i > *j)
		return -1;
	else
		return 1;
}