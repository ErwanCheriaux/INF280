from random import randint

f = open("balloons.input","w")


def get_alea(a,b):
    return str(randint(a,b)) + " "\
           +str(randint(a,b)) + " "\
           +str(randint(a,b)) + "\n"

for i in range(10000):
    n = randint(1,6)
    f.write(str(n)+"\n")
    f.write(get_alea(-100,100))
    f.write(get_alea(-100,100))
    for p in range(n):
        f.write(get_alea(-80,80))

f.write("0\n")

f.close()
