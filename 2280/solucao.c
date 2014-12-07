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
	int i;
	char exp[31], tel[31];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", &exp) != EOF)
	{
		for(i = 0; exp[i] != '\0'; i++)
		{
			if(exp[i] >= 'A' && exp[i] <= 'C')
				tel[i] = '2';
			else if(exp[i] >= 'D' && exp[i] <= 'F')
				tel[i] = '3';
			else if(exp[i] >= 'G' && exp[i] <= 'I')
				tel[i] = '4';
			else if(exp[i] >= 'J' && exp[i] <= 'L')
				tel[i] = '5';
			else if(exp[i] >= 'M' && exp[i] <= 'O')
				tel[i] = '6';
			else if(exp[i] >= 'P' && exp[i] <= 'S')
				tel[i] = '7';
			else if(exp[i] >= 'T' && exp[i] <= 'V')
				tel[i] = '8';
			else if(exp[i] >= 'W' && exp[i] <= 'Z')
				tel[i] = '9';
			else 
				tel[i] = exp[i];
		}
		
		tel[i] = '\0';
		
		printf("%s\n", tel);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}