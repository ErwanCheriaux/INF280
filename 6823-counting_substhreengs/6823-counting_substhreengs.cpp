#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> S;

void shift(int sens);

int main(void)
{
   while(1)
   {
      string str;
      getline(cin, str);

      if(str == "\0") return 0;

      S.clear();
      int result = 0;
      for(int i=0; i<3; i++) S.push_back(0);

      for(auto c : str)
      {
         //s'il sagit d'un chiffre
         if(c >= '0' && c <= '9') 
         {
            int chiffre = (c-'0')%3;
            //on décale en fonction du chiffre
            shift(chiffre);
            result = result + S.front();
            //si le chiffre est multiple de 3
            if(!chiffre) result++;
            S[chiffre]++;
         }
         else
         {
            S.clear();
            for(int i=0; i<3; i++) S.push_back(0);
         }
      }
      printf("%d\n", result);
   }
}

void shift(int sens)
{
   //multiple de 3 +1
   if(sens == 1)
   {
      S.push_back(S.front());
      S.pop_front();
   }
   //multiple de 3 -1
   else if(sens == 2)
   {
      S.push_front(S.back());
      S.pop_back();
   }
}
