/*
ÅÐ¶ÏÊ÷µÄÍ¬¹¹
*/
#include<stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
} T1[MaxTree], T2[MaxTree];

void test_isomorphism();
Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);