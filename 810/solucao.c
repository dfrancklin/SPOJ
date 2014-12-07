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

#define MAX_V	100
#define MAX_A	4950

typedef struct { int x, y, peso, MST; } Aresta;
Aresta arestas[MAX_A];
int vertices[MAX_V];

void kruskal(int, int);

int main()
{
	int N, M, caso = 0, i;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &N, &M) && N != 0)
	{
		for(i = 0; i < M; i++)
		{
			scanf("%d %d %d", &arestas[i].x, &arestas[i].y, &arestas[i].peso);
			arestas[i].MST = FALSE;
		}
		
		kruskal(N, M);
		
		printf("Teste %d\n", ++caso);
		
		for(i = 0; i < M; i++)
			if(arestas[i].MST)
			{
				if(arestas[i].x < arestas[i].y)
					printf("%d %d\n", arestas[i].x, arestas[i].y);
				else
					printf("%d %d\n", arestas[i].y, arestas[i].x);
			}
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

void kruskal(int v, int a)
{
	int i, j, g1, g2;
	char ok;
	
	int comp(const void *p1, const void *p2)
	{
		Aresta *i = (Aresta *) p1, *j = (Aresta *) p2;
		
		if(i->peso > j->peso)
			return 1;
		else
			if(i->peso < j->peso)
				return -1;
			else
				return 0;
	}
	
	qsort(arestas, a, sizeof(Aresta), comp);
	
	for(i = 1; i <= v; i++)
		vertices[i] = i;
	
	for(i = 0; i < a; i++)
	{
		if(vertices[arestas[i].x - 1] != vertices[arestas[i].y - 1])
		{
			arestas[i].MST = TRUE;
			
			if(vertices[arestas[i].x - 1] < vertices[arestas[i].y - 1])
			{
				g1 = vertices[arestas[i].x - 1];
				g2 = vertices[arestas[i].y - 1];
			}
			else
			{
				g1 = vertices[arestas[i].y - 1];
				g2 = vertices[arestas[i].x - 1];
			}
			
			for(j = 0; j < v; j++)
				if(vertices[j] == g2)
					vertices[j] = g1;
			
			for(j = 1, ok = TRUE; j < v && ok; j++)
				ok = ok && vertices[j] == vertices[j - 1];
			
			if(ok)
				break;
		}
	}
}