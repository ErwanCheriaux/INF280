#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int P, C, numero, index=1, express;
   char citizen;

   while(1)
   {
      scanf("%d %d\n", &P, &C);
      if(!P and !C) return 0;

      printf("Case %d:\n", index);
      express=0;

      for(int i=0; i<C; i++)
      {
         scanf("%c\n", &citizen);
         if(citizen == 'E') 
         {
            scanf("%d\n", &numero);
            printf("%d\n", numero);
            express++;
         }
         else printf("%d\n", ((i-express)%P)+1);
      }

      index++;
   }
}
