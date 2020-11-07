#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void CreateQueue_q(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
    pq->TotalOf_T=0;
}

int QueueEmpty_q(Queue* pq)
{
    return !pq->front;
}

int QueueFull_q(Queue* pq)
{
    return 0;
}

int QueueSize_q(Queue* pq)
{
    return pq->size;
}

void Append_q(int process_id,int Exe_T,Queue* pq)
{
    QueueNode*pn=(QueueNode*)malloc(sizeof(QueueNode));
    pn->next=NULL;
    pn->process_id=process_id;
    pn->execution_T=Exe_T;
    pq->Time_Q=30;
    pq->TotalOf_T = pq->TotalOf_T + pn->execution_T;
    if (!pq->rear)
        pq->front=pn;
    else
        pq->rear->next=pn;//run time error for empty queue
    pq->rear=pn;
    pq->size++;
}
void Append_f(int process_id,int Exe_T,Queue* pq)
{
    QueueNode*pn=(QueueNode*)malloc(sizeof(QueueNode));
    pn->next=NULL;
    pn->process_id=process_id;
    pn->execution_T=Exe_T;
    pq->Time_Q=30;
    pq->TotalOf_T = pq->TotalOf_T + pn->execution_T;

    if(pq->front->next == NULL)
    {
        pn->next=NULL;
        pq->front->next= pn;
    }
    else
    {
        pn->next=pq->front->next;
        pq->front->next=pn;
    }


}
void Serve_q(int *process_id,int *Exe_T,Queue* pq)
{
    QueueNode *pn=pq->front;
    *process_id=pn->process_id;
    *Exe_T = pn->execution_T;
    pq->front=pn->next;
    free(pn);
    if (!pq->front)
        pq->rear=NULL;
    pq->size--;
}
void ClearQueue_q(Queue* pq)
{
    while(pq->front)
    {
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size  = 0;
}
QueueNode LastNode(Queue *pq)
{
    return (*pq->rear);
}


