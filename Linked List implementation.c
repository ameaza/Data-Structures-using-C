#include <stdio.h>
#include <stdlib.h>



    typedef struct node
    {
       int data;
       struct node *next;

    }Node;                                          // defining a Node

    typedef struct
    {
        Node *Start;
    }LL;                                             //defining a Linked List using A Node

    void insertBegin(LL *list, int newValue)
    {                                                   // function to add a value to the beginning
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));          // allotting memory to the newNode that is to be created
        newNode->data = newValue;
        newNode->next= list->Start;                 //current start node now becomes second node
        list->Start=newNode;

    }

    void insertEnd(LL *list, int newValue)
    {        // function to add a value to the end of the Linked List
        Node *p,*q;
        p=(Node *)malloc(sizeof(Node));             // allotting memory to the newNode that is to be created
        p->data=newValue;
        p->next=NULL;
        if(list->Start==NULL)                       // checking if the list is Empty
        {
            list->Start=p;

        }
        else                                        // if the list is not empty
        {
            q=list->Start;
            while(q ->next!=NULL)                   //traverse LL until u reach to last node
        {
            q=q->next;

        }
            q->next=p;                              //link last node with new node
        }



    }

    void insertAfterNth_node(Node *Start, int Nth_node,int newValue)
    {                                                   // to add a node after some 'n' number of nodes
        Node *p,*q;
        p=(Node *)malloc(sizeof(Node));             // allotting memory to the newNode that is to be created
        p->data=newValue;
        int i = 1;
        Node *prev = Start;
        q = Start;
        while(i!= Nth_node)
        {
            prev = q;
            q = q->next;
            i++;
        }
        prev = q;
        q= q->next;
        prev->next = p;
        p->next = q;


    }

    void display(LL list)
    {
                Node *q;
                q=list.Start;
                while(q!=NULL)
                {
                 printf("%d\n",q->data);      // printing all the elements of the Linked list
                 q=q->next;
                }
    }

    void deleteNode(LL *list,int x)
    {

        Node *q = list->Start;
        Node *p = NULL;
        while( q != NULL)
        {
            if (q->data == x)
            break;
            p = q;
            q = q->next;
        }
            if( q == NULL)
        {
            printf("Node with %d data not found\n",x);
        }
            else
        {
            if(list->Start == q)
        {
            list->Start = list->Start->next;
        }
            else
        {
            p->next = q->next;
        }
            free(q);
        }
    }

    /*int countNodes(Node *Start){
        int count = 0;
        while (Start!= NULL){
            Start = Start->next;

            count++;

        }
        printf("%d", count);

    }*/


    int countNodes( Node* Start)
{
    // Base case
    if (Start == NULL)
        return 0;

    // count is 1 + count of remaining list
    else
       return 1 + countNodes(Start->next);
}

    void concatanate(Node *Start1, Node *Start2){
        Node *prev;
        while (Start1 != NULL){


            prev = Start1;
            Start1 = Start1->next;


        }
        prev->next = Start2;


    }

    void reverseLL(LL *list){


            Node *q,*r,*p;
            p=NULL; //previous nod
            q=list->Start; //current node
            while(q!=NULL)
            {
                     r=q->next;
                     q->next=p;
                     p=q;
                     q=r;
            }
            list->Start=p;
    }








    int main()
    {

        LL l1,l2,l3; //three linked list of integers
        l1.Start=NULL;
        l2.Start=NULL;
        l3.Start=NULL;
        int choice,ele,count;
        do
        {
            printf("\nEnter your choice : 1.Insert at beg LL1 2.Insert at end 3.Display  4.Delete Data 5.Count Nodes 6.Concat 2 LL 7.Reverse 8.Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1 :
                    printf("Enter the element to be added at the beginning of the linked list :");
                    scanf("%d",&ele);
                    insertBegin(&l1,ele);
                    break;
                case 2 :
                    printf("Enter the element to be added at the end of the linked list :");
                    scanf("%d",&ele);
                    insertEnd(&l1,ele);
                    break;
                case 3 :
                    printf("The Linked list is :\n");
                    display(l1);
                    break;
                case 4 :
                    printf("Enter the data to be deleted:");
                    scanf("%d",&ele);
                    deleteNode(&l1,ele);
                    break;
                case 5 :
                    //count  = getCount(&l1);
                    printf("count of nodes is %d", countNodes(l1.Start));
                    break;
                case 6 :
                    insertEnd(&l2,60);
                    insertEnd(&l2,50);
                    insertBegin(&l2,40);
                    concatanate(&l1,&l2);
                    printf("The concatenated linked list is :\n");
                    display(l1);
                    break;
                case 7 :
                    insertEnd(&l3,80);
                    insertEnd(&l3,90);
                    insertBegin(&l3,100);
                    reverseLL(&l3);
                    display(l3);
            }
    }
     while (choice != 8);

          return 0;
     }

     /*
    1. push an element
2. pop an element
3. check if stack is empty
4. check if stack is full
5. count/display elements present in stack
6. Print top of the stack
7. exit
Enter your choice
1

Enter value which you want to push into the stack :
5
1. push an element
2. pop an element
3. check if stack is empty
4. check if stack is full
5. count/display elements present in stack
6. Print top of the stack
7. exit
Enter your choice
1

Enter value which you want to push into the stack :
2
1. push an element
2. pop an element
3. check if stack is empty
4. check if stack is full
5. count/display elements present in stack
6. Print top of the stack
7. exit
Enter your choice
2
Value popped out is 2
1. push an element
2. pop an element
3. check if stack is empty
4. check if stack is full
5. count/display elements present in stack
6. Print top of the stack
7. exit
Enter your choice
5
 5
size of stack is 1
1. push an element
2. pop an element
3. check if stack is empty
4. check if stack is full
5. count/display elements present in stack
6. Print top of the stack
7. exit
Enter your choice */



