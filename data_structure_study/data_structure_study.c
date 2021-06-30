#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"first_lecture.h"

#define MAXN 10
#define MAXK 1e7
struct PolyNode {
	int coef; // 系数
	int expon; // 指数
	struct PolyNode *link; // 指向下一个节点的指针
};
typedef struct PolyNode *Polynomial;
Polynomial PolyAdd(Polynomial P1, Polynomial P2);void Attach(int c, int e, Polynomial *pRear);void test_duration(void);

//函数开始时间和结束时间 以时钟打点数表示
clock_t start, end;
//函数执行时长 CLOCKS_PER_SEC 机器时钟每秒所走的时钟打点数
double duration;

int main(void)
{
	Polynomial P1 = (Polynomial)malloc(sizeof(struct PolyNode));
	Polynomial P2= (Polynomial)malloc(sizeof(struct PolyNode));
	P1->coef = 1;
	P1->expon = 1;
	P1->link = NULL;
	P2->coef = 2;
	P2->expon = 2;
	P2->link = NULL;
	PolyAdd(P1, P2);
	return 0;
}

void test_duration(void)
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

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear; /* 由front 记录结果多项式链表头结点 */
	while (P1 && P2) /* 当两个多项式都有非零项待处理时 */
		switch (strcmp(P1->expon, P2->expon)) {
		case 1:
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
			break;
		case -1:
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->link;
			break;
		case 0:
			sum = P1->coef + P2->coef;
			if (sum) Attach(sum, P1->expon, &rear);
			P1 = P1->link;
			P2 = P2->link;
			break;
		}
	/* 将未处理完的另一个多项式的所有节点依次复制到结果多项式中去 */
	for (; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
	for (; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link; /*令front指向结果多项式第一个非零项 */
	free(temp); /* 释放临时空表头结点 */
	return front;
}

void Attach(int c, int e, Polynomial *pRear)
{ /* 由于在本函数中需要改变当前结果表达式尾项指针的值， */
/* 所以函数传递进来的是结点指针的地址，*pRear指向尾项*/
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode)); /* 申请新结点 */
	P->coef = c; /* 对新结点赋值 */
	P->expon = e;
	P->link = NULL;
	/* 将P指向的新结点插入到当前结果表达式尾项的后面 */
	(*pRear)->link = P;
	*pRear = P; /* 修改pRear值 */
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
