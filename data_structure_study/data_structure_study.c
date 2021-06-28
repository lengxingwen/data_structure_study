#include<stdio.h>
#include<time.h>
#include"first_lecture.h"
#define MAXN 10
#define MAXK 1e7

//函数开始时间和结束时间 以时钟打点数表示
clock_t start, end;
//函数执行时长 CLOCKS_PER_SEC 机器时钟每秒所走的时钟打点数
double duration;

int main(void)
{
	int i;
	double a[MAXN];
	for (i = 0; i < MAXN; i++)
	{
		a[i] = (double)i;
	}
	start = clock();
	for (i = 0; i < MAXK; i++)
	{
		f1(MAXN-1, a, 1.1);
	}
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("ticks1=%f\n", (double)(end - start));
	printf("duration1=%6.2e\n", duration);

	start = clock();
	for (i = 0; i < MAXK; i++)
	{
		f2(MAXN - 1, a, 1.1);
	}
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("ticks2=%f\n", (double)(end - start));
	printf("duration2=%6.2e\n", duration);
	return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
