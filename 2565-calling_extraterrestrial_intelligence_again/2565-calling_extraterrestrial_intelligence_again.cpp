#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <bitset>
#include <vector>

#define MAXM 100000

using namespace std;

bitset<10000001> P;
vector<long long> premiers;

void cribleEratosthene(int pmax);

unsigned int M, A, B;

int main(void)
{
   cribleEratosthene(MAXM/2);

   while(1)
   {
      cin >> M >> A >> B;
      if(!M and !A and !B) return 0;

      cout << M << endl;
      cout << A << endl;
      cout << B << endl;
   }
}

void cribleEratosthene(int pmax)
{
   P.set(); // initialisation
   P[0] = P[1] = 0;

   for(long long i=2; i<pmax; i++)
   {
      if(P[i])
      {
         for(long long j=i*i; j<pmax; j+=i) P[j] = 0;
         premiers.push_back(i);
      }
   }
}
