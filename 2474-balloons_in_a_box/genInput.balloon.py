from random import randint

f = open("balloons.input","w")


def get_alea(a,b):
    return str(randint(a,b)) + " "\
           +str(randint(a,b)) + " "\
           +str(randint(a,b)) + "\n"

for i in range(10000):
    n = randint(1,6)
    n = 6
    f.write(str(n)+"\n")
    f.write(get_alea(-10,10))
    f.write(get_alea(-10,10))
    for p in range(n):
        f.write(get_alea(-8,8))

f.write("0\n")

f.close()
