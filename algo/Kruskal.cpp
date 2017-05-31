#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <map>
#include <set>

using namespace std;

int N = 100;

map<int, pair<int,unsigned int>> Sets;  // map to parent & rank
vector<pair<int, pair<int,int>>> Edges;
set<pair<int,int>> A;  // Final minimum spanning tree


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

int main(void)
{
   return 0;
}
