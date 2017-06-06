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
            for(int i=S.size()-1; i>=0; i--)
            {
               sum = (sum + S[i]) % 3;
               if(!sum) cpt_multiple++;
            }
         }
         else S.clear();
      }

      printf("%d\n", cpt_multiple);
   }
}
