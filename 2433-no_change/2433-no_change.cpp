#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

bool no_change(int x, int *v, int k);
int  argent(int *v, int *c, int k);

int main(void)
{
   int n, x, v[5], k;

   scanf("%d", &n);
   for(int t=0; t<n; t++)
   {
      //lecture input
      scanf("%d %d", &x, &k);
      for(int i=0; i<k; i++) scanf("%d", &v[i]);

      if(no_change(x, v, k)) printf("YES");
      else                   printf("NO");

      if(t != n-1) printf("\n\n");
   }
   return 0;
}

bool no_change(int x, int *v, int k)
{
   int c[5];
   int max = x/v[0];

   for(int i0=0; i0<=max; i0++)
   {
      c[0]=i0;
      for(int i1=0; i1<=i0; i1++)
      {
         c[1]=i1;
         for(int i2=0; i2<=i1; i2++)
         {
            c[2]=i2;
            for(int i3=0; i3<=i2; i3++)
            {
               c[3]=i3;
               for(int i4=0; i4<=i3; i4++)
               {
                  c[4]=i4;
                  if(x == argent(v, c, k)) return true;
               }
            }
         }
      }
   }

   return false;  
}

int argent(int *v, int *c, int k)
{
   int s=0;
   for(int i=0; i<k; i++) s += v[i]*c[i];
   return s;
}
