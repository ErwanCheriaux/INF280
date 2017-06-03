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

const int MAXM = 500-1;

struct
{
   int start_time;
   int start_x;
   int start_y;
   int destination_time;
   int destination_x;
   int destination_y;
} Taxis[MAXM];

int N, M;

int main(void)
{
   scanf("%d\n", &N);
   for(int n=0; n<N; n++)
   {
      scanf("%d\n", &M);
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
   }

   return 0;
}
