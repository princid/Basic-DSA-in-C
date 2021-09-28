//Ques.4 - Write a program in C to store n elements in an array and print the elements using pointers.

#include <stdio.h>
#define MAX_SIZE 100 
int main()
{
    int arr[MAX_SIZE];
    int N, i;
    int * ptr = arr; 

    printf("Enter size of array: ");
    scanf("%d", &N);
    printf("\n");
    for (i = 0; i < N; i++)
    {
    	printf("Enter Element at %d position :",i);
        scanf("\t%d", ptr);
        printf("\n");
        ptr++;   
    }
    ptr = arr;
    printf("Array elements: ");
    for (i = 0; i < N; i++)
    {
        printf("%d  ", *ptr);
        ptr++;
    }
    printf("\n\n\n\n");
    return 0;
}
