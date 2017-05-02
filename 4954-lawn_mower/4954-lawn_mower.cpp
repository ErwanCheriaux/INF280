#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int nx, ny;
   double w;
   bool possible_x, possible_y;

   while(1)
   {
      scanf("%d", &nx);
      scanf("%d", &ny);
      scanf("%lf", &w);
      if(nx == 0 and ny == 0 and w == 0.0) return 0;

      possible_x = true;
      possible_y = true;

      double tx[nx];
      double ty[ny];

      for(int i=0; i<nx; i++) scanf("%lf", &tx[i]);
      for(int i=0; i<ny; i++) scanf("%lf", &ty[i]);

      if(75/w <= nx)
      {
         sort(tx, tx+nx);

         if(tx[0] > w/2 or 75-tx[nx-1] > w/2) possible_x = false;
         else
         {
            for(int i=0; i<nx-1; i++)
            {
               if(tx[i+1]-tx[i] > w)
               {
                  possible_x = false;
                  break;
               }
            }
         }
      } else possible_x = false;

      if(100/w <= ny)
      {
         sort(ty, ty+ny);
         
         if(ty[0] > w/2 or 100-ty[ny-1] > w/2) possible_y = false;
         else
         {
             for(int i=0; i<ny-1; i++)
             {
                if(ty[i+1]-ty[i] > w)
                {
                   possible_y = false;
                   break;
                }
             }
         }
      } else possible_y = false;

      if(possible_x and possible_y) printf("YES\n");
      else                          printf("NO\n");
   }
}
