"""python auto/vtcode.py: code-level vtable audit. For every vtable vtaudit.json pairs with an original vtable, compare
each slot's TARGET CODE (orig slot target vs our slot target; first 6 instructions, image addresses/rel32 masked,
imports by name/ordinal). Catches wrong bindings that an address-level audit misses because both sides resolve
through the same wrong alias (XTP InplaceEdit::SetValue -> ~thread_resource_error). Writes auto/vtcode.json."""
import json,re,struct,bisect,pefile,capstone
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
po=pefile.PE('run/RobloxOrig.exe',fast_load=True); import os; pq=pefile.PE(os.environ.get('VC_EXE','run/RobloxQT.exe'),fast_load=True)
for p in (po,pq): p.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
def imps(p): return {i.address:(e.dll.decode().lower()+':'+((i.name or b'').decode() or '#%d'%i.ordinal)) for e in p.DIRECTORY_ENTRY_IMPORT for i in e.imports}
io,iq=po.get_memory_mapped_image(),pq.get_memory_mapped_image(); mo,mq=imps(po),imps(pq)
vt={};rows=[]
for l in open(os.environ.get('VC_MAP','linkexp/qt.map'),errors='ignore'):
    p=l.split()
    if len(p)>=4 and re.fullmatch(r'[0-9a-f]{8}',p[2]):
        a=int(p[2],16)
        if p[1].startswith('??_7'): vt.setdefault(p[1],a)
        if p[0].startswith('0001:'): rows.append((a,p[1]))
rows.sort(); ks=[r[0] for r in rows]
def nm(v):
    j=bisect.bisect_right(ks,v)-1
    return rows[j][1][:90] if j>=0 and ks[j]==v else hex(v)
def code(im,a,imp,lo,hi):
    if not (lo<=a<hi): return None
    out=[]
    for i in md.disasm(im[a-0x400000:a-0x400000+0x60],a):
        s=i.op_str; m=re.search(r'\[(0x[0-9a-f]+)\]',s)
        if m and int(m.group(1),16) in imp: s='[IMP:'+imp[int(m.group(1),16)].split(':')[0]+']'
        if i.mnemonic in('call','jmp') and re.fullmatch(r'0x[0-9a-f]+',s): s='REL'
        s=re.sub(r'0x[0-9a-f]{5,}','X',s); out.append(i.mnemonic+' '+s)
        if i.mnemonic in('ret','int3','jmp') or len(out)>=6: break
    return out
def thunkimp(im,a,imp):
    # jmp [IAT] import thunk -> import name (ours resolves imports through thunks too)
    if im[a-0x400000:a-0x400000+2]==b'\xff\x25': return imp.get(struct.unpack_from('<I',im,a-0x400000+2)[0])
aud=json.load(open('auto/vtaudit.json'))
bad=[];n=0
for name,v in aud.items():
    if name not in vt or not v.get('orig'): continue
    o=int(v['orig'],16); q=vt[name]
    for i in range(v.get('orig_slots',0)):
        so=struct.unpack_from('<I',io,o-0x400000+4*i)[0]; sq=struct.unpack_from('<I',iq,q-0x400000+4*i)[0]
        if not (0x401000<=so<0x7f0000): continue
        n+=1
        ti,tq=thunkimp(io,so,mo),thunkimp(iq,sq,mq)
        if ti or tq:
            if ti and tq and ti.split(':')[0]==tq.split(':')[0]: continue
        A=code(io,so,mo,0x401000,0x7f0000); B=code(iq,sq,mq,0x401000,0x1300000)
        if A is None or B is None: continue
        f=lambda s: re.sub(r'\[IMP:[^\]]*\]','[IMP]',s)
        k=min(len(A),len(B))
        if [f(x) for x in A[:k]]==[f(x) for x in B[:k]]: continue
        # different first instruction KIND only (ignore regalloc/EH-prolog order noise): mnemonic multiset of first 3
        if sorted(x.split()[0] for x in A[:3])==sorted(x.split()[0] for x in B[:3]): continue
        bad.append({'vt':name[:110],'slot':i,'orig':'%08x'%so,'ours':nm(sq),'o':A[:4],'q':B[:4]})
json.dump(bad,open('auto/vtcode.json','w'),indent=0)
print('slots compared',n,'suspicious',len(bad))
import collections
print(collections.Counter(b['ours'] for b in bad).most_common(25))
