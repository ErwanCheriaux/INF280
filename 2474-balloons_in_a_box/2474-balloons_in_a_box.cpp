#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

class Balloon
{
   public:
      Balloon(int x, int y, int z): _x(x), _y(y), _z(z) {}

      virtual void display() {printf("{%d, %d, %d} r=%d v=%d\n", _x, _y, _z, _r, _v);}

   private:
      int _x, _y, _z;
      int _r=0, _v=0;
};

class Box
{
   public:
      Box() {}

      virtual void display() {for(auto b : balloons) b.display();}

      virtual void setFirstConner(int x, int y, int z) {first_x= x; first_y= y; first_z= z;}
      virtual void setOppoConner (int x, int y, int z) {oppo_x = x; oppo_y = y; oppo_z = z;}

      virtual void addBalloon(Balloon b) {balloons.push_back(b);}

   private:
      vector<Balloon> balloons;
      int first_x, first_y, first_z;
      int oppo_x,  oppo_y,  oppo_z;
      int _v;
};

int main(void)
{
   int nbTest = 1;

   while(1)
   {
      int n, x, y, z;
      Box box;

      scanf("%d", &n);
      if(!n) return 0;
      
      //first corner
      scanf("%d %d %d", &x, &y, &z);
      box.setFirstConner(x, y, z);

      //opposite corner
      scanf("%d %d %d", &x, &y, &z);
      box.setOppoConner(x, y, z);

      //balloons
      for(int i=0; i<n; i++)
      {
         scanf("%d %d %d", &x, &y, &z);
         box.addBalloon(Balloon(x, y, z));
      }

      box.display();

      nbTest++;
   }
}
