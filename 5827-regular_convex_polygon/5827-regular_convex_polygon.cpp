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

#define PI  3.14159265
#define EPS 1e-5

double x[4], y[4];

inline double produitScalaire(int u, int v, int origin)
{
   return (x[u]-x[origin])*(x[v]-x[origin]) + \
          (y[u]-y[origin])*(y[v]-y[origin]);
}

inline double norme(int u, int origin)
{
   return sqrt((x[u]-x[origin])*(x[u]-x[origin]) + \
               (y[u]-y[origin])*(y[u]-y[origin]));
}

double angle(int u, int v, int origin)
{
   return acos(produitScalaire(u,v,origin)/(norme(u,origin)*norme(v,origin)));
}

void barycentre()
{
   double angles[3];
   double lambda = 0;
   x[3] = 0;
   y[3] = 0;
   for(int i=0; i<3; i++) 
   {
      int u = (i+1)%3;
      int v = (i+2)%3;
      angles[i] = angle(u, v, i);
      lambda += 2*tan(angles[i]);
   }
   for(int i=0; i<3; i++)
   {
      x[3] += (tan(angles[(i+1)%3]) + tan(angles[(i+2)%3])) * x[i] / lambda;
      y[3] += (tan(angles[(i+1)%3]) + tan(angles[(i+2)%3])) * y[i] / lambda;
   }

   if(abs(x[3]) <EPS) x[3]=0;
   if(abs(y[3]) <EPS) y[3]=0;
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

      //recherche des 3 angles entre le triangle et le centre du cercle
      double angles[3];
      for(int i=0; i<3; i++) angles[i] = angle(i,(i+1)%3,3);

      for(int i=0; i<3; i++) cout << angles[i]*180/PI << endl;

      cout << "{" << x[3] << "," << y[3] << "}" << "\n" << endl;
   }
}
