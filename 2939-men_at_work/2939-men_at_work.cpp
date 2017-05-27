#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 50*50;
const int MAXLEN = INT_MAX;

vector<pair<int,int>> Adj[MAXN];

unsigned int Dist[MAXN];
typedef pair<unsigned int, int> WeightNode; // weight goes first
priority_queue<WeightNode, vector<WeightNode>, greater<WeightNode>> Q;

void Dijkstra(int root);

int main(void)
{
   int N;
   while(scanf("%d\n", &N)==1)
   {
      char maze[N][N];
      char work[N][N];

      //input
      for(int i=0; i<N; i++) {
         for(int j=0; j<N; j++) {
            if(j==N-1) scanf("%c\n", &maze[i][j]);
            else       scanf("%c",   &maze[i][j]);
         }
      }

      for(int i=0; i<N; i++) {
         for(int j=0; j<N; j++) {
            if(j==N-1) scanf("%c\n", &work[i][j]);
            else       scanf("%c",   &work[i][j]);
         }
      }

      //génération liste Adj
      for(int i=0; i<N; i++) {
         for(int j=0; j<N; j++) {
            if(maze[i][j] == '.') {
               if(i>0   and maze[i-1][j] == '.') Adj[10*i+j].push_back(make_pair(10*(i-1)+j,work[i-1][j]-48));
               if(i<N-1 and maze[i+1][j] == '.') Adj[10*i+j].push_back(make_pair(10*(i+1)+j,work[i+1][j]-48));
               if(j>0   and maze[i][j-1] == '.') Adj[10*i+j].push_back(make_pair(10*i+j-1  ,work[i][j-1]-48));
               if(j<N-1 and maze[i][j+1] == '.') Adj[10*i+j].push_back(make_pair(10*i+j+1  ,work[i][j+1]-48));
            }
         }
      }

      Dijkstra(0);

      printf("%d\n", Dist[N*N-1]);
   }
   return 0;
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
         }
      }
   }
}
