syms={}
for line in open('linkexp/qt.map',errors='ignore'):
    p=line.split()
    if len(p)>=4:
        try:
            v=int(p[2],16)
            syms[v]=p[1]
        except: pass
addrs=[0x851b3b,0x8a7d6b,0x755908,0x8577a9,0x8541a9,0x8541cb,0x853a69,0x44b2ea,0x6b85c0,0x6cde6716]
for a in addrs:
    best=None
    for s in syms:
        if s<=a and (best is None or s>best): best=s
    print(hex(a), '->', hex(best) if best else None, syms.get(best))