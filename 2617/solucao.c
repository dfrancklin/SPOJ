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

typedef struct { char c; int q, o;} Letra;

int cmp(const void *, const void *);
int sch(const void *, const void *);
int busca(char, Letra *);

int main()
{
	int T, F, i, r2, c = 0;
	char texto[10001], frequencia[27];
	Letra letras[26], s, *r;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &T, &F) && !(T == 0 && F == 0))
	{
		scanf(" %s", frequencia);
		scanf(" %[^\n]s", texto);
		
		for(i = 0; i < 26; i++)
		{
			letras[i].c = i + 'a';
			letras[i].q = 0;
			letras[i].o = i;
		}
		
		for(i = 0; texto[i] != '\0'; i++)
		{
			if(texto[i] != ' ')
			{
				s.c = texto[i];
				r = bsearch(&s, letras, 26, sizeof(Letra), sch);
				
				if(r)
					r->q++;
			}
		}
		
		qsort(letras, 26, sizeof(Letra), cmp);
		
		for(i = 0; i < T; i++)
		{
			if(texto[i] != ' ')
			{
				r2 = busca(texto[i], letras);
				
				if(r2 > -1)
					texto[i] = frequencia[r2];
			}
		}
		
		printf("Teste %d\n", ++c);
		printf("%s\n", texto);
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int cmp(const void *p1, const void *p2)
{
	Letra *i = (Letra *) p1, *j = (Letra *) p2;
	
	if(i->q == j->q)
		if(i->c == j->c)
			return 0;
		else if(i->c > j->c)
			return 1;
		else
			return -1;
	else if(i->q > j->q)
		return -1;
	else
		return 1;
}

int sch(const void *p1, const void *p2)
{
	Letra *i = (Letra *) p1, *j = (Letra *) p2;
	
	if(i->c == j->c)
		return 0;
	else if(i->c > j->c)
		return 1;
	else
		return -1;
}

int busca(char b, Letra *lista)
{
	int i;
	
	for(i = 0; i < 26; i++)
		if(lista[i].c == b)
			return i;
	
	return -1;
}