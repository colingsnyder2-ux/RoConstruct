import json,struct,os,collections
H='C:/Users/colin/RoConstruct/work/donorfree-route/'
def syms(p):
    b=open(p,'rb').read()
    if b[:2]==b'\x00\x00' and b[2:4]==b'\xff\xff': return None
    mach,ns,_,ptr,nsym,opt,_=struct.unpack('<HHIIIHH',b[:20])
    st=ptr+18*nsym; out=[]
    i=0
    while i<nsym:
        o=ptr+18*i
        nm,val,sec,typ,cls,aux=struct.unpack('<8sIhHBB',b[o:o+18])
        if nm[:4]==b'\0\0\0\0':
            off=struct.unpack('<I',nm[4:])[0]; e=b.index(b'\0',st+off); name=b[st+off:e].decode('latin1')
        else: name=nm.rstrip(b'\0').decode('latin1')
        if cls==2 and sec>0 and (typ>>4)==2: out.append(name)
        i+=1+aux
    return out
d=json.load(open(H+'auto/stub_candidates.json'))
bind=[];cat=collections.Counter()
for e in d:
    best=None
    for c in e['cands']:
        o=c.get('obj')
        if not o or not os.path.exists(o): continue
        s=syms(o) or []
        c['defines_stub_name']=e['stub'] in s
        c['code_symbols']=[x for x in s if any(x.endswith(a) or a in x for a in e['addrs'])][:6] or s[:4]
        if c['kind']=='renamed_obj' and not best: best=c
        elif c['kind']=='autorecover' and (not best or best['kind']!='renamed_obj'): best=c
    e['best']=best
    cat[(best['kind'],best['defines_stub_name']) if best else 'none']+=1
json.dump(d,open(H+'auto/stub_bindings.json','w'),indent=0)
print(cat)
