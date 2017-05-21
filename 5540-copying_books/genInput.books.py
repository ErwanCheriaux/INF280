from random import randint

f = open("books.input","w")

def get_alea(a,b):
    return str(randint(a,b)) + " "

N = 100
f.write(str(N) + "\n")

for i in range(N):
    m = randint(1, 500)
    k = randint(1, m)

    f.write(str(m) + " " + str(k) + "\n")
    for p in range(m):
        f.write(get_alea(1,30))
    
    f.write("\n")

f.close()
