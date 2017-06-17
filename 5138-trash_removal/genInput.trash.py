from random import *
from math import *


f = open("trash.input","w")

for n in range(10):
   n = 4
   f.write(str(n))
   f.write("\n")
   for i in range(n):
      x = randint(0,1000)
      y = randint(0,1000)
      f.write(str(x))
      f.write(" ")
      f.write(str(y))
      f.write("\n")

f.write("0\n")

f.close()
