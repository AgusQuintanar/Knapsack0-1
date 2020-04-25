import random
import math
f = open("generatedFile.txt", "w")

n = 1000000
f.write(str(n)+"\n")
for x in range(2*n):
    f.write(str(random.randint(1, int(n*math.log2(n))))+"\n")
f.write(str(int(random.randint(int(n/2), int(n**1.5))/10)))

f.close()