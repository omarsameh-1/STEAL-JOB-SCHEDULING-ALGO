#include <stdio.h>
#include <stdlib.h>
#include "List_q.h"


int main()
{
    Queue s;
    Queue e;
    Queue t;
    List L;
    CreateQueue_q(&s);
    Append_q(1,13,&s);
    Append_q(2,23,&s);
    Append_q(3,53,&s);
    CreateQueue_q(&e);
    Append_q(1,44,&e);
    Append_q(2,12,&e);
    Append_q(3,10,&e);
    CreateQueue_q(&t);
    Append_q(1,14,&t);
    Append_q(2,17,&t);
    Append_q(3,19,&t);
    CreateList(&L);
    InsertList(0,&s,&L);
    InsertList(1,&t,&L);
    InsertList(2,&e,&L);
    display(&L);
    execute(&L);





    return 0;
}
