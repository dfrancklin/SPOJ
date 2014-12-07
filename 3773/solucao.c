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
	int N, i, votos[100000], candidato, vencedor, qtd_votos, votosvenc;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
		scanf("%d", &votos[i]);
	
	votos[i] = 0;
	
	qsort(votos, N, sizeof(int), cmp);
	
	candidato = votos[0];
	vencedor = votos[0];
	qtd_votos = 1;
	votosvenc = 0;
	
	for(i = 1; i <= N; i++)
	{
		if(votos[i] == candidato)
			qtd_votos++;
		else
		{
			if(qtd_votos > votosvenc)
			{
				votosvenc = qtd_votos;
				vencedor = candidato;
			}
			
			candidato = votos[i];
			qtd_votos = 1;
		}
	}
	
	printf("%d\n", vencedor);
	
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
		return 1;
	else
		return -1;
}