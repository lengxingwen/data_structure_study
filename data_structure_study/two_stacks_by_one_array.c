#include"two_stacks_by_one_array.h"

Stack CreateStack_OATS()
{
	Stack stack = (Stack)malloc(sizeof(struct SNode));
	stack->top1 = -1;
	stack->top2 = MAXSIZE;
	return stack;
}

bool IsFull_OATS(Stack S)
{
	return (S->top1 + 1) == S->top2;
}

bool Push_OATS(Stack S, ElementType X, int tag)
{
	//tag表示第一个或者第二个栈
	//检查栈是否满
	if(IsFull(S))
		return false;
	if (tag == 1)
		S->data[++S->top1] = X;
	else if (tag == 2)
		S->data[--S->top2] = X;
	else
		return false;
	return true;
}

bool IsEmpty_OATS(Stack S)
{
	return S->top1 == -1 && S->top2 == MAXSIZE;
}

ElementType Pop_OATS(Stack S, int tag)
{
	if (IsEmpty(S))
		return ERROR;
	if (tag == 1&&S->top1!=-1)
		return S->data[S->top1--];
	else if (tag == 2&&S->top2!=MAXSIZE)
		return S->data[S->top2++];
	return ERROR;
}