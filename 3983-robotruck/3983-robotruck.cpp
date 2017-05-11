#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Package
{
   public:
      Package(int x, int y, int p) : _x(x), _y(y), _p(p) {}
      virtual void display() {printf("%d, %d, %d, %d\n", _x, _y, _p, _min);}

      virtual int getX() {return _x;}
      virtual int getY() {return _y;}

      virtual int distFromOrigine() {return _x + _y;}
      virtual int distFromPackage(Package *other) {return abs(this->_x - other->getX()) + abs(this->_y - other->getY());}

   private:
      int _x, _y, _p;
      int _min = INT_MAX;
};

int robotruck(int numPackage, vector<Package> packages)
{
   return 0;
}

int main(void)
{
   int n, P, N;

   scanf("%d", &n);

   for(int t=0; t<n; t++)
   {
      scanf("%d", &P);
      scanf("%d", &N);
    
      vector<Package> packages;
  
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
      printf("%d", robotruck(0, packages));
      if(t == n-1) printf("\n");
      else         printf("\n\n");
   }

   return 0;
}
