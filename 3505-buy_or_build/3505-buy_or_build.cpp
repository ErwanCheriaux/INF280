#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

const int MAXQ = 8;

struct subnetwork
{
   int nb_cities;
   int cout;
   vector<int> cities;
} subnetworks[MAXQ];

vector<pair<int,int>> Borduria;
int T, n, q;

int main(void)
{
   scanf("%d\n\n", &T);
   for(int t=0; t<T; t++)
   {
      scanf("%d %d\n", &n, &q);
      //subnetworks
      for(int i=0; i<q; i++)
      {
         int nb, c, city;
         scanf("%d %d ", &nb, &c);
         subnetworks[i].nb_cities = nb;
         subnetworks[i].cout = c;
         for(int j=0; j<nb; j++) 
         {
            scanf("%d", &city);
            subnetworks[i].cities.push_back(city);
         }
      }
      //cities
      for(int i=0; i<n; i++)
      {
         int x, y;
         scanf("%d %d\n", &x, &y);
         Borduria.push_back(make_pair(x, y));
      }
   }
   return 0;
}
