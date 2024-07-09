//==========================================================
//	ピラミッドを表示する 倒置
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// 関数プロトタイプ
void PrintPyramid_UpsideDown(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("何段のピラミッドですか? ");
			scanf("%d", &n);
		} while (n <= 0);
		PrintPyramid_UpsideDown(n);
	}
	return 0;
}

void PrintPyramid_UpsideDown(int n)
{
	// ここをコーディングしてください。
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < (2 * i - 1); j++) {
			printf("*");
		}
		printf("\n");
	}
}