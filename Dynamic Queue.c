#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
            int data;
            struct node *next;
}Node;
typedef struct

{
        Node *front,*rear;
}QueueLL;


void enqueue(QueueLL *ptr,int x)
{
         Node *p;
         p=(Node*)malloc(sizeof(Node));
         p->data = x;
         p->next = NULL;
         if(ptr->rear == NULL)
         ptr->rear = ptr->front = p; //this is the first Node
         else
         {
         ptr->rear->next = p;       // if there are nodes already then just increment the rear pointer
         ptr->rear = p;
         }
}


int dequeue(QueueLL *ptr)
{
         Node *q;
         int x;
         if(ptr->front == NULL)         // if queue is empty
         {
             printf("\nQueue is empty");
             return -1;
         }
         else
         {
             q = ptr->front;
             x = q->data;
             ptr->front = ptr->front->next;  //moving to the next pointer
         if(ptr->front == NULL)
         {
            ptr->rear=NULL;             //to avoid dangling pointer due to deletion
         }
         free(q);
         return x;
         }
}


void display(QueueLL temp)
{
         Node *q;
         for(q=temp.front;q!=NULL;q=q->next)   // traversing all the pointers and printing the data
            printf("\t%d",q->data);
}


int  main()
{
 QueueLL q;
 int choice , num;
 q.front = q.rear = NULL;
 do
 {
     printf("\n**********MENU*************\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice : ");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
         printf("\nEnter element : ");
         scanf("%d",&num);
         enqueue(&q,num);
         break;
     case 2:
         printf("\nThe deleted element is %d",dequeue(&q));
         break;
     case 3:
         printf("\nDisplaying elements : ");
         display(q);
         break;
     }
 }
 while(choice!=4);
 return 0;
}
