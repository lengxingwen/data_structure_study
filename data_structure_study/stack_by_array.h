#include<stdbool.h>
#include<stdlib.h>
#define ERROR NULL
typedef int Position;
typedef int ElementType;
struct SNode {
	ElementType *Data; /* 存储元素的数组 */
	Position Top;      /* 栈顶指针 */
	int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;
Stack CreateStack_Array(int MaxSize);
bool IsFull_Array(Stack S);
bool Push_Array(Stack S, ElementType X);
bool IsEmpty_Array(Stack S);
ElementType Pop_Array(Stack S);

