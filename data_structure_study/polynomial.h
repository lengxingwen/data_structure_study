/*
����ʽ
*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
	int coef; //ϵ��
	int expon; //ָ��
	Polynomial link;
};

Polynomial readPoly();

Polynomial multPoly(Polynomial p1, Polynomial p2);

void printPoly(Polynomial p);

Polynomial addPoly(Polynomial p1, Polynomial p2);

void attachPoly(int c, int e, Polynomial *pRear);