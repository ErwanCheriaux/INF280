#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int nbTest = 1;

   while(1)
   {
      int n, x, y, z;

      scanf("%d", &n);
      if(!n) return 0;
      
      //first corner
      scanf("%d %d %d", &x, &y, &z);

      //opposite corner
      scanf("%d %d %d", &x, &y, &z);

      //balloons
      for(int i=0; i<n; i++)
      {
         scanf("%d %d %d", &x, &y, &z);
      }

      nbTest++;
   }
}
