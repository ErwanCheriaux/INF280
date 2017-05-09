#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int n, C, N;

   scanf("%d", &n);

   for(int t=0; t<n; t++)
   {
      scanf("%d", &C);
      scanf("%d", &N);
    
      int x[N], y[N], c[N];
  
      for(int i=0; i<N; i++) scanf("%d %d %d", &x[i], &y[i], &c[i]);

      //debug
      printf("%d\n\n%d\n%d\n", n, C, N);
      for(int i=0; i<N; i++) printf("%d %d %d\n", x[i], y[i], c[i]);
   }

   return 0;
}
