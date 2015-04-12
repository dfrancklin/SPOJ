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
	char telefone[16], i;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf(" %s", telefone);
	
	for(i = 0; telefone[i] != '\0'; i++)
		if(telefone[i] >= 'A' && telefone[i] <= 'Z')
			switch(telefone[i])
			{
				case 'A': case 'B': case 'C': telefone[i] = '2'; break;
				case 'D': case 'E': case 'F': telefone[i] = '3'; break;
				case 'G': case 'H': case 'I': telefone[i] = '4'; break;
				case 'J': case 'K': case 'L': telefone[i] = '5'; break;
				case 'M': case 'N': case 'O': telefone[i] = '6'; break;
				case 'P': case 'Q': case 'R': case 'S': telefone[i] = '7'; break;
				case 'T': case 'U': case 'V': telefone[i] = '8'; break;
				case 'W': case 'X': case 'Y': case 'Z': telefone[i] = '9'; break;
			}
	
	printf("%s\n", telefone);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}