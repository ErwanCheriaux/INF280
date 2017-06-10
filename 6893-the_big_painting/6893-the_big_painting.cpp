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

const int MAXN = 2000;

char p[MAXN], s[MAXN]; int T[MAXN+1];
char motif[MAXN][MAXN], tab[MAXN][MAXN];
int np = strlen(p), ns = strlen(s);

int hp, wp, hm, wm;

int main(void)
{
   while(scanf("%d %d %d %d\n", &hp, &wp, &hm, &wm) == 1)
   {
      for(int i=0; i<hp; i++){
         for(int j=0; j<wp; j++)
            scanf("%c", &motif[i][j]);
         scanf("\n");
      }

      for(int i=0; i<hm; i++){
         for(int j=0; j<wm; j++)
            scanf("%c", &tab[i][j]);
         scanf("\n");
      }
            
   }
   return 0;
}
