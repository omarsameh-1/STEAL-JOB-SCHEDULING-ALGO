typedef struct queuenode{
    int process_id;
    int execution_T;
	struct queuenode *next;
}QueueNode;

typedef struct queue{
	QueueNode *front;
	QueueNode *rear;
	int Time_Q ;
	int TotalOf_T;
	int	size;
}Queue;

void CreateQueue_q(Queue *pq);
int isFull_q(Queue* pq);
int isEmpty_q(Queue* pq);
void Append_q(int process_id,int Exe_T,Queue* pq);
void Serve_q(int *process_id,int *Exe_T, Queue* pq);
int QueueSize_q(Queue* pq);
void ClearQueue_q(Queue* pq);
QueueNode LastNode(Queue *pq);



