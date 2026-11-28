"""python auto/callers.py EXE TARGETHEX [mapfile]: list E8 call sites to TARGET in .text (with containing symbol if map given)."""
import sys,struct,pefile,re,bisect
pe=pefile.PE(sys.argv[1],fast_load=True); t=int(sys.argv[2],16)
sec=[s for s in pe.sections if s.Name.startswith(b'.text')][0]; base=0x400000+sec.VirtualAddress; d=sec.get_data()
rows=[]
if len(sys.argv)>3:
    for l in open(sys.argv[3],errors='ignore'):
        p=l.split()
        if len(p)>=4 and re.fullmatch(r'[0-9a-f]{8}',p[2]): rows.append((int(p[2],16),p[1]))
    rows.sort()
ks=[r[0] for r in rows]
i=d.find(b'\xe8')
while i!=-1:
    if i+5<=len(d) and base+i+5+struct.unpack_from('<i',d,i+1)[0]==t:
        a=base+i; j=bisect.bisect_right(ks,a)-1
        print(hex(a), rows[j][1][:120]+'+%x'%(a-rows[j][0]) if j>=0 else '')
    i=d.find(b'\xe8',i+1)
