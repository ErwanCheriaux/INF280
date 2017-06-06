#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
   while(1)
   {
      string str;
      getline(cin, str);

      if(str == "\0") return 0;

      vector<char> S;
      int cpt_multiple=0;

      for(auto c : str)
      {
         if(c > 47 && c < 58) 
         {
            int sum = 0;
            S.push_back(c-48);
            for (iterator<char> it = S.end()-1; it != S.begin()-1; --it)
            {
               sum = (sum + *it) % 3;
               if(!sum) cpt_multiple++;
            }
         }
      }

      printf("%d\n", cpt_multiple);
   }
}
