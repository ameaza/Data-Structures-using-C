#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
typedef struct
{
char arr[SIZE];
int tos;
}Stack;


void push (Stack *p,char x)
{
        p->tos++;
        p->arr[p->tos]=x;
}
//Pop Function
char pop(Stack *p)
{
        return(p->arr[p->tos--]);
}
int main()
{
        Stack s1;
        char a[SIZE];
        int i;
        s1.tos=-1;
        printf("\nEnter an expression:\n");
        gets(a); //Taking the expression to be checked from user

        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='('||a[i]=='{'||a[i]=='[') //Condition for opening bracket
                {
                    push(&s1,a[i]); //Pushing the opening bracket
                }
            else if(a[i]==')'||a[i]=='}'||a[i]==']') //if the character is any of the closing brackets
                {
                    if(s1.tos != -1)
                    {
                        char bracket;
                        bracket = pop(&s1);//comparing the the left bracket with the right bracket
                        switch(a[i])
                        {

                                case ')':
                                if( bracket == '{' || bracket == '[' )

                                {

                                    printf("\nCorresponding '(' missing");

                                    exit(0);

                                }
                                break;
                                case ']':

                                if( bracket == '{' || bracket == '(' )

                                {

                                printf("\nCorresponding '[' missing");

                                exit(0);

                                }
                                break;
                                case '}':

                                if( bracket == '(' || bracket == '[' )

                                {

                                printf("\nCorresponding '{' missing");

                                exit(0);

                                }
                        }

                        }
                else
                { //if stack is empty

                        printf("\nCorresponding '(' or '{' or '[' missing"); // does not have an opening bracket


                        exit(0); // exit from program  with return status as 0
                }
            }
        }

if(s1.tos != -1) //check if stack is not empty
        printf("\nCorresponding ')' or '}' or ']' missing");
else //if stack is empty
        printf("\nMatched"); //equal no of brackets
return 0;
}
