#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <climits>
#include <math.h>
#include <utility>

using namespace std;

class Balloon
{
   public:
      Balloon(int x, int y, int z): x(x), y(y), z(z) {}

      virtual double getVolume() {return 4.188790205*r*r*r;} // (4*pi)/3 = 4.188790205

      virtual bool notUsed() {return (r) ? false : true;}

      int x, y, z;
      double r=0;
};

class Box
{
   public:
      Box() {}

      virtual double getVolume()
      {
         int volume  = (oppo_x-first_x);
             volume *= (oppo_y-first_y);
             volume *= (oppo_z-first_z);
         return volume;
      }

      virtual void setFirstConner(int x, int y, int z) {first_x= x; first_y= y; first_z= z;}
      virtual void setOppoConner (int x, int y, int z) 
      {
         oppo_x = x; if(oppo_x < first_x) swap(oppo_x, first_x);
         oppo_y = y; if(oppo_y < first_y) swap(oppo_y, first_y);
         oppo_z = z; if(oppo_z < first_z) swap(oppo_z, first_z);
      }

      virtual void addBalloon(Balloon b)
      {
         if(b.x > first_x and b.y > first_y and b.z > first_z and \
            b.x < oppo_x  and b.y < oppo_y  and b.z < oppo_z)
         {
            balloons.push_back(b);
         }
      }

      vector<Balloon> balloons;
      int first_x, first_y, first_z;
      int oppo_x,  oppo_y,  oppo_z;
};

double volumeBallons;
void   calculeVolumeBalloon(Box *box, double volumeCourant);

int main(void)
{
   int nbTest = 1;

   while(1)
   {
      int n, x, y, z;
      Box *box;

      scanf("%d", &n);
      if(!n) return 0;
      if(nbTest > 1) printf("\n");
      
      //first corner
      scanf("%d %d %d", &x, &y, &z);
      box->setFirstConner(x, y, z);

      //opposite corner
      scanf("%d %d %d", &x, &y, &z);
      box->setOppoConner(x, y, z);

      //balloons
      for(int i=0; i<n; i++)
      {
         scanf("%d %d %d", &x, &y, &z);
         box->addBalloon(Balloon(x, y, z));
      }

      volumeBallons = 0;
      calculeVolumeBalloon(box, 0.0);
      printf("Box %d: %lf\n", nbTest, box->getVolume() - volumeBallons);

      nbTest++;
   }
}

void calculeVolumeBalloon(Box *box, double volumeCourant)
{
   //maximisation du volume occupé par les ballons
   volumeBallons = max(volumeBallons, volumeCourant);

   for(auto balloon : box->balloons)
   {
      if(balloon.notUsed())
      {
         //contrainte de la boite
         double contrainte = balloon.x - box->first_x;
         if(balloon.y - box->first_y < contrainte) contrainte = balloon.y - box->first_y;
         if(balloon.z - box->first_z < contrainte) contrainte = balloon.z - box->first_z;

         if(box->oppo_x - balloon.x < contrainte) contrainte = box->oppo_x - balloon.x;
         if(box->oppo_y - balloon.y < contrainte) contrainte = box->oppo_y - balloon.y;
         if(box->oppo_z - balloon.z < contrainte) contrainte = box->oppo_z - balloon.z;

         //contrainte des autres ballons
         for(auto other : box->balloons) 
         {
            if(!other.notUsed())
            {
               double dist = sqrt((balloon.x - other.x)*(balloon.x - other.x) + \
                                  (balloon.y - other.y)*(balloon.y - other.y) + \
                                  (balloon.z - other.z)*(balloon.z - other.z));

               dist = dist - other.r;

               //le ballon ne doit pas etre dans un autre ballon
               if(dist <= 0)              contrainte = 0;
               else if(dist < contrainte) contrainte = dist;
            }
         }

         //s'il n'y a plus de ballon à gérer
         if(contrainte)
         {
            balloon.r = contrainte;
            calculeVolumeBalloon(box, volumeCourant + balloon.getVolume());
            balloon.r = 0;
         }
      } 
   }
}
