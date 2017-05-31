#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100;

queue<int> Q;
bool Visited[MAXN] = {};
vector<int> Adj[MAXN];

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

int main(void)
{
   return 0;
}
