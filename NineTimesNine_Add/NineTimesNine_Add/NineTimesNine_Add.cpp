//==========================================================
//	���\(���Z)��\������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
//�������R�[�f�B���O���Ă�������
	int i, j;
	
	printf("   |");
	for (i = 1; i <= 9; i++) {
		printf("%4d, i");
	}
	printf("\n");

	printf("---+");
	for (i = 1; i <= 9; i++) {
		printf("----");
	}
	printf("\n");

	for (i = 1; i <= 9; i++) {
		printf("%2d |", i);
		for (j = 1; j <= 9; j++) {
			printf("%4d", i + j);
		}
		printf("\n");
	}

	return 0;
}