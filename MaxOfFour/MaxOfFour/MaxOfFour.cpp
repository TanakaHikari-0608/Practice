//==============================================
//  4�l�̍ő�l
//==============================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
int MaxOfFour(int a, int b, int c, int d);

int main()
{
	srand(time(nullptr));
	int a = rand() % 100;
	int b = rand() % 100;
	int c = rand() % 100;
	int d = rand() % 100;
	int ans = MaxOfFour(a, b, c, d);
	printf("MaxOfFour(%d,%d,%d,%d) => %d\n", a, b, c, d, ans);
	return 0;
}
int MaxOfFour(int a, int b, int c, int d)
{
	// �������R�[�f�B���O���Ă��������B
	if (a > b) {
		if (a > c)
			if (a > d)
				return a;
	}
	if (b > a) {
		if (b > c)
			if (b > d)
				return b;
	}
	if (c > a) {
		if (c > b)
			if (c > d)
				return c;
	}
	if (d > a) {
		if (d > b)
			if (d > c)
				return d;
	}
}