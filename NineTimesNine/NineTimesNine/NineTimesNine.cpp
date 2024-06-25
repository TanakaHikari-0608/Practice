//==========================================================
//	‹ã‹ã•\‚ð•\Ž¦‚·‚é
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
	int i, j;
	printf("  |");
	for (i = 1; i <= 9; ++i)
		printf("%3d", i);
	putchar('\n');
			
			puts("--+---------------------------");
			for (i = 1; i <= 9; i++) {
				printf("%d |", i);
				for (j = 1; j <= 9; j++)
					printf("%3d", i * j);
				putchar('\n');
			}
		printf("\n");
	return (0);
}