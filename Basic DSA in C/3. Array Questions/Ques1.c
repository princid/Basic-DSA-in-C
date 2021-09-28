//Ques.1- Write a program to find an element using Binary Search. Insert the element if it does not exist already in the list.
#include<stdio.h>
int main()
{
	int a[100], k, N, i, search, first, middle, last, value;
	printf("Enter the number of Elements:\n");
	scanf("%d", &N);
	
	printf("Enter the elements:\n");

    for (i = 0; i < N; i++)
      scanf("%d", &a[i]);

    printf("Enter value to find:\n");
    scanf("%d", &search);
    
    first = 0;
	last = N-1;
    middle = (first+last)/2;
    
    while (first <= last) {
     if (a[middle] < search)
      first = middle + 1;
     else if (a[middle] == search) {
      printf("%d found at location %d.\n", search, middle+1);
      break;
     }
     else
      last = middle - 1;

     middle = (first + last)/2;
   }
    if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);
   
      // to insert the element at any position.
 
     printf("\nEnter the location where you wish to insert an element:\n");
     scanf("%d", &k);
 
     printf("Enter the value to insert:\n");
     scanf("%d", &value);
     
     for (i = N - 1; i >= k ; i--)
	   //shifting of elements
      a[i+1] = a[i];
 
      a[k] = value;  // inserting the element

     printf("Resultant array is:\n");
 
     for (i = 0; i <= N; i++)
     printf("%d\n", a[i]);  
     
}
