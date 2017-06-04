from random import randint

f = open("taxi.input","w")

N = 1000
f.write(str(N) + "\n")

heure = []
minute = []

for i in range(N):
   M = randint(1, 499)

   f.write(str(M) + "\n")

   for j in range(M):
      heure.append(randint(0, 23))
      minute.append(randint(0, 59))

   heure.sort()
   minute.sort()

   for j in range(M):
      if heure[j] < 10:
         f.write("0" + str(heure[j]) + ":")
      else:
         f.write(str(heure[j]) + ":")

      if minute[j] < 10:
         f.write("0" + str(minute[j]))
      else:
         f.write(str(minute[j]))

      for k in range(4):
         f.write(" " + str(randint(0, 199)))

      f.write("\n")

f.close()
