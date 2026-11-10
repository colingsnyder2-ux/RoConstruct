import sys,json,struct
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import match
out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105';rows=[]
for stem in ['Math','WorldHelpers']:
 a=(root/f'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/{stem}.obj').read_bytes();b=(out/f'{stem}-compile/candidate.obj').read_bytes()
 def data(raw):
  secs,syms,defs,starts=match._coff_data_index(raw); result={}
  for _,(name,start,sec,typ) in syms.items():
   if sec<=0 or typ==32 or name.startswith('.') or not name:continue
   t=secs[sec-1]
   if t[-1]&32:continue
   end=next((v for v in starts[sec] if v>start),t[3]);body=raw[t[4]+start:t[4]+end] if t[4] else bytes(end-start)
   reloc=[]
   for i in range(t[7]):
    off,s,k=struct.unpack_from('<IIH',raw,t[5]+10*i)
    if start<=off<end:reloc.append((off-start,syms[s][0],k))
   result[name]=(body.hex(),reloc)
  return result
 x=data(a);y=data(b);rows.append(dict(member=stem+'.obj',retained_named_data=len(x.keys()&y.keys()),changed=[n for n in x.keys()&y.keys() if x[n]!=y[n]],lost=sorted(x.keys()-y.keys()),added=sorted(y.keys()-x.keys())))
(out/'data-preservation.json').write_text(json.dumps(rows,indent=2));print(json.dumps(rows,indent=2))
