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

int main()
{
	int N;
	char A[110], B[110];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf(" %s %s", &A, &B);
		
		if((IMPAR(A[strlen(A) - 1]) && IMPAR(B[strlen(B) - 1])) || (!IMPAR(A[strlen(A) - 1]) && !IMPAR(B[strlen(B) - 1])))
			printf("Par\n");
		else
			printf("Impar\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}