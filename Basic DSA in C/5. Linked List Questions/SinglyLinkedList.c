//Singly Linked List(SLL):-
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*stnode;

void createNodeList(int n);                      //function to create the list
void NodeInsertatBegin(int num);	            //function to insert node at the beginning
void NodeInsertatEnd(int num);                 //function to insert node at the end
void insertNodeAtMiddle(int num, int pos);    //function to insert node at mid
void FirstNodeDeletion();	                 //function to delete the first node
void LastNodeDeletion();	                //function to delete the last nodes
void MiddleNodeDeletion(int pos);	       //function to delete a node from middle
void displayList();                       //function to display the list
 
int main()
{
    int n,num,pos;
	printf("\n\n Linked List : Insert a new node at the beginning of a Singly Linked List:\n");
	printf("------------------------------------------------------------------------------\n\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list are : \n");		
    displayList();
    
    printf("\n Input data to insert at the beginning of the list : ");
    scanf("%d", &num);
    NodeInsertatBegin(num);
    printf("\n Data after inserted in the list are : \n");		
    displayList();
    
    printf("\n Input data to insert at the end of the list : ");
    scanf("%d", &num);
    NodeInsertatEnd(num);
    printf("\n Data, after inserted in the list are : \n");		
    displayList();
    
    printf("\n Input data to insert in the middle of the list : ");
    scanf("%d", &num);
    printf(" \nInput the position to insert new node : " );
    scanf("%d", &pos);
        if(pos<=1 || pos>=n)
    {
     printf("\n Insertion can not be possible in that position.\n ");
    }
        if(pos>1 && pos<=n)      
      {
        insertNodeAtMiddle(num, pos);
        printf("\n Insertion completed successfully.\n ");
      }
    printf("\n The new list is : \n");		
    displayList();
    
    FirstNodeDeletion();
    printf("\n The new List after deletion of the first node : \n");		
    displayList();
    
    LastNodeDeletion();
	printf("\n The new list after deletion of the last node : \n");	
    displayList();
    
    printf("\n Input the position of node to delete : ");
    scanf("%d", &pos);

    if(pos<=1 || pos>=n)
    {
     printf("\n Deletion can not be possible from that position.\n ");
    }
	    if(pos>1 && pos<n)
        {
          printf("\n Deletion completed successfully.\n ");
	      MiddleNodeDeletion(pos);
        }

    printf("\n The new list is  : \n");	
    displayList();

    return 0;
}
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
 
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) //check whether the stnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode-> num = num;      
        stnode-> nextptr = NULL; //Links the address field to NULL
        tmp = stnode;
 
//Creates n nodes and adds to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
 

            if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
} 

void NodeInsertatBegin(int num)
{
    struct node *fnNode;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num; //Links the data part
        fnNode->nextptr = stnode; //Links the address part
        stnode = fnNode; //Makes stnode as first node
    }
}

void NodeInsertatEnd(int num)
{
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num;     //Links the data part
        fnNode->nextptr = NULL; 
        tmp = stnode;
        while(tmp->nextptr != NULL)
            tmp = tmp->nextptr;
        tmp->nextptr = fnNode;  //Links the address part
    }
}

void insertNodeAtMiddle(int num, int pos)
{
    int i;
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num; //Links the data part
        fnNode->nextptr = NULL;
        tmp = stnode;
        for(i=2; i<=pos-1; i++)
        {
            tmp = tmp->nextptr;
 
            if(tmp == NULL)
                break;
        }
        if(tmp != NULL)
        {
            fnNode->nextptr = tmp->nextptr;  //Links the address part of new node
            tmp->nextptr = fnNode;   
        }
        else
        {
            printf(" Insert is not possible to the given position.\n");
        }
    }
}

void FirstNodeDeletion()
{
    struct node *toDelptr;
    if(stnode == NULL)
    {
        printf(" There are no node in the list.");
    }
    else
    {
        toDelptr = stnode;
        stnode = stnode->nextptr;
        printf("\n Data of node 1 which is being deleted is :  %d\n", toDelptr->num);
        free(toDelptr);  // Clears the memory occupied by first node
    }
}

// Deletes the last node of the linked list
void LastNodeDeletion()
{
    struct node *toDelLast, *preNode;
    if(stnode == NULL)
    {
        printf(" There is no element in the list.");
    }
    else
    {
        toDelLast = stnode;
        preNode = stnode;
        /* Traverse to the last node of the list*/
        while(toDelLast->nextptr != NULL)
        {
            preNode = toDelLast;
            toDelLast = toDelLast->nextptr;
        }
        if(toDelLast == stnode)
        {
            stnode = NULL;
        }
        else
        {

            /* Disconnects the link of second last node with last node */
            preNode->nextptr = NULL;
        }
 
        /* Delete the last node */
        free(toDelLast);
    }
}

void MiddleNodeDeletion(int pos)
{
    int i;
    struct node *toDelMid, *preNode;
 
    if(stnode == NULL)
    {
        printf(" There are no nodes in the List.");
    }
    else
    {
        toDelMid = stnode;
        preNode = stnode;
 
        for(i=2; i<=pos; i++)
        {
            preNode = toDelMid;
            toDelMid = toDelMid->nextptr;
 
            if(toDelMid == NULL)
                break;
        }
        if(toDelMid != NULL)
        {
            if(toDelMid == stnode)
                stnode = stnode->nextptr;
 
            preNode->nextptr = toDelMid->nextptr;
            toDelMid->nextptr = NULL;
            free(toDelMid);
        }
        else
        {
            printf(" Deletion can not be possible from that position.");
        }
    }
}


void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
} 

