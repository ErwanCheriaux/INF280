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

int main(void)
{
   while(1)
   {
      string str;
      getline(cin, str);

      if(str == "\0") return 0;

      cout << str << endl;
   }
}
