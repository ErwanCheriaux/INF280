#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
#include <list>

using namespace std;

const int MAXM    = 500-1;
const int MAXFLOW = INT_MAX;
const int MAXN    = 2*MAXM+2;

struct
{
   int start_time;
   int start_x;
   int start_y;
   int destination_time;
   int destination_x;
   int destination_y;
} Taxis[MAXM];

int dist(int x, int y);
bool BFS(int s, int t, int Predecessor[MAXN]);
int FordFulkerson(int s, int t);

int N, M, G[MAXN][MAXN];

int main(void)
{
   scanf("%d\n", &N);
   for(int n=0; n<N; n++)
   {
      scanf("%d\n", &M);

      if(M == 1)
      {
         printf("1\n");
         string str;
         getline(cin, str);
         continue;
      }

      for(int m=0; m<M; m++)
      {
         int heure, minute, st, sx, sy, dt, dx, dy;
         scanf("%d:%d %d %d %d %d\n", &heure, &minute, &sx, &sy, &dx, &dy);

         st = 60*heure+minute;
         dt = st + abs(sx - dx) + abs(sy - dy);

         Taxis[m].start_time = st;
         Taxis[m].start_x = sx;
         Taxis[m].start_y = sy;
         Taxis[m].destination_time = dt;
         Taxis[m].destination_x = dx;
         Taxis[m].destination_y = dy;
      }

      //completion du graphe bipartie G
      fill_n((int *)G, MAXN * MAXN, 0);

      for(int i=0; i<M; i++)
      {
         int edge_exist = false;
         for(int j=i+1; j<M; j++)
         {
            if(Taxis[i].destination_time + dist(i,j) < Taxis[j].start_time)
            {
               G[i][M+j] = 1;
               edge_exist = true;
            }
         }
         if(edge_exist) G[2*M][i] = 1;
         G[i+M][2*M+1] = 1;
      }

      printf("%d\n", M-FordFulkerson(2*M,2*M+1));
   }

   return 0;
}

int dist(int x, int y)
{
   return abs(Taxis[x].destination_x - Taxis[y].start_x) + \
          abs(Taxis[x].destination_y - Taxis[y].start_y);
}

bool BFS(int s, int t, int Predecessor[MAXN])
{
   // Create a visited array and mark all vertices as not visited
   bool visited[MAXN];
   memset(visited, 0, sizeof(visited));
 
   // Create a queue, enqueue source vertex and mark source vertex
   // as visited
   queue <int> q;
   q.push(s);
   visited[s] = true;
   Predecessor[s] = -1;
 
   // Standard BFS Loop
   while (!q.empty())
   {
      int u = q.front();
      q.pop();
 
      for(int v=0; v < 2*M+2; v++)
      {
         if (visited[v]==false && G[u][v] > 0)
         {
            q.push(v);
            Predecessor[v] = u;
            visited[v] = true;
         }
      }
   }
 
   // If we reached sink in BFS starting from source, then return
   // true, else false
   return (visited[t] == true);
}

int FordFulkerson(int s, int t)
{
   int Predecessor[MAXN];
   int Maxflow = 0;

   while(BFS(s, t, Predecessor)) // find residual path
   {
      // get minimal flow of residual path
      int Bottleneck = MAXFLOW;
      for(int v = t, u = Predecessor[t]; v != s; v = u, u = Predecessor[u])
         Bottleneck = min(Bottleneck, G[u][v]);
      for(int v = t, u = Predecessor[t]; v != s; v = u, u = Predecessor[u])
      {
         // decrease capacity along residual path
         G[u][v] -= Bottleneck;
         G[v][u] += Bottleneck;
      }
      Maxflow += Bottleneck;
   }
   return Maxflow;
}
