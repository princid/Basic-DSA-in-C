// Ques.2- Write a program to arrange elements in ascending order using Bubble Sort.

#include <stdio.h>
int main()
{
  int array[100], N, K, D, swap; //N: Total No. of elements,  K: initial value,  D: PTR(Pass Pointer)

  printf("Enter number of elements:\n");
  scanf("%d", &N);

  printf("Enter %d integers:\n", N);

  for (K = 0; K < N; K++)
    scanf("%d", &array[K]);

  for (K = 0 ; K < N - 1; K++)
  {
    for (D = 0 ; D < N - 1; D++)
    {
      if (array[D] > array[D+1]) // For decreasing order use < //
      {
        swap       = array[D];
        array[D]   = array[D+1];
        array[D+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (K = 0; K < N; K++)
     printf("%d\n", array[K]);

  return 0;
}
