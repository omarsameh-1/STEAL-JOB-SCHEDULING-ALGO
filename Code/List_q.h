#include "queue.h"
typedef struct listnode{
	Queue *q;
	struct listnode *next;
}ListNode;

typedef struct list{
	ListNode	*head;
	int		size;
}List;
void CreateList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void InsertList(int pos,Queue *q_in, List *pl);
ListNode FindMin_Q(List *pl);
ListNode FindMax_Q(List *pl);
void Steal(List *pl);
void Fork(List *pl);
void execute(List *pl);
void display(List *pl);
void DestroyList(List *pl);
