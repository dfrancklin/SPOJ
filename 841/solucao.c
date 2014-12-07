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

typedef struct { int C, M; } Aluno;

int main()
{
	int N, i, maior, c = 0;
	Aluno alunos[1000];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		maior = 0;
		
		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &alunos[i].C, &alunos[i].M);
			
			if(maior < alunos[i].M)
				maior = alunos[i].M;
		}
		
		printf("Turma %d\n", ++c);
		
		for(i = 0; i < N; i++)
			if(maior == alunos[i].M)
				printf("%d ", alunos[i].C);
		
		printf("\n\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}