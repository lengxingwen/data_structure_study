#include<stddef.h>
#include<stdbool.h>
typedef struct LNode *PtrToLNode;
typedef int ElementType;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

#define ERROR NULL

Position Find_Linked(List L, ElementType X);

bool Insert_Linked(List L, ElementType X, Position P);

bool Delete_Linked(List L, Position P);