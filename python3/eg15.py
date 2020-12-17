f=open("pqr.xyz","r")
while True:
    print(f.tell())
    a=f.read(1)
    if len(a)==0: break
    print(f'({a})',a.__class__)
f.close()
