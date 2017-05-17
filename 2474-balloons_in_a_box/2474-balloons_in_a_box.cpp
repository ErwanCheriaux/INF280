#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <climits>
#include <math.h>
//#include <utility>

using namespace std;

class Balloon
{
   public:
      Balloon(int x, int y, int z): _x(x), _y(y), _z(z) {}

      virtual void display() {printf("{%d, %d, %d} r=%lf v=%lf\n", _x, _y, _z, _r, getV());}

      virtual int getX() {return _x;}
      virtual int getY() {return _y;}
      virtual int getZ() {return _z;}

      virtual double getR() {return _r;}
      virtual double getV() {return 4.188790205*_r*_r*_r;} // (4*pi)/3 = 4.188790205

      virtual void setR(double r) {_r = r;}

      virtual bool notUsed() {return (_r) ? false : true;}

   private:
      int _x, _y, _z;
      double _r=0;
};

class Box
{
   public:
      Box() {}

      virtual void display() {printf("Box volume free = %lf\n", volumeFree); for(auto b : balloons) b.display();}

      virtual long getVolumeFree() {calculeVolumeFree(); return round(volumeFree);}

      virtual void setFirstConner(int x, int y, int z) {first_x= x; first_y= y; first_z= z;}
      virtual void setOppoConner (int x, int y, int z) 
      {
         oppo_x = x; if(oppo_x < first_x) swap(oppo_x, first_x);
         oppo_y = y; if(oppo_y < first_y) swap(oppo_y, first_y);
         oppo_z = z; if(oppo_z < first_z) swap(oppo_z, first_z);
      }

      virtual void addBalloon(Balloon b)
      {
         if(b.getX() > first_x and b.getY() > first_y and b.getZ() > first_z and \
            b.getX() < oppo_x  and b.getY() < oppo_y  and b.getZ() < oppo_z)
         {
            balloons.push_back(b);
         }
      }

   private:
      vector<Balloon> balloons;
      int first_x, first_y, first_z;
      int oppo_x,  oppo_y,  oppo_z;
      double volumeFree=0;

      virtual void calculeVolumeFree()
      {
         //initialisation du volume libre
         volumeFree  = (oppo_x-first_x);
         volumeFree *= (oppo_y-first_y);
         volumeFree *= (oppo_z-first_z);

         while(1)
         {
            Balloon *balloon;
            double contrainteBalloonMin = 0;
            int index = 0;

            //recherche du ballon avec la plus faible contrainte
            for(auto b : balloons)
            {
               double contrainteBalloonMax = INT_MAX;
               if(b.notUsed())
               {
                  //contrainte de la boite
                  if(b.getX() - first_x < contrainteBalloonMax) contrainteBalloonMax = b.getX() - first_x;
                  if(b.getY() - first_y < contrainteBalloonMax) contrainteBalloonMax = b.getY() - first_y;
                  if(b.getZ() - first_z < contrainteBalloonMax) contrainteBalloonMax = b.getZ() - first_z;

                  if(oppo_x - b.getX() < contrainteBalloonMax) contrainteBalloonMax = oppo_x - b.getX();
                  if(oppo_y - b.getY() < contrainteBalloonMax) contrainteBalloonMax = oppo_y - b.getY();
                  if(oppo_z - b.getZ() < contrainteBalloonMax) contrainteBalloonMax = oppo_z - b.getZ();

                  //contrainte des autres ballons
                  for(auto other : balloons) 
                  {
                     if(!other.notUsed())
                     {
                        double dist = sqrt((b.getX() - other.getX())*(b.getX() - other.getX()) + \
                                           (b.getY() - other.getY())*(b.getY() - other.getY()) + \
                                           (b.getZ() - other.getZ())*(b.getZ() - other.getZ()));

                        dist = dist - other.getR();
                        if(dist <= 0)                        contrainteBalloonMax = 0;
                        else if(dist < contrainteBalloonMax) contrainteBalloonMax = dist;
                     }
                  }

                  //ballons ayant la plus faible contrainte
                  if(contrainteBalloonMin < contrainteBalloonMax)
                  {
                     contrainteBalloonMin = contrainteBalloonMax;
                     balloon = &balloons.at(index);
                  }
               }
               index++;
            }

            //s'il n'y a plus de ballon à gérer
            if(!contrainteBalloonMin) return;
            balloon->setR(contrainteBalloonMin);
            volumeFree = volumeFree - balloon->getV();
         }
      }
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

      printf("Box %d: %ld\n\n", nbTest, box.getVolumeFree());

      nbTest++;
   }
}
