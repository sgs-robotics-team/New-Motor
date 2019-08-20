a = [1,244,1,244]
size = int(len(a)/2)

def iToC(inp):
    out = [0 for x in range(size*2)]
    for i in range(size):
        out[2*i]=inp[i]>>8
        out[2*i+1]=inp[i]&0xff
    return out

def cToI(inp):
    out = [0 for x in range(size)]
    for i in range(size):
        out[i]=(inp[2*i]<<8)+(inp[2*i+1])
    return out

print(a)
b = cToI(a)
print(b)
c = iToC(b)
print(c)
