import sys,json,struct,hashlib
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import match
out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105'
def bodies(p):
 raw=p.read_bytes();secs,syms,defs,_=match._coff_data_index(raw);result={}
 for name,body,rels in match.coff_functions(raw):
  start,sec=defs[name];t=secs[sec]; bindings=[]
  for i in range(t[7]):
   off,s,k=struct.unpack_from('<IIH',raw,t[5]+10*i);off-=start
   if 0<=off<len(body):bindings.append((off,syms[s][0],k))
  result[name]=(body.hex(),bindings)
 return result
rows=[]
for stem in ['Math','WorldHelpers']:
 old=root/f'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/{stem}.obj';new=out/f'{stem}-compile/candidate.obj';a=bodies(old);b=bodies(new)
 rows.append(dict(member=stem+'.obj',original_object=str(old),original_sha256=hashlib.sha256(old.read_bytes()).hexdigest(),replacement=str(new),replacement_sha256=hashlib.sha256(new.read_bytes()).hexdigest(),retained=len(a.keys()&b.keys()),changed=[n for n in a.keys()&b.keys() if a[n]!=b[n]],lost=sorted(a.keys()-b.keys()),added=sorted(b.keys()-a.keys())))
(out/'preservation.json').write_text(json.dumps(rows,indent=2));print(json.dumps(rows,indent=2))
