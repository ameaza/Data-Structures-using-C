#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

typedef struct {
  float arr[SIZE];
  int tos;
}Stack;

void push (Stack *p, float new_value)
{

   if (p->tos == SIZE-1)
    {
        printf ("the stack is full");
   }
   else
    {
     p->tos++;
     p->arr[p->tos]= new_value;
     //display (Stack *p);

   }

}

void pop (Stack *p)
{
    if (p->tos== -1){
        printf ("Error Stack underflow");
        return -1;
    }
    else
    {
        p->tos--;


    }
    void  display (Stack *p);
}
 float peek(Stack p)
 {
     printf ("%f",(p.arr[p.tos]));
 }

 void display(Stack *p)
 { int i;
   for (i=p->tos; i<=0 ;i--)
    {
        //float ele= (p->arr[i]);
        printf ("%f \n",p->arr[i]  );
    }

 }
void isEmpty(Stack *p)
{
    if (p->tos == -1)
    {
        printf("\n Stack is empty");
    }
    else
        printf("\n Stack is not empty");
}
void isFull(Stack *p)
{
    if (p->tos == SIZE-1)
        {
        printf("Stack is Full");
        }
    else
        printf ("Stack is not Full");
}

void stackSize(Stack *p)
{
    (printf("%f",(p->tos)+1));

}

int main ()

{   Stack p1;
    p1.tos = -1;
    Stack *ptr = &p1;
    push(ptr,20.3);
    //push(ptr,25.3);
    //push(ptr,25.3);

    //p1.arr[2]=33.0;
    //p1.tos++;
    int opt;
    do
    {
    printf("Select any of the following options");
    printf("\n Press 1 to pop");
    printf("\n Press 2 to push");
    printf("\n Press 3 to peek");
    printf("\n Press 4 to find if stack is empty");
    printf("\n Press 5 to find if stack is full");
    printf("\n Press 6 to find size of stack");
    printf("\n Press 7 to view the Stack");
    printf("\n Press 8 to Exit");
    printf("\n enter your option \n");
    scanf("%d",&opt);







    switch (opt)
    {

    case 1:
         pop(ptr);
         break;

    case 2:

        printf ("enter the value to be pushed onto the stack \n");
        float value;
        scanf ("%f",&value);
        push(&p1, value);
        display (ptr);
        break;

    case 3:
        peek (p1);
        break;

    case 4:
        isEmpty(ptr);

        break;

     case 5:
         isFull(ptr);
         break;

     case 6 :
         stackSize(ptr);
         break;

     case 7:
         display (ptr);




    }


    }
    while (opt != 8);
}

