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
vector<int> path;

void explore(int root);

int T, N, L, R, node_cpt;
bool oppo;

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
      oppo = Adj[0][0].second;
      node_cpt=0;
      explore(0);

      //output
      printf("Case #%d\n", t+1);

      if(node_cpt != N) printf("some beads may be lost\n");
      else
      {
         oppo = true;
         for(auto tmp : path)
         {
            if(oppo) printf("%d %d\n", necklace[tmp].first, necklace[tmp].second);
            else     printf("%d %d\n", necklace[tmp].second, necklace[tmp].first);
            oppo = !oppo;
         }
      }

      if(t<T-1) printf("\n");

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
   if(node_cpt++ == N) return;
   visited[root] = true;
   path.push_back(root);
   oppo = !oppo;

   for(auto tmp : Adj[root])
   {
      if(!visited[root] and tmp.second == oppo)
      {
         explore(tmp.first);
         if(node_cpt == N) return;
      }
   }

   path.pop();
   visited[root] = false;
   node_cpt--;
}
