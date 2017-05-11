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

   private:
      int _x, _y, _p;
      int _min = INT_MAX;
};

int main(void)
{
   int n, P, N;

   scanf("%d", &n);

   for(int t=0; t<n; t++)
   {
      scanf("%d", &P);
      scanf("%d", &N);
    
      int x, y, p;
      vector<Package> packages;
  
      for(int i=0; i<N; i++) 
      {
         scanf("%d %d %d", &x, &y, &p);
         packages.push_back(Package(x,y,p));
      }

      for(auto pack : packages) pack.display();
   }

   return 0;
}
