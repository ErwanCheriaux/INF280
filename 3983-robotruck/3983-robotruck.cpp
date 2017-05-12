#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

//prototype
int robotruck(int numPackage);

//class
class Package
{
   public:
      Package(int x, int y, int p) : _x(x), _y(y), _p(p) {}
      virtual void display() {printf("%d, %d, %d, %d\n", _x, _y, _p, _min);}

      virtual int getX() {return _x;}
      virtual int getY() {return _y;}
      virtual int getP() {return _p;}

      virtual int distFromOrigin()   {return _x + _y;}
      virtual int dist(int x, int y) {return abs(x - _x) + abs(y - _y);}

      virtual int next(int numPackage)
      {
         if(_min == INT_MAX) _min = robotruck(numPackage);
         return _min;
      }

   private:
      int _x, _y, _p;
      int _min = INT_MAX;
};

//variables globales
int P, N;
vector<Package> packages;

//main
int main(void)
{
   int n;

   scanf("%d", &n);

   for(int t=0; t<n; t++)
   {
      scanf("%d", &P);
      scanf("%d", &N);
    
      packages.clear();

      //input
      for(int i=0; i<N; i++) 
      {
         int x, y, p;
         scanf("%d %d %d", &x, &y, &p);
         packages.push_back(Package(x,y,p));
      }

      //debug
      for(auto pack : packages) pack.display();

      //output
      printf("%d", robotruck(0));
      if(t == n-1) printf("\n");
      else         printf("\n\n");
   }
   return 0;
}

//algo
int robotruck(int numPackage)
{
   //caractéristique courante
   int distanceMin = INT_MAX;
   int poid = 0;
   int dist = 0;
   int x=0, y=0;

   //tant que le poid n'est pas dépassé et qu'il reste des paquets
   while(poid + packages[numPackage].getP() <= P and numPackage<N)
   {
      //mise à jour des caratéristiques
      poid = poid + packages[numPackage].getP();
      dist = dist + packages[numPackage].dist(x, y);

      x = packages[numPackage].getX();
      y = packages[numPackage].getY();

      //distance avec retour à l'origine
      int distanceTour = dist + packages[numPackage].distFromOrigin();
      if(numPackage+1<N) distanceTour += packages[numPackage].next(numPackage+1);
      if(distanceMin > distanceTour) distanceMin = distanceTour;
      numPackage++;

      //debug
      printf("\nnumPackage = %d\n", numPackage);
      for(auto pack : packages) pack.display();
   }
   return distanceMin;
}
