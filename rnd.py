import random

ints = input("type nr of integers, 10 is default")
if ints == "":
	ints = 10
i = 0;

while (i < int(ints)):
	print(f"{random.randint(-100, 100)} ", end="")
	i += 1