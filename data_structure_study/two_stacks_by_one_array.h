#include<stdbool.h>
#include<stdlib.h>
#define ERROR NULL
#define MAXSIZE 50
typedef int ElementType;

struct SNode
{
	ElementType data[MAXSIZE];
	int top1;
	int top2;
};
typedef struct SNode *Stack;

Stack CreateStack_OATS();
bool IsFull_OATS(Stack S);
bool Push_OATS(Stack S, ElementType X,int tag);
bool IsEmpty_OATS(Stack S);
ElementType Pop_OATS(Stack S, int tag);
