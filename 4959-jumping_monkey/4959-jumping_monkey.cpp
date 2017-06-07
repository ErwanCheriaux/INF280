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

const int MAXN = 21;

int Visited[MAXN] = {};
vector<int> Adj[MAXN];

int N, M;

bool circuit();

int main(void)
{
   while(1)
   {
      scanf("%d %d\n", &N, &M);
      if(!N and !M) return 0;

      //génération matrice adjacence
      for(int i=0; i<M; i++)
      {
         int x, y;
         scanf("%d %d\n", &x, &y);
         Adj[x].push_back(y);
         Adj[y].push_back(x);
      }

      if(circuit()) printf("OUI\n");
      else          printf("NON\n");

      //réinitialisation
      for(int i=0; i<N; i++)
      {
         Adj[i].clear();
         Visited[i] = 0;
      }
   }
}

/* Valeur de retour
 * true  : il y a un circuit dans le graphe
 * false : il n'y a pas de circuit dans le graphe
 */
bool circuit()
{
   /* 0 : non visité
    * 1 : sur la pile
    * 2 : visité et donc plus sur la pile
    */
   queue<int> Q;
   Q.push(0);
   while(!Q.empty())
   {
      int u = Q.front();
      Q.pop();
      Visited[u] = 2;
      for(auto v : Adj[u])
      {
         if(Visited[v] == 1) return true;
         else if(!Visited[v])
         {
            Visited[v] = 1;
            Q.push(v);
         }
      }
   }
   return false;
}
