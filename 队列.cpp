#include <stdio.h>
#define queuesize 100
typedef char datatype;

typedef struct{
    char data[queuesize];
    int front,rear;
}seqqueue;        
         
void initqueue(seqqueue *q)  
{ 
	q->front=0;
	q->rear=0;
}

int queueempty(seqqueue  *q)  
{
	return q->rear==q->front;
}

void enqueue(seqqueue *q,datatype x)  
{
	if ((q->rear+1)%queuesize==q->front)
		printf("queue overflow");
    else
	{ 
		q->data[q->rear]=x;
        q->rear=(q->rear+1)%queuesize; 
	}
}

datatype dequeue(seqqueue *q)  
{     
	datatype x;
	if(q->rear==q->front)
		printf("queue underflow");
    else
    {  
		x=q->data[q->front];
        q->front=(q->front+1)%queuesize;
        return x;
    }
}

void main(){
	seqqueue queue,*q;
	q=&queue;
	initqueue(q);
}
