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

double x[3], y[3];

int main(void)
{
   while(1)
   {
      string str;
      cin >> str >> y[0];
      if(str == "END") return 0;

      x[0] = atof(str.c_str());
      for(int i=1; i<3; i++) cin >> x[i] >> y[i];

      printf("{%f,%f,%f}\n", x[0], x[1], x[2]);
      printf("{%f,%f,%f}\n", y[0], y[1], y[2]);

      scanf("\n");
   }
}
