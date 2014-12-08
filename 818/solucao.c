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

typedef struct { int id, voos; } Aeroporto;

int ordena(const void *arg1, const void *arg2)
{
	Aeroporto *i = (Aeroporto *) arg1, *j = (Aeroporto *) arg2;
	
	if(i->voos == j->voos)
		if(i->id == j->id)
			return 0;
		else if(i->id > j->id)
			return 1;
		else
			return -1;
	else if(i->voos > j->voos)
		return -1;
	else
		return 1;
}

int main()
{
	int A, V, X, Y, i, c = 0;
	Aeroporto *aeroportos;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &A, &V) && !(A == 0 && V == 0))
	{
		aeroportos = (Aeroporto *) malloc(A * sizeof(Aeroporto));
		
		for(i = 0; i < A; i++)
		{
			aeroportos[i].id = i + 1;
			aeroportos[i].voos = 0;
		}
		
		while(V--)
		{
			scanf("%d %d", &X, &Y);
			
			aeroportos[X - 1].voos++;
			aeroportos[Y - 1].voos++;
		}
		
		qsort(aeroportos, A, sizeof(Aeroporto), ordena);
		
		printf("Teste %d\n", ++c);
		printf("%d", aeroportos[0].id);
		
		for(i = 1; aeroportos[0].voos == aeroportos[i].voos; i++)
			printf(" %d", aeroportos[i].id);
		
		printf("\n\n");
		
		free(aeroportos);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}