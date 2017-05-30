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
#include <stack>

using namespace std;

const unsigned int MAXN = 1000;

set<int> colors;
vector<int> Circuit;
vector<int> Adj[MAXN];

queue<int> Q;
bool Visited[MAXN] = {};

int T, N, L, R;

void BFS(int root);
bool Hierholzer(int root);

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

      if(Hierholzer(1))
      {
         for(auto tmp : Circuit)
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

bool Hierholzer(int root)
{
   BFS(root);
   for(auto color : colors) if(!Visited[color])       return false;
   for(auto color : colors) if(Adj[color].size() & 1) return false;

   int v = root; // find node with odd degree, else start with node 0

   stack<int> Stack;
   Stack.push(v);

   while(!Stack.empty())
   {
      if(!Adj[v].empty())
      {
         // follow edges until stuck
         Stack.push(v);
         int tmp = *Adj[v].begin();
         Adj[v].erase(tmp);
         // remove edge, modifying graph
         Adj[tmp].erase(v);
         v = tmp;
      }
      else
      {
         // got stuck: stack contains a circuit
         Circuit.push_back(v);
         // append node at the end of circuit
         v = Stack.top();
         // backtrack using stack, find larger circuit
         Stack.pop();
      }
   }
   return true;
}
