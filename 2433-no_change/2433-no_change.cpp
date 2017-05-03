#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int x, v[5], k;

   while(scanf("%d\n\n", &x)==1)
   {
      //lecture input
      scanf("%d %d", &x, &k);
      for(int i=0; i<k; i++) scanf("%d", &v[i]);

      printf("%d %d ", x, k);
      for(int i=0; i<k; i++) printf("%d ", v[i]);
      printf("\n");
   }

   return 0;
}
