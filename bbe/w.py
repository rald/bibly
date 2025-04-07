f = open("bbe.inf", "r")

for l in f:
  print(l.split("|",2)[1])
