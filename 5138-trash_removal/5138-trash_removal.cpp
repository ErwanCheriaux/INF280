#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;

#define PI   3.14159265
#define STEP 0.01
#define MAX  10000

int x[100], y[100];

double norme(int u, int origin)
{
   return sqrt((x[u]-x[origin])*(x[u]-x[origin]) + \
               (y[u]-y[origin])*(y[u]-y[origin]));
}

double angle(int u, int origin)
{
   return atan2(y[u]-y[origin], x[u]-x[origin]);
}

double dist(int u, int origin, double rotation)
{
   return norme(u,origin) * sin(angle(u,origin) - rotation);
}

int main(void)
{
   int cpt = 1;
   while(1)
   {
      int n;
      scanf("%d\n", &n);

      if(!n) return 0;

      for(int i=0; i<n; i++) scanf("%d %d\n", &x[i], &y[i]);

      double best = MAX;
      for(double rot=0; rot <= PI; rot += STEP)
      {
         double maxDistance = 0;
         double minDistance = 0;
         for(int i=1; i<n; i++)
         {
            double distance = dist(i,0,rot);
            maxDistance = max(maxDistance, distance);
            minDistance = min(minDistance, distance);
         }
         best = min(best, maxDistance-minDistance);
      }

      cout << "Case " << cpt++ << ": " << round(best*100)/100 << endl;
   }
}
