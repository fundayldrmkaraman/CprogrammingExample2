#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
          int array[20], i;
          for(i = 0; i < 20; i++)
          {
                  array[i] = (rand() % 100)+1;
                  printf("%4d\n", array[i]);
       }
    return 0;
}
