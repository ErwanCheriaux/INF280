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

unsigned long long A, B;

/* source : http://oeis.org/A000788/a000788.txt */
unsigned long long A000788(unsigned long long n)
{
   unsigned long long v = 0;
   for (unsigned long long bit = 1; bit <= n; bit <<= 1)
      v += ((n>>1)&~(bit-1)) + ((n&bit) ? (n&((bit<<1)-1))-(bit-1) : 0);
   return v;
}

int main(void)
{
   while(1)
   {
      if(!(cin >> A >> B)) return 0;

      cout << A << " : " << A000788(A) << endl;
      cout << B << " : " << A000788(B) << endl;
      cout << A000788(B) - A000788(A) + 1 << endl;
   }
}
