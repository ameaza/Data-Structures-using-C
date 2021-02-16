#include<stdio.h>
#include<stdlib.h>
struct tnode
{
        int data;
        struct tnode *left,*right;
};


typedef struct
{
        struct tnode *root;
} Tree;


void insert(Tree *tr,int x)//insert into tree a new node with data x
{ //it is always inserted as a leaf node
            struct tnode *p,*prev;
            prev=NULL;
            p=(struct tnode *)malloc(sizeof(struct tnode)); //new node created
            p->data=x;
            p->left=p->right=NULL; //leaf node
            if(tr->root == NULL) //if tree is empty
            {
            tr->root=p; //newly created node becomes root
            }
            else
            {
            struct tnode *q=tr->root;
            while(q!=NULL) // if node is there
            {
            prev=q; //make that node as parent
            if(p->data < q->data) //update q
            q=q->left;
            else
            q=q->right;
            }
            //a new node p is inserted after prev node
            if(p->data >= prev->data) prev->right=p; //if data is greater in p, aƩach p as parent's(prev) right son
            else
            prev->left=p;//if data is smaller in p, a each p as parent's(prev) left son
            }
}


void delete(Tree *tr,int x)
{
            struct tnode *p,*q,*prev,*r;
            prev=NULL; //root node doesnt have parent
            p=tr->root; //start from root node
            while(p!=NULL) //search the data x
            {
                    if(p->data==x)
                    break;
                    prev=p; //keep track of parent of p
                    if(x < p->data)
                    p=p->left;
            else
                    p=p->right;
            }
            if(p==NULL)
                    printf("Data not found\n");
            else
            {
            if( p->left == NULL || p->right == NULL) //case 1 or case 2
                    q = p; //q is node to be deleted
            else //case 3
            {
                    prev = p; //inorder successor parent
                    q = p->right; //currently right son is inorder sucessor
            while ( q->left != NULL) // if leŌ son present
            {
                    prev = q; //parent of r
                    q= q->left;
            }
            p->data = q->data; //copy q node data to p node data
            }
            //in the following part, q node is deleted
            //q is replaced by node r
            if( q->left == NULL) //in case 1, r is NULL
                    r = q->right;
            else
                    r = q->left;
            if(prev==NULL) // q is root node, then no parent to it
                    tr->root = r; //root is r
            else if(prev->left==q) //q is left son of its parent, r becomes left son replacing q
                    prev->left = r;
            else //q is right son of its parent, r becomes right son replacing q
                    prev->right = r;
                    free(q);
                    printf("Data deleted");
            }
}


struct node *iterative_tree_search(struct tnode *rt, int key)
{
while( rt != NULL) //if node exist
{
        if ( key == rt->data) //compare for equality
        {
                printf("\nData Found\n");
                return rt; //if found, return node's address
        }
        else if (key < rt->data) //if not found and key is less than node's data, go to leŌ subtree
                rt = rt->left;
        else //if not found and key is greater than node's data, go to right subtree
                rt = rt->right;
        }
        printf("\nData Not Found\n");
        return rt; // if key not found then this stmt is reachable, and return NULL
}


struct tnode *tree_search(struct tnode *rt, int key)
{
        if (rt == NULL) //if no node in a tree return NULL
        {
                printf("\nData Not Found\n");
                return NULL;
        }
        else if( key == rt->data) // if matches, return address of that node
        {
                printf("\nData Found\n");
                return rt;
        }
        else if (key < rt->data) //if key is less than node's data then go search in Left subtree
                return(tree_search(rt->left,key));
        else
                return(tree_search(rt->right,key));//if key is greater than node's data then go search in right subtree
}


int tree_minimum(struct tnode *rt)
{
        while( rt->left != NULL) //if left son present
        {
                rt = rt->left; //go to that left son
        }
        return rt->data; //leftmost node reached
}


int tree_maximum(struct tnode *rt)
{
        while( rt->right != NULL) //if right son present
        {
                rt = rt->right;
        }
        return rt->data; //rightmost node has largest data, return its address
}


int countnodes(struct tnode *rt)
{
        if( rt == NULL) //if no nodes in tree, return count as 0
                return 0;
        else //otherwise
{
        return( 1+ countnodes(rt->left)+countnodes(rt->right)); //count the node + nodes in LeŌ subtree+ nodes in Right Subtree
}
}

