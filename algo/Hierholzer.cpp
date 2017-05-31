#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 100;

vector<int> Circuit;
vector<int> Adj[MAXN];

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
         auto it_tmp = Adj[v].begin();
         auto it_v = Adj[tmp].begin();
         int index = 0;
         // remove edge, modifying graph
         Adj[v].erase(it_tmp);
         for(auto node : Adj[tmp])
         {
            if(node == v) it_v = Adj[tmp].begin()+index;
            index++;
         }
         Adj[tmp].erase(it_v);
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
