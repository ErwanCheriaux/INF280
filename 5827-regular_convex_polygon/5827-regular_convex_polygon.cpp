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

double x[3], y[3];

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
   return acos(produitScalaire(u,v)/(norme(u)*norme(v))) * 180.f / (2*PI);
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
      cout 
         << angle(0,1) << ", "
         << angle(1,2) << ", "
         << angle(2,0) << ", "
         << endl;
   }
}
