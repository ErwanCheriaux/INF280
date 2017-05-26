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

      for(int i=0; i<N; i++) Adj[i].clear();
      for(int i=0; i<M; i++)
      {
         scanf("%d %d %d", &U, &V, &P);
         Adj[U].push_back(make_pair(V,P));
      }

      //recherche du plus court chemin
      Dijkstra(S);

      if(Dist[D] != INT_MAX)
      {
         //recherche du presque plus court chemin
         shortest_path = Dist[D];
         while(Dist[D] == shortest_path)
         {
            //suppression du chemin le plus court
            int node_s, node_d = D;
            do
            {
               for(auto tmp : path) if(tmp.second == node_d) node_s = tmp.first;
               for(auto &tmp : Adj[node_s]) if(tmp.first == node_d) tmp.second = INT_MAX;
               node_d = node_s;
            } while(node_s != S);
            Dijkstra(S);
         }
      }

      //output
      if(Dist[D] == INT_MAX) printf("-1\n");
      else                   printf("%d\n", Dist[D]);
   }
}

/* 
 * Alogorithme récupéré dans les slides de cours 
 * et adapté pour les besoins du problème
 */
void Dijkstra(int root)
{
   fill_n(Dist, MAXN, MAXLEN);
   Dist[root] = 0;
   Q.push(make_pair(0, root));
   path.clear();
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
            int i=0;
            for(auto edge : path) 
            {
               if(edge.second == v) path[i] = make_pair(u,v);
               else i++;
            }
            if(i == path.size()) path.push_back(make_pair(u,v));
         }
      }
   }
}
