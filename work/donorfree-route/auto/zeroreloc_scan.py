import sys,struct,re,collections,json; sys.path.insert(0,'../..')
from pathlib import Path
import pefile
H=Path('.')
src=Path('codematch.py').read_text(encoding='latin-1')
exec(compile(src[src.index('def relsyms'):src.index('def orig_names')],'r','exec'))
img=pefile.PE('../../clients/2008-06/Roblox.exe',fast_load=True).get_memory_mapped_image(); B=0x400000
RR=json.loads(Path('renamed/rename.json').read_text())
hits=collections.Counter(); ex={}; plan={}
for o in Path('renamed/obj').glob('*.obj'):
    X=o.stem
    if not re.fullmatch('[0-9a-f]{8}',X): continue
    x=int(X,16)
    try: rs=relsyms(o.read_bytes())
    except Exception: continue
    body=rs.get('func_'+X) or rs.get((RR.get(X) or {}).get('symbol') or '')
    if not body: continue
    for off,s in body.items():
        if x-B+off+4>len(img) or off<0: continue
        v=struct.unpack_from('<I',img,x-B+off)[0]
        if v==0 and not s.startswith('__imp_') :
            hits[s]+=1; ex.setdefault(s,X); plan.setdefault(X,[]).append(off)
print(sum(hits.values()), len(plan))
for s,n in hits.most_common(15): print(n,ex[s],s[:90])
json.dump(plan,open('auto/zeroreloc_plan.json','w'))
