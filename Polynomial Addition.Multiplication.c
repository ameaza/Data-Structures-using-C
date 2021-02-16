#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int coeff,exp;
   node *next;
};

void multipy_2_polys(Node *poly1,  Node *poly2 ,Node *poly3)
{
     Node *ptr1, *ptr2;
     ptr1 = poly1; //intialising the pointers
     ptr2 = poly2;  //with the pointers of LL pointing to the polynomials to be multiplied



     while  (ptr1!= NULLL){
       while (ptr2 != NULL){

      int Coeff , Exp;
       Coeff =  ptr1->coeff * ptr2->coeff;
       Exp = ptr1->exp + ptr2->exp;
       poly3 = addnode(poly3, coeff, Exp);
       ptr2 = ptr2->next;

     }
       ptr2 = poly2;
       ptr1 = ptr1->next;

       }
      addSameDegree(poly3);
      return poly3;


}


void addSameDegree(Node* start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        // Compare the picked element
        // with rest of the elements
        while (ptr2->next != NULL) {

            // If powerer of two elements are same
            if (ptr1->power == ptr2->next->power) {

                // Add their coefficients and put it in 1st element
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;

                // remove the 2nd element
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


// Function add a new node at the end of list
Node* addnode(Node* start, int coeff, int power)
{
    // Create a new node
    Node* newnode = new Node;
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;

    // If linked list is empty
    if (start == NULL)
        return newnode;

    // If linked list has nodes
    Node* ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;

    return start;
}
