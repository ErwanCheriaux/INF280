from random import *
from math import *


f = open("polygon.input","w")

for n in range(50):
   for i in range(3):
      for j in range(2):
         a = random()
         b = randint(-10000,10000)
         c = round(a*b,6)
         f.write(str(c))
         if j == 0:
            f.write(" ")
      f.write("\n")

f.write("END\n")

f.close()
