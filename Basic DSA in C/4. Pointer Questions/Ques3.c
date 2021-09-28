//Ques.3 - Write a program in C to find the maximum of two numbers using pointers.

#include<stdio.h>
#include<conio.h>
int main()
{
 int x, y, *greatest, *ptr1,*ptr2;
 printf("Enter the value of x and y :");
 scanf("%d %d", &x, &y);
 
 ptr1 = &x;
 ptr2 = &y;
 if(*ptr1 > *ptr2)
     greatest = ptr1;
 else
     greatest = ptr2;
 printf("\nThe largest number is : %d",*greatest);
 printf("\n\n\n\n");
 return 0;
}
