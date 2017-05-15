#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int N;
   scanf("%d", &N);

   for(int t=0; t<N; t++)
   {
      //lecture input
      int m, k;
      scanf("%d %d", &m, &k);

      int p[m], somPage=0;

      for(int i=0; i<m; i++)
      {
         scanf("%d", &p[i]);
         somPage = somPage + p[i];
      }

      int    som = 0;
      int    use = 1;
      double div = (double)somPage/k;

      for(int i=0; i<m; i++)
      {
         som = som + p[i];

         if(use < k and som > div)
         {
            use++;
            som = p[i];
            printf("/ ");
         }

         if(i==m-1) printf("%d\n", p[i]);
         else       printf("%d ",  p[i]);
      }
   }
   return 0;
}
