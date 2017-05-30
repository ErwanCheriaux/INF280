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
#include <set>

using namespace std;

const unsigned int MAXN = 1000;

set<int> colors;
vector<int> path;
vector<int> Adj[MAXN];

queue<int> Q;
bool Visited[MAXN] = {};

int T, N, L, R;

void BFS(int root);
bool eulerien();

int main(void)
{
   scanf("%d\n", &T);
   for(int t=0; t<T; t++)
   {
      scanf("%d\n", &N);
      for(int n=0; n<N; n++)
      {
         scanf("%d %d\n", &L, &R);
         if(colors.find(L) == colors.end()) colors.insert(L);
         if(colors.find(R) == colors.end()) colors.insert(R);
         Adj[L].push_back(R);
         Adj[R].push_back(L);
      }

      //output
      printf("Case #%d\n", t+1);

      if(eulerien()) 
      {
         for(auto tmp : path)
         {
            printf("\n");
         }
      }
      else printf("some beads may be lost\n");

      if(t<T-1) printf("\n");

      //réinitialisation de la liste d'adjacence
      for(auto color : colors) 
      {
         Adj[color].clear();
         Visited[color]=false;
      }
      colors.clear();
   }
   return 0;
}

bool eulerien()
{
   BFS(1);
   for(auto color : colors) if(!Visited[color])       return false;
   for(auto color : colors) if(Adj[color].size() & 1) return false;
   return true;
}

void BFS(int root)
{
   Q.push(root);
   while(!Q.empty())
   {
      int u = Q.front();
      Q.pop();
      if(Visited[u]) continue;
      Visited[u] = true;
      for(auto v : Adj[u]) Q.push(v);
   }
}
