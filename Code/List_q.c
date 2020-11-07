#include <stdio.h>
#include <stdlib.h>
#include "List_q.h"
void CreateList(List *pl)
{
    pl->head=NULL;
    pl->size=0;
} // (1)

int ListEmpty(List *pl)
{
    return (pl->size==0);
    //or return !pl->head
} // (1)

int ListFull(List *pl)
{
    return 0;
} // (1)

int ListSize(List *pl)
{
    return pl->size;
} // (1)
void InsertList(int pos,Queue *q_in, List *pl)
{
    ListNode *p, *q;
    int i;
    p=(ListNode *)malloc(sizeof(ListNode));
    p->q=q_in;
    p->next=NULL;

    if (pos==0) //will work also for head equals NULL
    {
        p->next=pl->head;
        pl->head=p;
    }
    else
    {
        for(q=pl->head, i=0; i<pos-1; i++)
            q=q->next;
        p->next=q->next;
        q->next=p;
    }
    pl->size++;
}
ListNode FindMin_Q(List *pl)
{
    ListNode *p, *qL;
    int flag_1=0;
    qL = pl->head;
    if(pl->head->next == NULL)
    {
        return *qL->next;
    }
    else
    {
        p = pl->head->next;
        while(p != NULL)
        {
            if(qL->q->TotalOf_T < p->q->TotalOf_T)
            {
                flag_1=1;
            }
            if(flag_1==1)
                p = p->next;
            else
                qL = p;
            p = p->next;
        }
    }
    return *qL;
}
ListNode FindMax_Q(List *pl)
{
    ListNode *p, *qL;
    int flag_1=0;
    qL = pl->head;
    if(pl->head->next == NULL)
    {
        return *qL->next;
    }
    else
    {
        p = pl->head->next;
        while(p != NULL)
        {
            if(qL->q->TotalOf_T > p->q->TotalOf_T)
            {
                flag_1=1;
            }
            if(flag_1==1)
                p = p->next;
            else
                qL = p;
            p = p->next;
        }
        return *qL;
    }

}
void Steal(List *pl)
{
    ListNode *p,*T;
    QueueNode *ql;
    T = pl->head;
    p = pl->head;
    if(pl->head->next == NULL)
    {
        return;
    }
    else
    {
        *p = FindMax_Q(pl);
        *T = FindMin_Q(pl);
        ql = p->q->front;
        *ql = LastNode(p->q);
        Append_q(ql->process_id,ql->execution_T,(T->q));
        Serve_q(&ql->process_id,&ql->execution_T,(p->q));
    }
}
void Fork(List *pl)
{
    ListNode *p;
    QueueNode *pq;
    if(pl->head == NULL)
    {
        return;
    }
    else
    {

        p =pl->head;
        while(p != NULL)
        {

            if(p->q->front == NULL)
            {
                return;
            }
            else
            {
                pq = p->q->front;

                while(pq != NULL)
                {
                    int con = pq->execution_T;
                    while(con > p->q->Time_Q)
                    {
                        pq->execution_T=30;
                        con = con -  pq->execution_T;
                        Append_f(pq->process_id,pq->execution_T,(p->q));
                    }
                    Append_f(pq->process_id,con,(p->q));
                    pq = pq->next;
                }
            }
            p= p->next;

        }
    }

}
void execute(List *pl)
{
    ListNode *p;
    p = pl->head;
    if(pl->head == NULL)
    {
        return;
    }
    else
    {
        Fork(pl);

        if(pl->head->next == NULL)
            return;
        else
            Steal(pl);

        QueueNode *pq;

        while(p !=NULL)
        {

            pq = p->q->front;
            while(pq != NULL)
            {
                Serve_q(&pq->process_id,&pq->execution_T,p->q);
                pq = pq->next;
            }
            p = p->next;
        }
    }
    DestroyList(pl);

}
void display(List *pl)
{
    //Node current will point to head
    ListNode *current = pl->head;
    QueueNode *pq;
    if(pl->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of singly linked list Before execute: \n");
    while(current != NULL)
    {
        //Prints each node by incrementing pointer
        printf("Time Queue :%d , Total of Time of nodes: %d \n", current->q->Time_Q,current->q->TotalOf_T);
        pq = current->q->front;
        while(pq != NULL)
        {
            printf("ID : %d \t Execution Time: %d \n",pq->process_id,pq->execution_T);
            pq = pq->next;
        }
        current = current->next;
    }
    printf("\n");
}
void DestroyList(List *pl)
{
    ListNode *q;
    while(pl->head)
    {
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->size=0;
}
