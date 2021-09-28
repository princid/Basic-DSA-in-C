#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;
void createlist(int n);          // function to create the list
void newnodeinbeg(int a);        // function to insert new node at begnning 
void newnodeinend(int a, int n); // function to insert new node at end
void newnodeinmid(int a, int p); // function to insert new node in middle
void deleteatbeg();              // function to delete node at begnning
void deleteatend();              // function to delete node at end
void deleteatmid(int p);         // function to delete node at middle
void displaylist();              // function to display the list
int main()
{
    int n,x,y,z,a,d,e,f,m,p;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    createlist(n);
    printf("\n Data entered in the list are : \n");
    displaylist();
    printf("\n\nTo insert a node at the BEGINNING of list, Enter 1: ");
    scanf("%d",&x);
    if(x==1)
    {
    printf("\nEnter the data you want to insert in begnning=");
    scanf("%d",&a);
    newnodeinbeg(a);
    printf("\n Data entered in the list after insertion are : \n");
    displaylist(m);
    }
    else
    {
     printf("\n\nNot interested to insert any node at begnning!!");
     printf("\n\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo insert a node at the END of list, Enter 1: ");
    scanf("%d",&y);
    if(y==1)
    {
    printf("\nEnter the data you want to insert in end = ");
    scanf("%d",&a);
    newnodeinend(a,n);
    printf("\n Data entered in the list after insertion are : \n");
    displaylist();
    }
    else
    {
     printf("\n\nNot interested to insert any node at end!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo insert a node in the MIDDLE of list, Enter 1: ");
    scanf("%d",&z);
    if(z==1)
    {
    printf("\nEnter the position where you to insert the node=");
    scanf("%d",&p);
    printf("\nEnter the data you want to insert at %d node =",p);
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
    printf("\n\nTo delete a node at the BEGINNING of list, Enter 1: ");
    scanf("%d",&d);
    if(d==1)
    {
      deleteatbeg();
      printf("\n Data in the list after deletion are : \n");
      displaylist();  
    } 
    else
    {
     printf("\n\nNot interested to delete any node at begnning!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo delete a node at the END of list, Enter 1: ");
    scanf("%d",&e);
    if(e==1)
    {
      deleteatend();
      printf("\n Data in the list after deletion are : \n");
      displaylist();  
    }
    else
    {
     printf("\n\nNot interested to delete any node at end!!");
     printf("\n\n Data entered in the list are : \n");
     displaylist();
    }
    printf("\n\nTo delete a node at the MIDDLE of list, Enter 1: ");
    scanf("%d",&f);
    if(f==1)
    {
      printf("\nEnter the position at which you want to delete the node=");
      scanf("%d",&p);
      deleteatmid(p);
      printf("\n Data in the list after deletion are : \n");
      displaylist();  
    }
    else
    {
     printf("\n\nNot interested to delete any node at end!!");
     printf("\n Data entered in the list are : \n");
     displaylist();
    }
    return 0;
}
void createlist(int n)
{
    struct node *ptr, *tmp;
    int a, i;
    head = (struct node *)malloc(sizeof(struct node));
     printf(" Input data for node 1 : ");
    scanf("%d", &a);
    head->data = a;      
    head->next= NULL; 
    tmp = head;
    for(i=2; i<=n; i++)
       {
            ptr = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf(" %d", &a);
            ptr->data = a;     
            ptr->next = NULL; 
            tmp->next = ptr; 
            tmp = ptr; 
       }
       tmp->next=head;
}
void displaylist()
{
    int n;
    struct node *tmp;
    tmp = head;
       do 
        {
            printf("%d\t", tmp->data);       
            tmp = tmp->next;
            n++;                    
        }while(tmp != head);
}
void newnodeinbeg(int a)
{
    struct node *ptr1,*temp;
    ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->data=a;
    ptr1->next=head;
    temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=ptr1;
    head=ptr1;
}
void newnodeinend(int a, int n)
{
 struct node *temp, *ptr;
 int i;
 ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=a;
    ptr->next=NULL;
 temp=head;
 for(i=1;i<=n;i++)
  {
    temp=temp->next;
  }
  ptr->next=head;
  temp->next=ptr;
}
void newnodeinmid(int a, int p)
{
    int i;
    struct node *ptr,*ptr1;
    ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->data=a;
    ptr1->next=NULL;
    ptr=head;
    for (i=1;i<p-1;i++)
    {
        ptr=ptr->next;
    }
    ptr1->next=ptr->next;
    ptr->next=ptr1;
}
void deleteatbeg()
{
    int i;
    struct node *temp,*temp1; 
    temp=head;
    while(temp->next!=head)
     {
       temp=temp->next;
     }
     temp1=head;
    for(i=1;i<=1;i++)
     {
       temp1=temp1->next;
     }
     head=temp1;
    temp->next=head;
}
void deleteatend()
{
    struct node *temp,*prev;
    temp=head;
    while (temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
}
void deleteatmid(int p)
{
    int i;
    struct node *temp,*temp1;
    temp=head;
    for (i=1;i<p;i++)
    {
      temp=temp->next;
    }
    temp1=head;
    for (i=1;i<p-1;i++)
    {
      temp1=temp1->next;
    }
    temp1->next=temp->next;
}
