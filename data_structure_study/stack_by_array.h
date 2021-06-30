#include<stdbool.h>
#include<stdlib.h>
#define ERROR NULL
typedef int Position;
typedef int ElementType;
struct SNode {
	ElementType *Data; /* �洢Ԫ�ص����� */
	Position Top;      /* ջ��ָ�� */
	int MaxSize;       /* ��ջ������� */
};
typedef struct SNode *Stack;
Stack CreateStack_Array(int MaxSize);
bool IsFull_Array(Stack S);
bool Push_Array(Stack S, ElementType X);
bool IsEmpty_Array(Stack S);
ElementType Pop_Array(Stack S);

