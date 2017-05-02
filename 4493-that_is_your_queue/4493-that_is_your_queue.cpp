#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int P, C, numero;
   char citizen;

   while(1)
   {
      scanf("%d %d\n", &P, &C);
      if(!P and !C) return 0;
      
      printf("%d %d\n", P, C);

      for(int i=0; i<C; i++)
      {
         scanf("%c\n", &citizen);
         if(citizen == 'E') scanf("%d\n", &numero);

         if(citizen == 'E') printf("%c %d\n", citizen, numero);
         else               printf("%c\n", citizen);
      }
   }
}
