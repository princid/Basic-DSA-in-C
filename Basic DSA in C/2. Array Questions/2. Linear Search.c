//Ques.3- Write a program to search any given element using Linear search.
#include <stdio.h>
int main()
{
  int a[100], search,i, n;

  printf("Enter number of elements in array:\n");
  scanf("%d", &n);

  printf("Enter the elements:\n");

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("Enter a number to search:\n");
  scanf("%d", &search);

  for (i = 0; i < n; i++)
  {
    if (a[i] == search)   
    {
      printf("%d is present at location %d.\n", search,i+1);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array.\n", search);

  return 0;
}
