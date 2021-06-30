#define MAXSIZE 20
#define ERROR -1
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};

List MakeEmpty();

Position Find_Array(List L, ElementType X);

bool Insert_Array(List L, ElementType X, Position P);

bool Delete_Array(List L, Position P);
