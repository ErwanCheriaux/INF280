from random import randint

f = open("ASP.input","w")

for i in range(1000):
   N = randint(2, 500)
   M = randint(1, 10000)
   S = randint(0, N-1)
   D = randint(0, N-1)
   while(S == D):
      D = randint(0, N-1)

   f.write(str(N) + " " + str(M) + "\n")
   f.write(str(S) + " " + str(D) + "\n")
   for p in range(M):
      U = randint(0, N-1)
      V = randint(0, N-1)
      while(U == V):
         V = randint(0, N-1)
      P = randint(1, 1000)
      f.write(str(U) + " " + str(V) + " " + str(P) + "\n")

   f.write("\n")

f.write("0 0\n")
f.close()
