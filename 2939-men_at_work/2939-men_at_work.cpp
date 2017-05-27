#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void)
{
   int N;
   while(scanf("%d\n", &N)==1)
   {
      char maze[N][N];
      char work[N][N];

      for(int i=0; i<N; i++) {
         for(int j=0; j<N; j++) {
            if(j==N-1) scanf("%c\n", &maze[i][j]);
            else       scanf("%c",   &maze[i][j]);
         }
      }

      for(int i=0; i<N; i++) {
         for(int j=0; j<N; j++) {
            if(j==N-1) scanf("%c\n", &work[i][j]);
            else       scanf("%c",   &work[i][j]);
         }
      }

      for(int i=0; i<N; i++) {
         for(int j=0; j<N; j++) {
            printf("%c", maze[i][j]);
         }
         printf("\n");
      }

      for(int i=0; i<N; i++) {
         for(int j=0; j<N; j++) {
            printf("%c", work[i][j]);
         }
         printf("\n");
      }
   }
   return 0;
}
