#include <stdio.h>
#include <stdlib.h>
typedef struct
{
 int front,rear,numberItems;
 int Capacity;
 int *items;
} Queue;


void initialize(Queue *q,int size)
{
 q->rear=0;
 q->front=0;
 q->numberItems=0;
 q->Capacity=size;
 q->items=malloc(size*sizeof(int));
}

void enqueue(Queue *q,int value)
{
 q->items[q->rear]=value;
 q->rear=(q->rear+1)%q->Capacity;
 q->numberItems++;
}


int dequeue(Queue *q)
{
 int data=q->items[q->front];
 q->front=(q->front+1)%q->Capacity;
 q->numberItems--;
 return data;
}

int isempty(Queue *q)
{
 if(q->numberItems==0)
 return 1;
 else
 return 0 ;
}

int isfull(Queue *q)
{
 if(q->numberItems==q->Capacity)
 return 1;
else
 return 0 ;
}

void display(Queue *q)
{
 Queue copy;
 initialize(&copy,q->Capacity);
 printf("[");
 while (!isempty(q))
 {
 int x=dequeue(q);
 printf("%d ",x);
 enqueue(&copy,x);
 }
 printf("]\n");
 while (!isempty(&copy))
 enqueue(q,dequeue(&copy));
}


int getHead(Queue *q)
{
 Queue copy;
 initialize(&copy,q->Capacity);
 int data=dequeue(q);
 enqueue(&copy,data);
 while (!isempty(q))
 enqueue(&copy,dequeue(q));
 while (!isempty(&copy))
 enqueue(q,dequeue(&copy));
 return data;
}


int getTail(Queue *q)
{
 int data;
 Queue copy;
 initialize(&copy, q ->Capacity);
 while (!isempty(q))
 {
 data=dequeue(q);
 enqueue(&copy,data);
 }
 while (!isempty(&copy))
 enqueue(q,dequeue(&copy));
 return data;
}
///////////////////////

typedef struct
{
 int data;
 struct Node *next;
} Node;
typedef struct
{
 Node *front, *rear;
} queue;

void initQueue_linked(queue *q)
{
 q->front=q->rear=NULL;

}

int isEmpty_linked(queue *q)
{
 if (q->front==NULL)
 return 1;
 return 0;
}


void enqueue_linked ( queue *q,int y)
{
 Node *ptr=malloc(sizeof(Node));
 ptr->data=y;
 ptr->next=NULL;
 if(q->front==NULL)
 q->front = q->rear= ptr;
 else
 {
 q->rear->next=ptr;
 q->rear=ptr;
 }
}

int dequeue_linked (queue *q)
{
 int num;
 Node*p=q->front;
 if(q->front==NULL)
 {q->rear=NULL;
    return NULL;}
 else
 {
 num=q->front->data;
 q->front = q->front->next;
 free(p);
 return num;
 }
}

void display_linked(queue *q)
{
 queue copy;
 initQueue_linked(&copy);
 printf("[");
 while (!isEmpty_linked(q))
 {
 int x=dequeue_linked(q);
 printf("%d ",x);
 //printf(" %d\n",isEmpty_linked(q));
 enqueue_linked(&copy,x);
 }
 printf("]\n");
 while (!isEmpty_linked(&copy))
 enqueue_linked(q,dequeue_linked(&copy));

}


int getHead_linked(queue *q)
{
 queue copy;
 initQueue_linked(&copy);
 int data=dequeue_linked(q);
 enqueue_linked(&copy,data);
 while (!isEmpty_linked(q))
 enqueue_linked(&copy,dequeue_linked(q));
 while (!isEmpty_linked(&copy))
 enqueue_linked(q,dequeue_linked(&copy));
 return data;
}


int getTail_linked(queue *q)
{
 int data;
 queue copy;
 initQueue_linked(&copy);
 while (!isEmpty_linked(q))
 {
 data=dequeue_linked(q);
 enqueue_linked(&copy,data);
 }
 while (!isEmpty_linked(&copy))
 enqueue_linked(q,dequeue_linked(&copy));
 return data;
}

int main()
{
    Queue q1;
    initialize(&q1,7);
    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    dequeue(&q1);
    printf("Queue \n");
    display(&q1);
    printf("head is %d Tail is %d \n\n\n",getHead(&q1),getTail(&q1));
    /////////////////////
   queue q2;
   initQueue_linked(&q2);

   enqueue_linked(&q2,1);
    enqueue_linked(&q2,2);
    enqueue_linked(&q2,3);
    enqueue_linked(&q2,4);
    enqueue_linked(&q2,5);
    dequeue_linked(&q2);
    printf("Queue using Linked List\n");
   display_linked(&q2);
   printf("head is %d Tail is %d \n",getHead_linked(&q2),getTail_linked(&q2));


    return 0;
}
