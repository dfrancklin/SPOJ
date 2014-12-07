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

typedef struct { char nome[41]; int H; } Aluno;

int habilidade(const void *, const void *);
int nome(const void *, const void *);

int main()
{
	int N, T, i, j, k, jogadores;
	Aluno *alunos, **times;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d %d", &N, &T);
	
	jogadores = ceil(N / (float) T);
	
	alunos = malloc(N * sizeof(Aluno));
	
	for(i = 0; i < N; i++)
		scanf("%s %d", alunos[i].nome, &alunos[i].H);
	
	qsort(alunos, N, sizeof(Aluno), habilidade);
	
	times = malloc(T * sizeof(Aluno *));
	
	for(i = 0; i < T; ++i)
		times[i] = malloc(jogadores * sizeof(Aluno));
	
	for(i = 0; i < T; i++)
		for(j = 0; j < jogadores; j++)
		{
			times[i][j].nome[0] = '\0';
			times[i][j].H = -1;
		}
	
	for(i = 0, k = 0; i < N; k++)
		for(j = 0; j < T && i < N; j++, i++)
		{
			strcpy(times[j][k].nome, alunos[i].nome);
			times[j][k].H = alunos[i].H;
		}
	
	for(i = 0; i < T; i++)
	{
		printf("Time %d\n", i + 1);
		
		qsort(times[i], jogadores, sizeof(Aluno), nome);
		
		for(j = 0; j < jogadores; j++)
			if(times[i][j].nome[0] != '\0')
				printf("%s\n", times[i][j].nome);
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int habilidade(const void *p1, const void *p2)
{
	Aluno *i = (Aluno *) p1, *j = (Aluno *) p2;
	
	if(i->H == j->H)
		return 0;
	else if(i->H > j->H)
		return -1;
	else
		return 1;
}

int nome(const void *p1, const void *p2)
{
	Aluno *i = (Aluno *) p1, *j = (Aluno *) p2;
	
	return strcmp(i->nome, j->nome);
}