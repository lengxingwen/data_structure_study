#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"first_lecture.h"
#include"polynomial.h"

#define MAXN 10
#define MAXK 1e7
void test_polynomial();void test_duration();

//函数开始时间和结束时间 以时钟打点数表示
clock_t start, end;
//函数执行时长 CLOCKS_PER_SEC 机器时钟每秒所走的时钟打点数
double duration;

int main()
{
	
	return 0;
}

void test_polynomial()
{
	Polynomial p1, p2, pm, pa;
	p1 = readPoly();
	p2 = readPoly();
	pm = multPoly(p1, p2);
	pa = addPoly(p1, p2);
	printPoly(pm);
	printPoly(pa);
}

void test_duration()
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
		f1(MAXN - 1, a, 1.1);
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
}
