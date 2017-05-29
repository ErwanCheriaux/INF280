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

const unsigned int MAXN = 1000;

bool visited[MAXN];
pair<int,int> necklace[MAXN];
vector<pair<int,bool>> Adj[MAXN];

void explore(int root);

int T, N, L, R, node_cpt;

int main(void)
{
   scanf("%d\n", &T);
   for(int t=0; t<T; t++)
   {
      scanf("%d\n", &N);
      for(int n=0; n<N; n++)
      {
         scanf("%d %d\n", &L, &R);
         necklace[n] = make_pair(L,R);
         for(int i=0; i<n; i++)
         {
            if(necklace[i].first  == necklace[n].first)
            {
               Adj[i].push_back(make_pair(n,false));
               Adj[n].push_back(make_pair(i,false));
            }
            if(necklace[i].second == necklace[n].second) 
            {
               Adj[i].push_back(make_pair(n,true));
               Adj[n].push_back(make_pair(i,true));
            }
         }
      }

      //recherche d'un chemin passant par tous les noeuds
      //sans se séparer en plusieurs chemins
      node_cpt=0;
      explore(0);

      //output

      //réinitialisation de la liste d'adjacence
      //et de visite des noeuds
      for(int n=0; n<N; n++)
      {
         Adj[n].clear();
         visited[n] = false;
      }
   }
   return 0;
}

void explore(int root)
{
   visited[root] = true;
   if(node_cpt++ == N) return;

   for(auto tmp : Adj[root])
   {
      if(!visited[root])
      {
         explore(tmp);
      }
   }

   visited[root] = false;
   node_cpt--;
}
