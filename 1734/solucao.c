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

typedef struct { char nome[21]; int problemas; } Aluno;

int compara(const void *, const void *);

int main()
{
	int N, K = 0, i;
	Aluno alunos[100];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		for(i = 0; i < N; i++)
			scanf(" %s %d", alunos[i].nome, &alunos[i].problemas);
		
		qsort(alunos, N, sizeof(Aluno), compara);
		
		printf("Instancia %d\n", ++K);
		printf("%s\n", alunos[N - 1].nome);
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int compara(const void *p1, const void *p2)
{
	Aluno *i = (Aluno *) p1, *j = (Aluno *) p2;
	
	if(i->problemas == j->problemas)
		return strcmp(i->nome, j->nome);
	else if(i->problemas > j->problemas)
		return -1;
	else
		return 1;
		
}