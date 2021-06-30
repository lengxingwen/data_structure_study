#include"stack_by_array.h"

Stack CreateStack_Array(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull_Array(Stack S)
{
	return (S->Top == S->MaxSize - 1);
}

bool Push_Array(Stack S, ElementType X)
{
	if (IsFull(S)) {
		printf("堆栈满");
		return false;
	}
	else {
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool IsEmpty_Array(Stack S)
{
	return (S->Top == -1);
}

ElementType Pop_Array(Stack S)
{
	if (IsEmpty(S)) {
		printf("堆栈空");
		return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
	}
	else
		return (S->Data[(S->Top)--]);
}