from random import *

f = open("polygon.input","w")

for n in range(1):
   for i in range(3):
      for j in range(2):
         a = random()
         b = randint(-10000,10000)
         f.write(str(a*b))
         if j == 0:
            f.write(" ")
      f.write("\n")

f.write("END\n")

f.close()
