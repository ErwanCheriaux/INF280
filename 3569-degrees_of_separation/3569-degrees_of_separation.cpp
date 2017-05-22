#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 50;
vector<int> Adj[MAXN];

int main(void)
{
   int cpt = 1;

   while(1)
   {
      int P, R;

      scanf("%d %d", &P, &R);
      if(!P and !R) return 0;

      for(int i=0; i<R; i++)
      {
         string str1, str2;
         cin >> str1 >> str2;
      }

      printf("Network %d: DISCONNECTED\n", cpt++);
   }
}
