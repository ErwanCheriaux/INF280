#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

const unsigned int MAXN = 500;
const unsigned int MAXLEN = INT_MAX;
vector<pair<int,int>> Adj[MAXN];
vector<pair<int,int>> path;

unsigned int Dist[MAXN];
typedef pair<unsigned int, int> WeightNode; // weight goes first
priority_queue<WeightNode, vector<WeightNode>, greater<WeightNode>> Q;

void Dijkstra(int root);

int main(void)
{
   while(1)
   {
      int N, M, S, D, U, V, P, shortest_path;
      scanf("%d %d", &N, &M);

      if(!N and !M) return 0;

      scanf("%d %d", &S, &D);

      for(int i=0; i<M; i++)
      {
         scanf("%d %d %d", &U, &V, &P);
         Adj[U].push_back(make_pair(V,P));
      }

      //recherche du plus court chemin
      Dijkstra(S);
      shortest_path = Dist[D];

      //recherche du presque plus court chemin
      //while(Dist[D] == shortest_path) Dijkstra(S);

      //output
      if(Dist[D] == INT_MAX) printf("-1\n");
      else                   printf("%d\n", Dist[D]);
   }
}

void Dijkstra(int root)
{
   fill_n(Dist, MAXN, MAXLEN);
   Dist[root] = 0;
   Q.push(make_pair(0, root));
   while(!Q.empty())
   {
      int u = Q.top().second;              // get node with least priority
      Q.pop();
      for(auto tmp : Adj[u])
      {
         int v = tmp.first;
         unsigned int weight = tmp.second;
         if (Dist[v] > Dist[u] + weight)
         {
            Dist[v] = Dist[u] + weight;
            Q.push(make_pair(Dist[v], v)); // simply push, no update here
            for(auto edge : path) if(edge.second == v) path.remove(edge); 
            path.push_back(make_pair(u, v));
         }
      }
      int a =1;
   }
}
