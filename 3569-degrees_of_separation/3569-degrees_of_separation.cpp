#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN   = 50;
const int MAXLEN = 50;

vector<int> Adj[MAXN];
map<string,int> node;

int N;
int Dist[MAXN][MAXN];
void FloydWarshall();

int main(void)
{
   int cpt = 1;

   while(1)
   {
      int P, R, index=0, degree_of_separation=0;

      scanf("%d %d", &P, &R);
      if(!P and !R) return 0;

      for(int i=0; i<MAXN; i++) Adj[i].clear();

      for(int i=0; i<R; i++)
      {
         string str1, str2;
         cin >> str1 >> str2;
         if(node.find(str1) == node.end()) node[str1] = index++;
         if(node.find(str2) == node.end()) node[str2] = index++;

         Adj[node[str1]].push_back(node[str2]);
         Adj[node[str2]].push_back(node[str1]);
      }

      N = node.size();
      FloydWarshall();
      for(int i=0; i<N; i++)
         for(int j=0; j<N; j++)
            degree_of_separation = max(degree_of_separation,Dist[i][j]);

      if(degree_of_separation == 50) printf("Network %d: DISCONNECTED\n", cpt++);
      else                           printf("Network %d: %d\n", cpt++, degree_of_separation);
   }
}

/* Alogorithme récupéré dans les slides de cours */
void FloydWarshall()
{
   fill_n((int *)Dist, MAXN * MAXN, MAXLEN);

   for(int u=0; u < N; u++)
   {
      Dist[u][u] = 0;
      for(auto v : Adj[u])
         Dist[u][v] = 1;
   }

   for (int k=0; k < N; k++) // check sub-path combinations
      for(int i=0; i < N; i++)
         for(int j=0; j < N; j++) // concatenate paths
            Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
}
