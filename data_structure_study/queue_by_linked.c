#include"queue_by_linked.h"

Queue CreateQueue_Linked()
{
	Queue queue = (Queue)malloc(sizeof(struct QNode));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

bool IsFull_Linked(Queue Q)
{
	PtrNode tmp = (PtrNode)malloc(sizeof(struct Node));
	if (tmp)
	{
		free(tmp);
		return false;
	}
	return true;
}

bool AddQ_Linked(Queue Q, ElementType X)
{
	if (IsFull(Q))
		return false;
	PtrNode top = (PtrNode)malloc(sizeof(struct Node));
	top->data = X;
	if (IsEmpty(Q))
	{
		top->Next = NULL;
		Q->rear = top;
		Q->front = top;
		return true;
	}
	top->Next = Q->front;
	Q->front = top;
	return true;
}

bool IsEmpty_Linked(Queue Q)
{
	return Q->rear == NULL;
}
ElementType DeleteQ_Linked(Queue Q)
{
	ElementType re;
	if (IsEmpty(Q))
		return ERROR;
	PtrNode node = Q->rear;
	if (Q->front == Q->rear)
	{
		
		Q->front = NULL;
		Q->rear = NULL;
		re = node->data;
		free(node);
		return re;
	}
	PtrNode i;
	for (i = Q->front; i->Next != node; i = i->Next)
	{

	}
	re = node->data;
	free(node);
	Q->rear = i;
	return re;
}