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

      for(int i=0; i<m; i++)
      {
         scanf("%d", &p[i]);
         slash[i] = i;
      }

      contrainte = INT_MAX;
      copying_books(k);

      //output
      printf("%d\n", contrainte);
      for(int i=0; i<k; i++) printf("%d, ", best[i]);
      printf("\n\n");
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
         for(int i=0; i<k; i++) best[i] = slash[i];
      }
      return;
   }

   int fin = m;
   if(scriber != k) fin = slash[scriber+1];

   for(int i=slash[scriber]; i<fin; i++)
   {
      slash[scriber] = i;
      copying_books(scriber-1);
   }
}

int calculeContrainte()
{
   int som=0, top=0, scriber=1;
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
   return top;
}
