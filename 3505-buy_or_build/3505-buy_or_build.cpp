#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

const int MAXQ = 8;
const int N    = 1000;

struct subnetwork
{
   int nb_cities;
   int price;
   vector<int> cities;
} subnetworks[MAXQ];

vector<int> Sets;
vector<pair<int, pair<int,int>>> Edges;

vector<pair<int,int>> Borduria;
int T, n, q, best_global, best_local;

void Union(int x, int y);
int  weight(int x, int y);
void Kruskal();

int main(void)
{
   scanf("%d\n\n", &T);
   for(int t=0; t<T; t++)
   {
      scanf("%d %d\n", &n, &q);
      //subnetworks
      for(int i=0; i<q; i++)
      {
         int nb, c, city;
         scanf("%d %d ", &nb, &c);
         subnetworks[i].nb_cities = nb;
         subnetworks[i].price = c;
         for(int j=0; j<nb; j++) 
         {
            scanf("%d", &city);
            subnetworks[i].cities.push_back(city-1);
         }
      }
      //cities
      for(int i=0; i<n; i++)
      {
         int x, y;
         scanf("%d %d\n", &x, &y);
         Borduria.push_back(make_pair(x, y));
      }

      //calcule du poid des arrètes
      for(int i=0; i<n-1; i++)
         for(int j=i+1; j<n; j++)
            Edges.push_back(make_pair(weight(i,j), make_pair(i,j)));

      best_global = INT_MAX;
      int maxT = pow(2, q);
      sort(Edges.begin(),  Edges.end()); // Sort edges by weight

      //test des 2⁸ cas par force brute
      for(int i=0; i<maxT; i++)
      {
         //initialisation
         Sets.clear();
         for(int j=0; j<n; j++) Sets.push_back(j);
         best_local = 0;
         //parcours des compagnies de télécommunication
         for(int j=0; j<q; j++)
         {
            //vérif de la présence de la compagnies
            if(1 & i >> j)
            {
               //ajout des villes dans Union
               for(int k=1; k<subnetworks[j].nb_cities; k++) 
                  Union(subnetworks[j].cities[k-1],subnetworks[j].cities[k]);
               best_local += subnetworks[j].price;
            }
         }
         //apres ajout des compagnies
         //on cherche un arbre couvrant de poid min
         Kruskal();
         best_global = min(best_global, best_local);
      }

      //output
      printf("%d\n", best_global);
      if(t<T-1) 
      {
         printf("\n");
         //réinitialisation
         for(int i=0; i< q; i++) subnetworks[i].cities.clear();
         Edges.clear();
         Borduria.clear();
      }
   }
   return 0;
}

int weight(int x, int y)
{
   return (Borduria[x].first - Borduria[y].first)   * \
          (Borduria[x].first - Borduria[y].first)   + \
          (Borduria[x].second - Borduria[y].second) * \
          (Borduria[x].second - Borduria[y].second);
}

void Union(int x, int y)
{
   int ensembleX = Sets[x];
   int ensembleY = Sets[y];

   if(ensembleX == ensembleY) return;

   for(auto &tmp : Sets)
      if(tmp == ensembleY)
         tmp = ensembleX;
}

/* 
 * Alogorithme récupéré dans les slides de cours 
 * et adapté pour les besoins du problème
 */
void Kruskal() 
{
   for(auto tmp : Edges)
   {
      auto edge = tmp.second;
      if(Sets[edge.first] != Sets[edge.second]) 
      {
         Union(edge.first, edge.second); // update Union-Find DS
         best_local += tmp.first; //somme du poid de chaque arrète de l'arbre
      }
   }
}
