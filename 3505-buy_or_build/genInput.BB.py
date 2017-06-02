from random import randint

f = open("BB.input","w")

T = 1

for i in range(T):
   n = 1000
   q = 8

   f.write(str(T) + "\n\n")
   f.write(str(n) + " " + str(q) + "\n")

   for j in range(q):
      nb = randint(2, n)
      wc = randint(1, 2000000)
      f.write(str(nb) + " " + str(wc))
      for k in range(nb):
         f.write(" " + str(randint(1, n)))
      f.write("\n")

   for j in range(n):
      f.write(str(randint(0, 3000)) + " " + str(randint(0, 3000)) + "\n")

   if(i<T-1):
      f.write("\n")

f.close()
