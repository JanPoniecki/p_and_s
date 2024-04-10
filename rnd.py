import random
import sys
import os

# ints = input("type nr of integers, 10 is default")
# if ints == "":
# 	ints = 10
ints = int(sys.argv[1])
i = 0;

result = []

while (i < int(ints)):
	nr = random.randint(-100, 100)
	if nr not in result:
		result.append(nr)
		i += 1

for r in result:
	print(f'{r} ', end="")

with open("log.txt", "w") as log:
	log.write(str(result))
