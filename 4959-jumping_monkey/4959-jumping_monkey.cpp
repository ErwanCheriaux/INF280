#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 21;

vector<int> Adj[MAXN];
long past[1<<MAXN];
int  fire[1<<MAXN];

int N, M;

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

      vector<int> shootedPath;
      shootedPath = shoot();

      if(shootedPath.empty()) printf("Impossible\n");
      else
      {
         cout << shootedPath.size() << ":";
         for(auto s : shootedPath) printf(" %d", s);
         printf("\n");
      }

      //réinitialisation
      for(int i=0; i<(1<<N); i++) past[i] = 0;
      for(int i=0; i<N; i++) Adj[i].clear();
   }
}

vector<int> shoot()
{
   vector<int> path;
   queue<long> Q;
   Q.push((1<<N)-1); //le singe peut être sur n'importe quel arbre

   while(!Q.empty())
   {
      long singe = Q.front();
      if(!singe) //le singe ne peut plus se cacher
      {
         while(singe != (1<<N)-1)
         {
            path.push_back(fire[singe]);
            singe = past[singe];
         }
         return path;
      }

      //on tire sur tous les arbres
      for(int i=0; i<N; i++)
      {
         //on retire l'arbre visé
         long singeAfterShoot = singe & ~(1<<i);
         long singePostion = 0;

         //on regarde où le singe peut aller
         for(int j=0; j<N; j++)
            if((singeAfterShoot >> j) & 1)
               for(auto arbre : Adj[j])
                  singePostion = singePostion | 1<<arbre;

         //si la position du singe n'a jamais été éudié
         if(!past[singePostion])
         {
            Q.push(singePostion);
            past[singePostion] = singe; //permet d'avoir un historique
            fire[singePostion] = i;     //permet l'arbre shooté
         }
      }
      Q.pop();
   }
   return path;
}
