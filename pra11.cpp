#include <stdio.h>
#include<stdlib.h>

main()
{
  int numbers[20];
  int array[20];
  int i, temp;
  int c, n;
  printf("Parth Vasoya \n 18dcs134\n");
  for (c = 0; c <= 14; c++)
  {
    n = rand() % 100 + 1;
    numbers[c] = n;
  }
  printf("\nThe random array is : ");
  for (c = 0; c <= 14; c++)
  {
    printf("\n element:%d is:- %d", c, numbers[c]);
  }
  for (i = 0; i < 18; i++)
  {
    temp = (numbers[i] % 18) + 2;
    array[temp] = numbers[i];
  }

  printf("\nThe key value pair are : ");
  for (i = 2; i < 20; i++)
  {
    printf("\n%d : \t%d", i, array[i]);
  }
}
