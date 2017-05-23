#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 100;
const int MAXN = 100;
const int MAXLEN = 5;

vector<int> Adj[MAXN];

int Dist[MAXN][MAXN];
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

int main(void)
{
   return 0;
}
