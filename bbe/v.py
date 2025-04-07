f1 = open("bbe-01.inf","r")
f2 = open("abbr","r")

for x in f1:
  w=f2.readline().strip()
  y=x.split("|")
  z=y[0]+"|"+w+"|"+y[2]+"|"+y[3]+"|"+y[4]
  print(z.strip())
