#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20


typedef struct
    {
      char *name;
      int regNo;
    }Student;

typedef struct
    {
        Student S[SIZE];
        int rear, front;
    }databaseQ;



//database operations
void addStudent (databaseQ *q, char NameS[SIZE]  ,int Nos)
    {
        if (q->rear != SIZE-1)

        {  q->rear++;
           q->S->name = NameS;
           q->S->regNo = Nos;
        }
        else printf("Database is Full");
    }


void displayStudent (databaseQ *q)
    {
        if(q->rear!= NULL)
        {
            printf("%s",(q->S)->name);
            printf("%d", (q->S)->regNo);
        }
        else printf ("The database is empty");
    }

void removeStudent (databaseQ *q)
    {
       if(q->rear!= NULL)
        {
           // printf("%s",(q->S)->name);
           // printf("%d", (q->S)->regNo);
            q->rear--;
        }
        else printf ("The database is empty");

    }



int main()
{   int choice;
    databaseQ Q1;
    Q1.front = Q1.rear = -1;
    Q1.S->name = "Lisa";
    Q1.S->regNo = 49;
    Q1.front = Q1.rear = Q1.rear++;


    printf("Press 1 to add a new student \n");
    printf("Press 2 to remove a  student from the database \n");
    printf("Press 3  to view student's information \n");
    scanf("%d", choice);
    switch(choice)
    {
      case 1 :
            printf ("Enter the Student\'s Name");
            char NameS[SIZE] ;
            int NoS;
            scanf("%s",&NameS);
            printf ("Enter the Student\'s Registration number");
            scanf ("%d",&NoS);


            break;

      case 2 :
            removeStudent (&Q1);
            break;

      case 3:
            displayStudent (&Q1);
            break;




    }

}
