#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXQ = 8;
const int N    = 1000;

struct subnetwork
{
   int nb_cities;
   int cout;
   vector<int> cities;
} subnetworks[MAXQ];

map<int, pair<int,unsigned int>> Sets;  // map to parent & rank
vector<pair<int, pair<int,int>>> Edges;
set<pair<int,int>> A;  // Final minimum spanning tree

vector<pair<int,int>> Borduria;
int T, n, q;

void MakeSet(int x);
int  Find(int x);
void Union(int x, int y);
int  weight(int x, int y);

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

      //calcule du poid des arrètes
      for(int i=0; i<n; i++)
         for(int j=0; j<n; j++)
            if(i!=j)
               Edges.push_back(make_pair(weight(i,j), make_pair(i,j)));

   }
   return 0;
}

int weight(int x, int y)
{
   return (Borduria[x].first - Borduria[y].first)   * \
          (Borduria[x].first - Borduria[y].first)   + \
          (Borduria[x].second - Borduria[y].second) * \
          (Borduria[x].second - Borduria[y].second);
}

void MakeSet(int x)
{ 
   Sets.insert(make_pair(x, make_pair(x, 0)));
}

int Find(int x) 
{
   if(Sets[x].first == x) return x;                  // Parent == x ?
   else return Sets[x].first = Find(Sets[x].first);  // Get Parent
}

void Union(int x, int y)
{
   int parentX = Find(x), parentY = Find(y);
   int rankX = Sets[parentX].second, rankY = Sets[parentY].second;

   if(parentX == parentY) return;
   else if(rankX < rankY) Sets[parentX].first = parentY;
   else Sets[parentY].first = parentX;
   if(rankX == rankY) Sets[parentX].second++;;
}

void Kruskal() 
{
   for(int u=0; u < N; u++) MakeSet(u);   // Initialize Union-Find DS
   sort(Edges.begin(), Edges.end());      // Sort edges by weight

   for(auto tmp : Edges)
   {
      auto edge = tmp.second;
      if(Find(edge.first) != Find(edge.second)) 
      {
         Union(edge.first, edge.second);  // update Union-Find DS
         A.insert(edge);                  // include edge in MST
      }
   }
}
