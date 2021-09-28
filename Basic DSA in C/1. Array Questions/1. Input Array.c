//Ques.1- Write a program to declare an array of 10 elements. Input elements and print it.

#include<stdio.h>
#include<conio.h>
int main()
{
int a[10],i;
printf("Enter the elements of array: \n");
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
printf("The elements of array are: \n");
for ( i = 0; i < 10; i++)
{
printf("%d \t",a[i]);
}
return 0;
}
