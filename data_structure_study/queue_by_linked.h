#include<stdlib.h>
#include<stdbool.h>
#define ERROR NULL

typedef int ElementType;
typedef struct Node *PtrNode;
struct Node {
	ElementType data;   
	PtrNode Next;
};
struct QNode
{
	PtrNode front,rear;//队首和队尾结点指针
};
typedef struct QNode *Queue;

Queue CreateQueue_Linked();
bool IsFull_Linked(Queue Q);
bool AddQ_Linked(Queue Q, ElementType X);
bool IsEmpty_Linked(Queue Q);
ElementType DeleteQ_Linked(Queue Q);


