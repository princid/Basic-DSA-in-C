//Ques.2 - Write a program to add two numbers using Call by Reference.

#include <stdio.h>
#include <conio.h>

long add(long *, long *);

int main()
{
    long first, second, sum;
    
    printf("Input two integers to add :");
    scanf("%ld %ld", &first, &second);
    
    sum = add(&first, &second);
    printf("\n");
    printf("(%ld) + (%ld) = (%ld)\n", first, second, sum);
    
    return 0;
}

long add(long *x, long *y)
 {
    long sum;
    
    sum = *x + *y;
    
    return sum;
 }
