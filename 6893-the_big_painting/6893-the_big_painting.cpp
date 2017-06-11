#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2000;

int T[MAXN+1];
char motif[MAXN][MAXN];
vector<pair<int,int>> memorie;

int hp, wp, hm, wm, match;

void makeTable()
{
   T[0] = -1;
   int cnd = 0;
   for(int i = 1; i <= wp; i++)
   {
      T[i] = cnd;
      while(cnd >= 0 && motif[cnd][0] != motif[i][0])
         cnd = T[cnd];
      cnd++;
   }
}

void KnuthMorrisPratt()
{
   int cnd = 0;                          // position courante dans le motif
   for(int i = 0; i <= (hm*(wm+1)); i++)
   {
      char tableau;
      scanf("%c", &tableau);
      while(cnd >= 0 && motif[cnd][0] != tableau) // tant qu'on ne lit pas le prochain char du motif
         cnd = T[cnd];                            // on recule dans le motif
      cnd++;        // maintenant que le prochain char convient, avancer
      if(cnd == hp) // on a atteint la fin de p, donc on a trouvé un match
      {
         // on recule dans p au cas où le prochain match chevauche
         cnd = T[cnd];
         memorie.push_back(make_pair(i-hp+1, 1));
      }

      int cptErase = 0;
      for(auto &tmp : memorie)
      {
         int position = i - (wm+1)*tmp.second - tmp.first;
         if(position >= 0 and position < wp)
         {
            if(motif[tmp.second][position] == tableau)
            {
               if(position == wp-1 and tmp.second == hp-1) 
               {
                  match++; 
                  memorie.erase(memorie.begin()+cptErase);
               }
               else if(position == wp-1) tmp.second++;
            }
            else memorie.erase(memorie.begin()+cptErase);
         }
         cptErase++;
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
      printf("%d\n", match);

      //réinitialisation
      match = 0;
   }
   return 0;
}
