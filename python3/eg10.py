try:
    f=open("whatever.xyz")
    a=f.read()
    f.close()
    print(a)
except FileNotFoundError:
    print("File does not exist")
