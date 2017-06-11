from random import randint

f = open("painting.input","w")

hp = 2
wp = 4

hm = 6
wm = 6

f.write(str(hp) + " " + str(wp) + " " + str(hm) + " " + str(wm) + "\n")

for i in range(hp):
   for j in range(wp):
      c = randint(0, 1)
      c = 'x' if c else 'o'
      f.write(c)
   f.write("\n")

for i in range(hm):
   for j in range(wm):
      c = randint(0, 1)
      c = 'x' if c else 'o'
      f.write(c)
   f.write("\n")

f.close()
