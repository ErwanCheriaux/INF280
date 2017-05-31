#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <list>

using namespace std;

const int MAXN = 100;

vector<int> Circuit;
list<int> Adj[MAXN];

void Hierholzer()
{
   int v = 0;

   stack<int> Stack;
   Stack.push(v);

   while(!Stack.empty())
   {
      if(!Adj[v].empty())
      {
         // follow edges until stuck
         Stack.push(v);
         int tmp = *Adj[v].begin();
         // remove edge, modifying graph
         Adj[v].remove(tmp);
         Adj[tmp].remove(v);
         v = tmp;
      }
      else
      {
         // got stuck: stack contains a circuit
         Circuit.push_back(v);
         // append node at the end of circuit
         v = Stack.top();
         // backtrack using stack, find larger circuit
         Stack.pop();
      }
   }
}

int main(void)
{
   return 0;
}
