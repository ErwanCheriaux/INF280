#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
#include <list>

using namespace std;

char S[1000000];

int main(void)
{
   while(1)
   {
      string str;
      getline(cin, str);

      if(str == "\0") return 0;

      int cpt_number = 0;
      int cpt_multiple=0;

      for(auto c : str)
      {
         if(c > 47 && c < 58) 
         {
            int sum = 0;
            S[cpt_number] = c-48;
            for(int i=cpt_number; i >= 0; i--)
            {
               sum = (sum + S[i]) % 3;
               if(!sum) cpt_multiple++;
            }
            cpt_number++;
         }
         else  cpt_number = 0;
      }

      printf("%d\n", cpt_multiple);
   }
}
