#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int N = 100;

vector<int> Sets;
set<pair<int,int>> A;  // Final minimum spanning tree
vector<pair<int, pair<int,int>>> Edges;


void MakeSet()
{ 
   for(int i=0; i<N; i++) Sets.push_back(i);
}

void Union(int x, int y)
{
   int ensembleX = Sets[x];
   int ensembleY = Sets[y];

   if(ensembleX == ensembleY) return;

   for(auto &tmp : Sets)
      if(tmp == ensembleY)
         tmp = ensembleX;
}

void Kruskal() 
{
   MakeSet();   // Initialize Union-Find DS
   sort(Edges.begin(), Edges.end());      // Sort edges by weight

   for(auto tmp : Edges)
   {
      auto edge = tmp.second;
      if(Sets[edge.first] != Sets[edge.second]) 
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
