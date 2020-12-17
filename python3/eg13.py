f=open("pqr.xyz","r")
while True:
    print(f.tell())
    a=f.readline()
    if len(a)==0: break
    print(a.strip())
f.close()
