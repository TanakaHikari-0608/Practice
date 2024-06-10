//=====================================================
//  3値の最大値
//=====================================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
//  関数プロトタイプ
int MaxOfTree(int a, int b, int c);

int main()
{
    srand(time(NULL));
    int a = rand() % 100;
    int b = rand() % 100;
    int c = rand() % 100;
    int ans = MaxOfTree(a, b, c);
    printf("MaxOfThree(%d, %d, %d): %d\n", a, b, c, ans);
    return 0;
}

int MaxOfTree(int a, int b, int c)
{
    // ここに3値の最大値を算定するコードを書いてください。
 
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    return max;
}
