with open("pqr.xyz") as f:
    while True:
        a=f.readline()
        if len(a)==0: break
        a=a.strip()
        print(a)
