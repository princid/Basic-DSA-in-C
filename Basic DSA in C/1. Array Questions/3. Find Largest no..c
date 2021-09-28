//Ques.3- Write a Program to find the largest number of elements inputted in an array.

#include<stdio.h>
#include<conio.h>
int main()
{
int a[100],i,num;
printf("Enter the size of an array \n");
scanf("%d", &num);
for(i=0;i<num;i++)
{
printf("Enter number %d:\n",i+1);
scanf("%d",&a[i]);
}
for ( i = 0; i < num; i++)
{
    if (a[0]<a[i])
    {
     a[0]=a[i];  
    }
}
printf("The largest number is:%d",a[0]);
return 0;
}
