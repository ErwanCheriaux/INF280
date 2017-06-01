#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXQ = 8;
const int N    = 1000;

struct subnetwork
{
   int nb_cities;
   int price;
   vector<int> cities;
} subnetworks[MAXQ];

map<int, pair<int,unsigned int>> Sets;  // map to parent & rank
vector<pair<int, pair<int,int>>> Edges;
set<pair<int,int>> A;  // Final minimum spanning tree

vector<pair<int,int>> Borduria;
int T, n, q, best_global, best_local;

void MakeSet(int x);
int  Find(int x);
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
            subnetworks[i].cities.push_back(city);
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
         A.clear();
         Sets.clear();
         for(int u=0; u<n; u++) MakeSet(u); // Initialize Union-Find DS
         best_local = 0;
         //parcours des compagnies de télécommunication
         for(int j=0; j<q; j++)
         {
            //vérif de la présence de la compagnies
            if(1 & i << j)
            {
               //ajout des villes dans Union
               for(int k=1; k<subnetworks[j].nb_cities; k++) 
                  Union(subnetworks[j].cities[k-1],subnetworks[j].cities[k-1]);
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
      if(t<T-1) printf("\n");

      //réinitialisation
      for(int i=0; i< q; i++) subnetworks[i].cities.clear();
      Edges.clear();
      Borduria.clear();
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

void MakeSet(int x)
{ 
   Sets.insert(make_pair(x, make_pair(x, 0)));
}

int Find(int x) 
{
   if(Sets[x].first == x) return x;                  // Parent == x ?
   else return Sets[x].first = Find(Sets[x].first);  // Get Parent
}

void Union(int x, int y)
{
   int parentX = Find(x), parentY = Find(y);
   int rankX = Sets[parentX].second, rankY = Sets[parentY].second;

   if(parentX == parentY) return;
   else if(rankX < rankY) Sets[parentX].first = parentY;
   else Sets[parentY].first = parentX;
   if(rankX == rankY) Sets[parentX].second++;;
}

void Kruskal() 
{
   for(auto tmp : Edges)
   {
      auto edge = tmp.second;
      if(Find(edge.first) != Find(edge.second)) 
      {
         Union(edge.first, edge.second);  // update Union-Find DS
         A.insert(edge);                  // include edge in MST
         //somme du poid de chaque arrète de l'arbre
         best_local += tmp.first;
      }
   }
}
