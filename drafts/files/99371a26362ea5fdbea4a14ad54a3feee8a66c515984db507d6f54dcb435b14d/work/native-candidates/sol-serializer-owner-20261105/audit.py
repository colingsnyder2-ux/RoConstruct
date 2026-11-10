from pathlib import Path
import sys,json,hashlib,struct
sys.path.insert(0,str(Path.cwd()));from roc import match
out=Path('work/2008-06/shared-layouts/sol-serializer-owner-20261105')
def index(b):
 secs,syms,defs,starts=match._coff_data_index(b);result={}
 for name,(v,si) in defs.items():
  sec=secs[si];data=b[sec[4]:sec[4]+sec[3]];refs=[]
  for j in range(sec[7]):
   off,idx,kind=struct.unpack_from('<IIH',b,sec[5]+j*10);refs.append((off,syms[idx][0],kind))
  result[name]={'value':v,'bytes':data.hex(),'relocations':refs,'characteristics':sec[9]}
 return result
old=Path('rebuild/2008-06/out/RbxgsApp/layer-glue/glue_serializer.obj').read_bytes();new=(out/'unit-000/candidate.obj').read_bytes();a=index(old);b=index(new);removed=sorted(a.keys()-b.keys());changed=sorted(k for k in a.keys()&b.keys() if a[k]!=b[k]);added=sorted(b.keys()-a.keys());d={'old_sha256':hashlib.sha256(old).hexdigest(),'new_sha256':hashlib.sha256(new).hexdigest(),'removed':removed,'changed':changed,'added':added,'unchanged':len(a.keys()&b.keys())-len(changed),'removed_identity':{k:a[k] for k in removed},'changed_identity':{k:{'old':a[k],'new':b[k]} for k in changed}}
(out/'retention.json').write_text(json.dumps(d,indent=2));print(json.dumps({k:v for k,v in d.items() if 'identity' not in k},indent=2))
