#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

void no_change(int x, int *v, int k);
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

      no_change(x, v, k);
   }
   return 0;
}

void no_change(int x, int *v, int k)
{
   //init coef
   int c[k], y, index=0;
   for(int i=0; i<k; i++) c[i] = 0;

   while(1)
   {
      if(index > 0 and c[index-1] <= c[index]) 
      {   
         if(index == k-1)
         {
            printf("NO\n\n");
            return;
         }
         index++;
      }
      else c[index]++;

      y = argent(v, c, k);
      if(x == y)
      {
         printf("YES\n\n");
         return;
      }
      else if (x < y)
      {
         if(index == k-1)
         {
            printf("NO\n\n");
            return;
         }
         c[index]--;
         index++;
      }
   }    
}

int argent(int *v, int *c, int k)
{
   int s=0;
   for(int i=0; i<k; i++) s += v[i]*c[i];
   return s;
}