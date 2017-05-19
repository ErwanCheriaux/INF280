#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>

using namespace std;

int m, k, p[500], slash[500], best[500], contrainte;

void copying_books(int scriber);
int calculeContrainte();

int main(void)
{
   int N;
   scanf("%d", &N);

   for(int t=0; t<N; t++)
   {
      //lecture input
      scanf("%d %d", &m, &k);
      for(int i=0; i<m; i++) scanf("%d", &p[i]);

      //initialisation
      for(int i=0; i<k-1; i++) slash[i] = i+1;
      contrainte = INT_MAX;

      //algo
      copying_books(k-1);

      //output
      int scriber = 0;
      for(int i=0; i<m; i++)
      {
         if(i==best[scriber])
         {
            printf("/ ");
            scriber++;
         }
         if(i==m-1) printf("%d", p[i]);
         else       printf("%d ", p[i]);
      }
      printf("\n");
   }
   return 0;
}

void copying_books(int scriber)
{
   if(scriber == 0)
   {
      int contrainteCourante = calculeContrainte();
      if(contrainte > contrainteCourante)
      {
         contrainte = contrainteCourante;
         for(int i=0; i<k-1; i++) best[i] = slash[i];
      }
      return;
   }

   int next = m-1;
   if(scriber != k-1) next = slash[scriber];

   for(int i=slash[scriber-1]; i<next; i++)
   {
      slash[scriber-1] = i;
      copying_books(scriber-1);
   }
}

int calculeContrainte()
{
   int som=0, top=0, scriber=0;
   for(int i=0; i<m; i++)
   {
      if(i==slash[scriber])
      {
         top = max(top, som);
         som = 0;
         scriber++;
      }
      som += p[i];
   }
   top = max(top, som);
   return top;
}
