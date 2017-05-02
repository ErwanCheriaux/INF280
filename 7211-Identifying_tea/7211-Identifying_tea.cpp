#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>

using namespace std;

int main(void)
{
   int T, c, cpt;
   while(scanf("%d", &T)==1)
   {
      cpt = 0;
      for(int i=0; i<5; i++)
      {
         scanf("%d", &c);
         if(c==T) cpt++;
      }
      printf("%d\n", cpt);
   }
   return 0;
}
