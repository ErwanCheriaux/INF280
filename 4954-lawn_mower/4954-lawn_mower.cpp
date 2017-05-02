#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

bool mower(double *t, int n, int max, double w);

int main(void)
{
   int nx, ny;
   double w;
   bool side_x, side_y;

   while(1)
   {
      scanf("%d", &nx);
      scanf("%d", &ny);
      scanf("%lf", &w);
      if(nx == 0 and ny == 0 and w == 0.0) return 0;

      double tx[nx];
      double ty[ny];

      for(int i=0; i<nx; i++) scanf("%lf", &tx[i]);
      for(int i=0; i<ny; i++) scanf("%lf", &ty[i]);

      side_x = mower(tx, nx, 75,  w);
      side_y = mower(ty, ny, 100, w);

      if(side_x and side_y) printf("YES\n");
      else                  printf("NO\n");
   }
}

bool mower(double *t, int n, int max, double w)
{
   if(max/w <= n)
   {
      sort(t, t+n);

      if(t[0] > w/2 or max-t[n-1] > w/2) return false;
      
      for(int i=0; i<n-1; i++)
      {
         if(t[i+1]-t[i] > w) return false;
      }
   } else return false;
   return true;
}