int countleafnodes(struct tnode *rt)
{
        if (rt == NULL) //if no nodes in tree, return 0
                return 0;
        else if(rt->left == NULL && rt->right == NULL) //if leaf node, count it's occurence, therefore return 1
                return 1;
        else
        {
                return(countleafnodes(rt->left)+countleafnodes(rt->right)); //if nonleaf node, count leaf nodes in left subtree + count nodes in Right subtree
        }
}

int height(struct tnode *rt)
{
            int lh,rh;
            if(rt==NULL) //empty tree has height -1
                    return -1;
            else if(rt->left == NULL && rt->right == NULL) //leaf node is at height 0
                    return 0;
            else //for nonleaf node
            {
                    lh=height(rt->left); //calculate height of leŌ subtree
                    rh=height(rt->right); //calculate height of right subtree
            if(lh > rh) //since a parent is always one level above its childern level
                    return lh+1; //add 1 to largest height
            else
                    return rh+1;
}
}


void inorder(struct tnode *rt)
{
            if(rt!=NULL)
            {
                    inorder(rt->left);
                    printf("%d\t",rt->data);
                    inorder(rt->right);
            }
}


void preorder(struct tnode *rt)
{
            if(rt!=NULL)
            {
                    printf("%d\t",rt->data);
                    preorder(rt->left);
                    preorder(rt->right);
            }
}


void postorder(struct tnode *rt)
{
                    if(rt!=NULL)
                    {
                            postorder(rt->left);
                            postorder(rt->right);
                            printf("%d\t",rt->data);
                    }
}


void mirror(struct tnode *rt)
{
        if(rt!=NULL)
        {
                struct tnode *temp;
                mirror(rt->left);
                mirror(rt->right);
                temp = rt->left;
                rt->left = rt->right;
                rt->right = temp;
        }
}


int main()
{
        Tree t1; //tree t1 is created
        int min = 0,max = 0;
        t1.root=NULL;//Initially tree is empty
        int choice,ele,x;
        do
        {
                printf("\nEnter the choice from the following :\n");
                printf("1. Add an element in the binary tree\n");
                printf("2. Delete an element in the binary tree\n");
                printf("3. Display in inorder fashion\n");
                printf("4. Display in preorder fashion\n");
                printf("5. Display in postorder fashion\n");
                printf("6. Find the minimum element entered\n");
                printf("7. Find the maximum element entered\n");
                printf("8. Search for an element using iteration\n");
                printf("9. Search for an element using recursion\n");
                printf("10. Count the total number of nodes\n");
                printf("11. Count the number of leaf nodes\n");
                printf("12. Calculate height of the tree\n");
                printf("13. Mirror the tree\n");
                printf("14.Exit\n");
                scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be added to the binary tree :");
            scanf("%d",&ele);
            insert(&t1,ele);
            printf("\nThe element %d is inserted\n",ele);
            break;
        case 2:
            printf("\nEnter the element to be deleted from binary tree :");
            scanf("%d",&ele);
            delete(&t1,ele);
            break;
        case 3:
            printf("\nThe numbers in the inorder fashion are : ");
            inorder(t1.root);
            break;
        case 4:
            printf("\nThe numbers in the preorder fashion are : ");
            preorder(t1.root);
            break;
        case 5:
            printf("\nThe numbers in the postorder fashion are : ");
            postorder(t1.root);
            break;
        case 6:
            min = tree_minimum(t1.root);
            printf("\nThe minimum element is : %d",min);
            break;
        case 7:
            max = tree_maximum(t1.root);
            printf("\nThe maximum element is : %d",max);
            break;
        case 8:
            printf("Enter the Element to be searched : ");
            scanf("%d",&x);
            printf("\nIterative searching\n");
            iterative_tree_search(t1.root,x);
            break;
        case 9:
            printf("Enter the Element to be searched : ");
            scanf("%d",&x);
            printf("\nRecursive searching\n");
            iterative_tree_search(t1.root,x);
            break;
        case 10:
            printf("\nThe Number of nodes in the tree are %d\n",countnodes(t1.root));
            break;
        case 11:
            printf("\nThe Number of leaf nodes in the tree are %d\n",countleafnodes(t1.root));
            break;
        case 12:
            printf("\nThe Height of the tree is %d\n",height(t1.root));
            break;
        case 13:
            mirror(t1.root);
            printf("\nThe mirrored tree is : ");
            inorder(t1.root);
        }
}
while(choice!=14);
return 0;
}
