#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>

using namespace std;

int m, k, p[500], slash[500], best[500];
long long contrainte;

void copying_books();
int calculeContrainte();

int main(void)
{
   int N;
   scanf("%d", &N);

   for(int t=0; t<N; t++)
   {
      //lecture input
      scanf("%d %d\n", &m, &k);
      
      if(k==1)
      {
         string str;
         getline (cin, str);
         cout << str << endl;
         continue;
      }

      for(int i=0; i<m; i++)
      {
         scanf("%d", &p[i]);
         slash[i] = 0;
         best[i]  = 0;
      }

      //initialisation
      for(int i=0; i<k-1; i++) slash[i] = i+1;
      contrainte = LLONG_MAX;

      //algo
      copying_books();

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

void copying_books()
{
   while(1)
   {
      int scriber = calculeContrainte();
      if(!scriber or slash[scriber]-1 == slash[scriber-1]) return;
      slash[scriber-1]++;
   }
}

int calculeContrainte()
{
   long long som=0, topSom=0;
   int scriber=0, topScriber=0;

   for(int i=0; i<m; i++)
   {
      if(i==slash[scriber])
      {
         if(topSom < som)
         {
            topSom = som;
            topScriber = scriber;
         }
         som = 0;
         scriber++;
      }
      som += p[i];
   }

   if(topSom < som)
   {
      topSom = som;
      topScriber = scriber;
   }

   if(topSom < contrainte)
   {
      contrainte = topSom;
      for(int i=0; i<k-1; i++) best[i] = slash[i];
   }
   return topScriber;
}
