//Ques.4- Write a program to search any given element using Binary search.
#include<stdio.h>
int main()
{
  int i, first, last, middle, n, search, a[100];

  printf("Enter number of elements:\n");
  scanf("%d", &n);

  printf("Enter the elements:\n");

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("Enter value to find:\n");
  scanf("%d", &search);

  first = 0;
  last = n - 1;
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

  return 0;
}
