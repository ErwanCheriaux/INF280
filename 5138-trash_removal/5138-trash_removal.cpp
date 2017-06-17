#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <math.h>
#include <algorithm>

using namespace std;

#define PI  3.14159265
#define EPS 1e-6

double x[100], y[100];

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
   x[0] = y[0] = 0;
   x[1] = y[1] = 2;
   for(double rot=0; rot < PI; rot += PI/4)
      cout << rot << ": " << dist(1,0,rot) << endl;
}
