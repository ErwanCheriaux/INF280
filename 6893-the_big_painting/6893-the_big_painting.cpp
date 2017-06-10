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

int T[MAXN+1];
char motif[MAXN][MAXN];

int hp, wp, hm, wm;

void makeTable()
{
   T[0] = -1;
   int cnd = 0;
   for (int i = 1; i <= wp; i++)
   {
      T[i] = cnd;
      while (cnd >= 0 && motif[cnd][0] != motif[i][0])
         cnd = T[cnd];
      cnd++;
   }
}

void KnuthMorrisPratt()
{
   int cnd = 0;                          // position courante dans le motif
   for (int i = 0; i <= (hm*(wm+1)); i++)
   {
      char tableau;
      scanf("%c", &tableau);
      while (cnd >= 0 && motif[cnd][0] != tableau) // tant qu'on ne lit pas le prochain char du motif
         cnd = T[cnd];                             // on recule dans le motif
      cnd++;         // maintenant que le prochain char convient, avancer
      if (cnd == hp) // on a atteint la fin de p, donc on a trouvé un match
      {
         // on recule dans p au cas où le prochain match chevauche
         printf("match at %d\n", i - hp + 1);
         cnd = T[cnd];
      }
   }
}

int main(void)
{
   while(scanf("%d", &hp)==1)
   {
      scanf(" %d %d %d\n", &wp, &hm, &wm);
      //lecture motif
      for(int i=0; i<hp; i++){
         for(int j=0; j<wp; j++)
            scanf("%c", &motif[i][j]);
         scanf("\n");
      }

      //calcule à partir du motif
      makeTable();

      //lecture tableau
      KnuthMorrisPratt();
   }
   return 0;
}
