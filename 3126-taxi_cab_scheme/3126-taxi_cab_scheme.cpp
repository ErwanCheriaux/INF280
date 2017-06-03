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

const int MAXM    = 500-1;
const int MAXFLOW = INT_MAX;
const int MAXN    = 2*MAXM+2;

struct
{
   int start_time;
   int start_x;
   int start_y;
   int destination_time;
   int destination_x;
   int destination_y;
} Taxis[MAXM];

int dist(int x, int y);

int N, M;
int G[MAXN][MAXN];

int main(void)
{
   scanf("%d\n", &N);
   for(int n=0; n<N; n++)
   {
      scanf("%d\n", &M);

      if(M == 1)
      {
         printf("1\n");
         string str;
         getline(cin, str);
         continue;
      }

      for(int m=0; m<M; m++)
      {
         int heure, minute, st, sx, sy, dt, dx, dy;
         scanf("%d:%d %d %d %d %d\n", &heure, &minute, &sx, &sy, &dx, &dy);

         st = 60*heure+minute;
         dt = st + abs(sx - dx) + abs(sy - dy);

         Taxis[m].start_time = st;
         Taxis[m].start_x = sx;
         Taxis[m].start_y = sy;
         Taxis[m].destination_time = dt;
         Taxis[m].destination_x = dx;
         Taxis[m].destination_y = dy;
      }

      //completion du graphe bipartie G
      fill_n((int *)G, MAXN * MAXN, 0);

      for(int i=0; i<M; i++)
      {
         G[2*M][i]     = 1;
         G[i+M][2*M+1] = 1;
         for(int j=i+1; j<M; j++)
            if(Taxis[i].destination_time + dist(i,j) < Taxis[j].start_time)
               G[i][M+j] = 1;
      }

      for(int i=0; i<10; i++){
         for(int j=0; j<10; j++)
            printf("%d ,", G[i][j]);
         printf("\n");
      }
      printf("\n");

   }

   return 0;
}

int dist(int x, int y)
{
   return abs(Taxis[x].destination_x - Taxis[y].start_x) + \
          abs(Taxis[x].destination_y - Taxis[y].start_y);
}
