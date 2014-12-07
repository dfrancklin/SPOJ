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

int compara(const void *, const void *);

int main()
{
	int N, E, F, i, j, k, l, m, o;
	char especiais[100][11], filmes[100][101], aux[101], sigla[101], *c;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
	{
		scanf("%d %d", &E, &F);
		
		for(j = 0; j < E; j++)
			scanf(" %s", especiais[j]);
		
		for(j = 0; j < F; j++)
			scanf(" %[^\n]s", filmes[j]);
		
		qsort(especiais, E, sizeof(especiais[0]), compara);
		
		for(j = 0; j < F; j++)
		{
			k = l = m = o = 0;
			
			while(TRUE)
			{	
				if(filmes[j][k] == ' ' || filmes[j][k] == '-' || filmes[j][k] == '\0')
				{
					aux[l] = '\0';
					
					c = (char *) bsearch(aux, especiais, E, sizeof(especiais[0]), compara);
					
					if(c != NULL)
					{
						if(m == 0)
						{ }	
						else
						{
							sigla[o] = tolower(aux[0]);
							o++;
						}
					}
					else
					{
						sigla[o] = toupper(aux[0]);
						o++;
					}
					
					l = -1;
					m++;
				}
				else
					aux[l] = filmes[j][k];
				
				
				if(filmes[j][k] == '\0')
					break;
				
				l++;
				k++;
			}
			
			sigla[o] = '\0';
			printf("%s\n", sigla);
		}
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int compara(const void *p1, const void *p2)
{
	char *i = (char *) p1, *j = (char *) p2;
	
	return stricmp(i, j);
}

int stricmp(const char *p1, const char *p2)
{
	char *s1 = (char *) p1;
	char *s2 = (char *) p2;
	
	char c1, c2;

	do {
		c1 = (char) toupper((int) *s1++);
		c2 = (char) toupper((int) *s2++);
		
		if(c1 == '\0')
			return c1 - c2;
	} while (c1 == c2);

	return c1 - c2;
}