//Ques.2- Write a Program to find the Sum and Average of elements of an Array.

#include<stdio.h>
#include<conio.h>
int main()
{
int a[100],i,num,sum=0;
float avg;
printf("Enter the size of an array \n");
scanf("%d", &num);
printf("Enter elements of array: \n");
for(i=0;i<num;i++)
{
scanf("%d",&a[i]);
sum=sum+a[i];
avg=sum/num;
}
printf("The sum of elements of array is:%d",sum);
printf("The avg of elements of array is:%f",avg);
return 0;
}
