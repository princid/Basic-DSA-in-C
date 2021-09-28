#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
} *head,*end;
void createlist(int n);            // function to create the list
void newnodeinbeg(int a);          // function to insert new node at begnning
void newnodeinend(int a);          // function to insert new node at end
void newnodeinmid(int a,int p);    // function to insert new node at middle
void deleteatbeg();                // function to delete node at begnning
void deleteatend();                // function to delete node at end
void deleteatmid(int p);           // function to delete node at middle
void displaylist();                // function to display the list
int main()
{
    int n,x,y,z,d,e,f,a,p;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    createlist(n);
    printf("\n Data entered in the list are : \n");
    displaylist();
    printf("\n\nTo insert a node at the begnning of list, Enter 1: ");
    scanf("%d",&x);
    if(x==1)
    {
    printf("\nEnter the data you want to insert in begnning=");
    scanf("%d",&a);
    newnodeinbeg(a);
    printf("\n Data entered in the list after insertion are : \n");
    displaylist();
    }
    else
    {
     printf("\n\nNot interested to insert any node at begnning!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo insert a node at the end of list, Enter 1: ");
    scanf("%d",&x);
    if(x==1)
    {
    printf("\nEnter the data you want to insert in end=");
    scanf("%d",&a);
    newnodeinend(a);
    printf("\n Data entered in the list after insertion are : \n");
    displaylist();
    }
    else
    {
     printf("\n\nNot interested to insert any node at end!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo insert a node in the middle of list, Enter 1: ");
    scanf("%d",&z);
    if(z==1)
    {
    printf("\nEnter the position at which you want to insert the node=");
    scanf("%d",&p);
    printf("\nEnter the data you want to insert in %d node=",p);
    scanf("%d",&a);
    newnodeinmid(a,p);
    printf("\n Data entered in the list after insertion are : \n");
    displaylist();
    }
    else
    {
     printf("\n\nNot interested to insert any node in middle!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo delete a node at the begnning of list, Enter 1: ");
    scanf("%d",&d);
    if(d==1)
    {
    deleteatbeg();
    printf("\n\n Data in the list after deletion of an element at begnning are : \n");
    displaylist();
    }
    else
    {
     printf("\n\nNot interested to delete any node at begnning!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
     printf("\n\nTo delete a node at the end of list, Enter 1: ");
    scanf("%d",&e);
    if(e==1)
    {
    deleteatend();
    printf("\n\n Data in the list after deletion of an element at end are : \n");
    displaylist();
    }
    else
    {
     printf("\n\nNot interested to delete any node at end!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo delete a node in the middle of list, Enter 1: ");
    scanf("%d",&f);
    if(f==1)
    {
    printf("\n\nEnter the position at which you want to delete the node=");
    scanf("%d",&p);
    deleteatmid(p);
    printf("\n\n Data in the list after deletion of an element in the middle are : \n");
    displaylist();
    }
    else
    {
     printf("\n\nNot interested to delete any node in the middle!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    return 0;
}
void createlist(int n)
{
    struct node *ptr;
    int a, i;
    head = (struct node *)malloc(sizeof(struct node));
     printf(" Input data for node 1 : ");
    scanf("%d", &a);
    head->data = a;
    head->prev=NULL;      
    head->next=NULL; 
    end = head;
    for(i=2; i<=n; i++)
       {
            ptr = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf(" %d", &a);
            ptr->data = a;
            ptr->prev=end;     
            ptr->next = NULL; 
            end->next = ptr; 
            end=ptr;
       }
}
void displaylist()
{
    struct node *tmp;
    tmp = head;
        while(tmp != NULL)
        {
            printf("%d\t", tmp->data);      
            tmp = tmp->next;                    
        }
}
void newnodeinbeg(int a)
{
    struct node *ptr1;
    ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->data=a;
    ptr1->prev=NULL;
    ptr1->next=head;
    head=ptr1;
}
void newnodeinend(int a)
{
    struct node *ptr1;
    ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->data=a;
    ptr1->prev=end;
    ptr1->next=NULL;
    end->next=ptr1;
    end-ptr1;
}
void newnodeinmid(int a, int p)
{
    int i;
    struct node *ptr1,*tmp;
    tmp =head;
        i=1;
        while(i<p-1 && tmp!=NULL)
        {
            tmp = tmp->next;
            i++;
        }
    ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->data=a;
    ptr1->next = tmp->next;             
    ptr1->prev = tmp;              
    if(tmp->next != NULL)
        {
            tmp->next->prev = ptr1;
        }
    tmp->next = ptr1;
}
void deleteatbeg()
{
    struct node *ptr1;
    ptr1=head;
    head = head->next;   
    head->prev = NULL;
}
void deleteatend()
{
    struct node *ptr1;
    ptr1 = end;
    end = end->prev;    
    end->next = NULL;
}
void deleteatmid(int p)
{
    int i;
    struct node *ptr1;
    ptr1 = head;
    for(i=1; i<p && ptr1!=NULL; i++)
    {
        ptr1 = ptr1->next;
    }
    ptr1->prev->next = ptr1->next;
    ptr1->next->prev = ptr1->prev;
}
