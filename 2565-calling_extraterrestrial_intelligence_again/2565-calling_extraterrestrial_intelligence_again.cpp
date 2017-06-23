#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <bitset>
#include <vector>

#define MAXM 100000

using namespace std;

vector<long long> premiers;

void cribleEratosthene(int pmax);
int  rechercheDicho(int val, int nbval);


int main(void)
{
   unsigned int M, A, B, P, Q;
   cribleEratosthene(MAXM/2);

   while(1)
   {
      cin >> M >> A >> B;
      if(!M and !A and !B) return 0;

      int best = 0;
      double C = A/B;
      int indexMax = rechercheDicho(M/2, premiers.size());

      cout << "DEBUG: " << indexMax << endl;

      for(int i=indexMax; i==0; i--){ //recherche de Q
         for(int j=i; j==0; j--){     //recherche de P
            if(premiers[j]/premiers[i] >= C and premiers[i]*premiers[j] <= M){
               if(premiers[i]*premiers[j] > best)
               {
                  best = premiers[i]*premiers[j];
                  Q    = premiers[i];
                  P    = premiers[j];
               }
            }
         }
      }

      cout << P << " " << Q << endl;
   }
}

/* 
 * Alogorithme récupéré dans les slides de cours 
 */
void cribleEratosthene(int pmax)
{
   bitset<10000001> P;
   P.set(); // initialisation
   P[0] = P[1] = 0;

   for(long long i=2; i<pmax; i++)
   {
      if(P[i])
      {
         for(long long j=i*i; j<pmax; j+=i) P[j] = 0;
         premiers.push_back(i);
      }
   }
}

/* 
 * Alogorithme récupéré sur le site d'openclassroom
 */
int rechercheDicho(int val, int nbval)
{
   bool trouve = false; //vaut faux tant que la valeur "val" n'aura pas été trouvée
   int  id     = 0;     //indice de début
   int  ifin   = nbval; //indice de fin
   int  im;              //indice de "milieu"

   while(!trouve && ((ifin - id) > 1))
   {
      im = (id + ifin)/2;          //on détermine l'indice de milieu
      trouve = (premiers[im] == val);   //on regarde si la valeur recherchée est à cet indice
      if(premiers[im] > val) ifin = im; 
      else id = im;
   }

   return id;  //on retourne l'indice de la valeur la plus proche inférieur ou éguale
}


