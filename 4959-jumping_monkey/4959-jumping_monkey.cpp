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

vector<int> Adj[MAXN];
int Visited[MAXN];
int fire[1<<MAXN];
int past[1<<MAXN];

int N, M;

bool circuit();
vector<int> shoot();

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

      if(circuit()) printf("Impossible\n");
      else
      {
         vector<int> shootedPath;
         shootedPath = shoot();
         printf("%d:", shootedPath.size());
         for(auto s : shootedPath) printf(" %d", s);
         printf("\n");
      }

      //réinitialisation
      for(int i=0; i<(1<<N); i++) past[i] = 0;
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

vector<int> shoot()
{
   queue<int> Q;
   Q.push((1<<N)-1); //le singe peut être sur n'importe quel arbre

   while(!Q.empty())
   {
      int singe = Q.front();
      if(!singe) //le singe ne peut plus se cacher
      {
         
      }

      //on tire sur tous les arbres
      for(int i=0; i<N; i++)
      {
         //on retire l'arbre visé
         int singeAfterShoot = singe & ~(1<<i);
         int singePostion = 0;

         //on regarde où le singe peut aller
         for(int j=0; j<N; j++)
            if((singeAfterShoot >> i) & 1)
               for(auto arbre : Adj[i])
                  singePostion = singePostion | 1<<arbre;

         //si la position du singe n'a jamais été éudié
         if(!past[singePostion])
         {

         }
      }
   }
}
