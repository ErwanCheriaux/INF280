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

unsigned int time_cpt;
vector<int> Adj[MAXN];
queue<int> Q;
bool Visited[MAXN] = {};

void BFS(int root);

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
               if(i>0   and maze[i-1][j] == '.') Adj[N*i+j].push_back(N*(i-1)+j);
               if(i<N-1 and maze[i+1][j] == '.') Adj[N*i+j].push_back(N*(i+1)+j);
               if(j>0   and maze[i][j-1] == '.') Adj[N*i+j].push_back(N*i+j-1  );
               if(j<N-1 and maze[i][j+1] == '.') Adj[N*i+j].push_back(N*i+j+1  );
            }
         }
      }

      time_cpt=0;
      BFS(0);

      printf("%d\n", time_cpt);

      //initialisation Adj
      for(int i=0; i<N*N; i++) {Adj[i].clear(); Visited[i].clear();}
   }
   return 0;
}

/* 
 * Alogorithme récupéré dans les slides de cours 
 * et adapté pour les besoins du problème
 */
void BFS(int root)
{
   Q.push(root);
   while(!Q.empty())
   {
      int u = Q.front();
      Q.pop();
      if(Visited[u]) continue;
      Visited[u] = true;
      for(auto v : Adj[u])
      {
         Q.push(v);
      }
   }
}
