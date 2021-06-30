#include<stdlib.h>
#include<stdbool.h>
#define ERROR NULL
typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack_Linke();
bool IsEmpty_Linke(Stack S);
bool Push_Linke(Stack S, ElementType X);
ElementType Pop_Linke(Stack S);