#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100;
const int MAXLEN = 5;

vector<int> Adj[MAXN];

unsigned int Dist[MAXN];
typedef pair<unsigned int, int> WeightNode; // weight goes first
priority_queue<WeightNode, vector<WeightNode>, greater<WeightNode>> Q;

void Dijkstra(int root)
{
   fill_n(Dist, MAXN, MAXLEN);
   Dist[root] = 0;
   Q.push(make_pair(0, root));
   while(!Q.empty())
   {
      int u = Q.top().second;              // get node with least priority
      Q.pop();
      for(auto v : Adj[u])
      {
         if (Dist[v] > Dist[u] + 1)   // shorter path found?
         {
            Dist[v] = Dist[u] + 1;
            Q.push(make_pair(Dist[v], v)); // simply push, no update here
         }
      }
   }
}

int main(void)
{
   return 0;
}
