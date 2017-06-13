#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <math.h>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
#include <list>

using namespace std;

#define PI 3.14159265

double x[4], y[4];

inline double produitScalaire(int u, int v)
{
   return x[u]*x[v] + y[u]*y[v];
}

inline double norme(int u)
{
   return sqrt(x[u]*x[u] + y[u]*y[u]);
}

double angle(int u, int v)
{
   return acos(produitScalaire(u,v)/(norme(u)*norme(v)));
}

void barycentre()
{
   double angles[3];
   double lambda = 0;
   x[3] = 0;
   y[3] = 0;
   for(int i=0; i<3; i++) angles[i] = angle((i+1)%3,(i+2)%3);
   for(int i=0; i<3; i++) lambda += 2*tan(angles[i]);
   for(int i=0; i<3; i++)
   {
      x[3] += (tan(angles[(i+1)%3]) + tan(angles[(i+2)%3])) * x[i] / lambda;
      y[3] += (tan(angles[(i+1)%3]) + tan(angles[(i+2)%3])) * y[i] / lambda;
   }

   cout
      << angles[0] << ", "
      << angles[1] << ", "
      << angles[2] << ", "
      << tan(angles[0]) << ", "
      << tan(angles[1]) << ", "
      << tan(angles[2]) << ", "
      << lambda << endl;
}

int main(void)
{
   while(1)
   {
      string str;
      cin >> str >> y[0];
      if(str == "END") return 0;

      //input
      x[0] = atof(str.c_str());
      for(int i=1; i<3; i++) cin >> x[i] >> y[i];

      //recherche du centre du cercle circonscrit
      barycentre();

      cout << "{" << x[3] << "," << y[3] << "}" << endl;
   }
}
