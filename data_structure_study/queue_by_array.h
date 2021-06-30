#include<stdlib.h>
#include<stdbool.h>
#define ERROR NULL

typedef int ElementType;
typedef int Position;
struct QNode {
	ElementType *Data;     /* �洢Ԫ�ص����� */
	Position Front, Rear;  /* ���е�ͷ��βָ�� */
	int MaxSize;           /* ����������� */
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize);
bool IsFull(Queue Q);
bool AddQ(Queue Q, ElementType X);
bool IsEmpty(Queue Q);
ElementType DeleteQ(Queue Q);

