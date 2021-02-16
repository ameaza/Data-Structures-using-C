#include <stdio.h>
#include <stdlib.h>
#define SIZE 20


typedef struct {
   int a[SIZE];
   int rear, front;
}circularQ;


void circularQenqueue( circularQ *p, int newValue)
{
    if((p->rear + 1 )%SIZE == 0 && p->front == 0){
        printf("This Circular Queue is Full");

    }
    else if (p->rear == SIZE - 1){
        p->rear= 0;
        p->a[p->rear] = newValue;
    }
    else if (p->front != -1){
        p->rear++;
        p->a[p->rear] = newValue;
    }
    else {
        p->front++;
        p->rear++;
        p->a[p->rear] = newValue;
    }
}

int circularQdequeue(circularQ *p)
{   int x;
    if(p->front == -1){                             // checking if the queue is empty
        printf("This Circular Queue is Empty");
        x= NULL;
    }
    else if (p->front = SIZE -1){                   // checking if the front pointer is pointing to the last memory of the array
        x = p->a[p->front];
        p->front =0;
    }
    else if (p->front = p->rear){                 //if the queue has only one element left
        x = p->a[p->front];
        p->front= p->rear -1;
    }
    else{
        x = p->a[p->front];
        p->front++;
    }
    return x;

}
void display(circularQ p)
{
    int i;
    printf("\n");
    if (p.front == -1 && p.rear == -1)              // if queue is empty
    {
        printf ("\n QUEUE IS EMPTY");
    }
    else
    {
        if(p.front<p.rear)                              // condition ehrm ther
        {
            for(i=p.front;i<=p.rear;i++)
                printf("\t %d", p.a[i]);
        }
        else
        {
            for(i=p.front;i<SIZE;i++)
                printf("\t %d", p.a[i]);
            for(i=0;i<=p.rear;i++)
                printf("\t %d", p.a[i]);
        }
    }
}

int isFull(circularQ p)
{
    if ( p.rear == p.front ){
        return 1;
    }
    else return 0;
}

int Empty(circularQ p)
{
    if ( p.rear == p.front == -1 ){
        return 1;
    }
    else return 0;
}







int main()
{
   circularQ q1;
   int x,choice;
   char ch;
   q1.front = q1.rear = -1;

    do
        {
            printf("Enter the choice: 1.Enqueue 2.Dequeue 3.Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                    printf("Enter element to be inserted :\n");
                    scanf("%d",&x);
                    circularQenqueue(&q1,x);
                    break;
            case 2:
                    x = circularQdequeue(&q1);
                    printf("The removed element is %d\n",x);
                    break;
            case 3:
                    printf("Queue Contents\n");
                    display(q1);

            }

         printf("\nDo u want to continue:= ");
         scanf("%c",&ch);
 }while(ch == 'y' || ch == 'Y');
    return 0;
}
