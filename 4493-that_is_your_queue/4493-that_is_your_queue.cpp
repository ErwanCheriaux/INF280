#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <list>

using namespace std;

int main(void)
{
   int P, C, numero, index=1;
   char citizen;

   while(1)
   {
      scanf("%d %d\n", &P, &C);
      if(!P and !C) return 0;

      printf("Case %d:\n", index++);

      //on ne peut pas distribuer plus de médicament 
      //que ce qui à été commandé
      if(C<P) P=C;

      //initialisation de la queue
      list<int> queue;
      for(int i=0; i<P; i++) queue.push_front(P-i);

      //défilement de la queue
      for(int i=0; i<C; i++)
      {
         scanf("%c\n", &citizen);
         if(citizen == 'E') 
         {
            scanf("%d\n", &numero);
            //on le positionne en tête
            queue.remove(numero);
            queue.push_front(numero);
         }
         else
         {
            printf("%d\n", queue.front());
            //rotation de la queue
            queue.push_back(queue.front());
            queue.pop_front();
         }
      }
   }
}
