from random import *
from math import *


f = open("polygon.input","w")

for n in range(5):
   for i in range(3):
      for j in range(2):
         a = random()
         b = randint(-10,10)
         c = round(a*b)
         f.write(str(c))
         if j == 0:
            f.write(" ")
      f.write("\n")

f.write("10 0\n")
f.write("0 10\n")
f.write("0 -10\n")

f.write("END\n")

f.close()
