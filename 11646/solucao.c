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

typedef struct { int id, o, p, b; } Pais;

int cmp(const void *, const void *);

int main()
{
	int N, M, O, P, B, i;
	Pais paises[100];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d %d", &N, &M);
	
	for(i = 0; i < N; i++)
	{
		paises[i].id = i + 1;
		paises[i].o = 0;
		paises[i].p = 0;
		paises[i].b = 0;
	}
	
	for(i = 0; i < M; i++)
	{
		scanf("%d %d %d", &O, &P, &B);
		paises[O - 1].o++;
		paises[P - 1].p++;
		paises[B - 1].b++;
	}
	
	qsort(paises, N, sizeof(Pais), cmp);
	
	printf("%d", paises[0].id);
	
	for(i = 1; i < N; i++)
		printf(" %d", paises[i].id);
	
	printf("\n");
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int cmp(const void *p1, const void *p2)
{
	Pais *i = (Pais * ) p1, *j = (Pais * ) p2;
	
	if(i->o == j->o)
		if(i->p == j->p)
			if(i->b == j->b)
				if(i->id == j->id)
					return 0;
				else if(i->id > j->id)
					return 1;
				else
					return -1;
			else if(i->b > j->b)
				return -1;
			else
				return 1;
		else if(i->p > j->p)
			return -1;
		else
			return 1;
	else if(i->o > j->o)
		return -1;
	else
		return 1;
	
}