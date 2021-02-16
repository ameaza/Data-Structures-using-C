#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct node                          // defining a Node
{
        int info;
        struct node *next;
} Node;

typedef struct                              // forming a Dynamic stack using the 'Node'
{
        Node *tos;
} StackLL;


void push(StackLL *ptr, int x,int n)
{
        Node *p;
        p=(Node *)malloc(n*sizeof(Node));   // allotting memory
        p->info=x;
        if(ptr->tos==NULL)                  // if the Linked List is Empty
{
            ptr->tos=p;                    //tos = p
            p->next=NULL;
}
        else                                // if Linked List is Not EMpty
{
            p->next=ptr->tos;              //p->next = tos
            ptr->tos=p;                    //tos = p, newly created node becomes top of the stack
}
}


int pop(StackLL *ptr)
{
        Node *p;
        int x;
        if(ptr->tos==NULL)
        {
            printf("\nStack underflow\n");
            return;
        }
        else
        {
            p=ptr->tos;                     //p is pointer pointing to top of the stack
            x=p->info;                      //store its data into 'x'
            ptr->tos=p->next;               //tos = tos->next
            free(p);                        //release the memory pointed by p
            return x;
        }
}

void empty()
{
    if (tos == NULL)
        printf("STACK IS EMPTY\n");
    else
        printf("elements are present, stack is not empty \n");
}

// to check if stack is full
void stack_full()
{
    int count;

    count = stack_count();
    if (count == MAX)
    {
        printf("stack is full\n");
    }
    else
        printf("stack is not full \n");
}

// to count the number of elements
int stack_count()
{
    int count = 0;
    node_t *temp;

    temp = top;
    while (temp != NULL)
    {
        printf(" %d\n",temp->data);
        temp = temp->link;
        count++;
    }
    printf("size of stack is %d \n",count);
    return count;
}

int st_count()
{
    int count = 0;
    node_t *temp;
    temp = top;
    while (temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}



void display(StackLL s)
{
            Node *p;
            p=s.tos;
            while(p!=NULL)
            {
                    printf("%d\n",p->info);
                    p=p->next;
            }
}


int main()
{
            int choice,ele,n;
            StackLL s1;                 //stack s1 created using LL
            s1.tos=NULL;                //Initially no node
            do
            {
                printf("\nEnter your choice : \n1.Insert the Element \n2.Delete theElement \n3.Display the Stack Elements \n4.Exit\n");
                scanf("%d",&choice);     // choosing from the menu
            switch(choice)
            {
            case 1 :
                    printf("Enter the number of elements to be added: ");
                    scanf("%d",&n);
                    for(int i=1;i<=n;i++)
                    {
                    printf("Enter the element to be added:");
                    scanf("%d",&ele,n);
                    push(&s1,ele,n);
                    }
                    break;
            case 2 :
                    printf("\nThe Popped element is %d",pop(&s1));
                    break;
            case 3:
                    printf("\nThe Stack is :\n");
                    display(s1);
                    }
            }
            while (choice!=4);           // as long as the user doesn't want to exit
            return 0;
}
