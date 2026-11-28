"""python auto/aliasverify.py: for every func_<X>=NAME line in the alias files quicktest reads, compare the original's code at
X with the code now linked under NAME (first 8 instructions, image addresses/rel32 masked, imports by name).
Writes auto/aliasverify.json {file: [line, orig, ours]} for mismatches."""
import re,json,bisect,pefile,capstone,sys
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
po=pefile.PE('run/RobloxOrig.exe',fast_load=True); pq=pefile.PE('run/RobloxQT.exe',fast_load=True)
for p in (po,pq): p.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
def imps(p): return {i.address:(i.name or b'#%d'%i.ordinal).decode() for e in p.DIRECTORY_ENTRY_IMPORT for i in e.imports}
io,iq=po.get_memory_mapped_image(),pq.get_memory_mapped_image(); mo,mq=imps(po),imps(pq)
addr={};stubaddr=set()
for l in open('linkexp/qt.map',errors='ignore'):
    p=l.split()
    if len(p)>=4 and p[0].startswith('0001:') and re.fullmatch(r'[0-9a-f]{8}',p[2]):
        addr.setdefault(p[1],int(p[2],16))
        if 'stubs' in p[-1]: stubaddr.add(int(p[2],16))
def norm(im,a,imp,n=8):
    out=[]
    for i in md.disasm(im[a-0x400000:a-0x400000+0x80],a):
        s=i.op_str; m=re.search(r'\[(0x[0-9a-f]+)\]',s)
        if m and int(m.group(1),16) in imp: s=s.replace(m.group(0),'['+imp[int(m.group(1),16)]+']')
        if i.mnemonic in('call','jmp') and re.fullmatch(r'0x[0-9a-f]+',s): s='REL'
        s=re.sub(r'0x[0-9a-f]{6,}','X',s); out.append(i.mnemonic+' '+s)
        if i.mnemonic in('ret','int3') or len(out)>=n: break
    return out
src=open('quicktest.py').read()
files=re.findall(r"'(aliases_[a-z0-9_]+\.txt|auto/stub_aliases_[a-z0-9_]+\.txt)'",src)
res={};tot=0
for f in dict.fromkeys(files):
    try: L=open(f).read().splitlines()
    except FileNotFoundError: continue
    for l in L:
        m=re.match(r'func_([0-9a-f]{8})=(\S+)$',l.strip())
        if not m: continue
        x=int(m.group(1),16); t=addr.get(m.group(2))
        if t is None or t in stubaddr or not (0x401000<=x<0x7f0000): continue
        tot+=1
        A=norm(io,x,mo); B=norm(iq,t,mq)
        k=min(len(A),len(B))
        if A[:k]!=B[:k] or not k: res.setdefault(f,[]).append([l.strip()[:160],A[:4],B[:4]])
json.dump(res,open('auto/aliasverify.json','w'),indent=0)
print('checked',tot,'mismatch',sum(len(v) for v in res.values()),{f:len(v) for f,v in res.items()})
