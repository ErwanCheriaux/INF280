#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

const int MAXN = 51;

set<int> Colors;
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
         if(Colors.find(L) == Colors.end()) Colors.insert(L);
         if(Colors.find(R) == Colors.end()) Colors.insert(R);
         Adj[L].push_back(R);
         Adj[R].push_back(L);
      }

      //output
      printf("Case #%d\n", t+1);

      if(Hierholzer(*Colors.begin())){
         for(int n=0; n<N; n++){
            printf("%d %d\n", Circuit[n], Circuit[n+1]);
         }
      }
      else  printf("some beads may be lost\n");

      if(t<T-1) printf("\n");

      //réinitialisation de la liste d'adjacence
      for(auto color : Colors) 
      {
         Adj[color].clear();
         Visited[color]=false;
      }
      Colors.clear();
      Circuit.clear();
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

/* 
 * Alogorithme récupéré dans les slides de cours 
 * et adapté pour les besoins du problème
 */
bool Hierholzer(int root)
{
   BFS(root);
   for(auto color : Colors) if(!Visited[color])       return false;
   for(auto color : Colors) if(Adj[color].size() & 1) return false;

   int v = root;

   stack<int> Stack;
   Stack.push(v);

   while(!Stack.empty())
   {
      if(!Adj[v].empty())
      {
         // follow edges until stuck
         Stack.push(v);
         int tmp = *Adj[v].begin();
         auto it_tmp = Adj[v].begin();
         auto it_v = Adj[tmp].begin();
         int index = 0;
         // remove edge, modifying graph
         Adj[v].erase(it_tmp);
         for(auto node : Adj[tmp])
         {
            if(node == v) it_v = Adj[tmp].begin()+index;
            index++;
         }
         Adj[tmp].erase(it_v);
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
