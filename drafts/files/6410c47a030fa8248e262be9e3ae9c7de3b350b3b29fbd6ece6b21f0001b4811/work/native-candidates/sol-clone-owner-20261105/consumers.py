from pathlib import Path
import sys,json,struct,hashlib,bisect
sys.path.insert(0,str(Path.cwd()));from roc import match
out=Path('work/2008-06/shared-layouts/sol-clone-owner-20261105');sha=lambda b:hashlib.sha256(b).hexdigest()
def idx(raw):
 secs,syms,defs,starts=match._coff_data_index(raw);result={}
 for name,(v,si) in defs.items():
  if name.startswith(('.', '$LN')):continue
  sec=secs[si];end=next((x for x in starts[si+1] if x>v),sec[3]);data=raw[sec[4]+v:sec[4]+end] if sec[4] else bytes(end-v);refs=[]
  for j in range(sec[7]):
   off,i,k=struct.unpack_from('<IIH',raw,sec[5]+j*10)
   if v<=off<end:refs.append((off-v,syms[i][0],k))
  result[name]={'size':end-v,'bytes_sha256':sha(data),'relocations':refs,'characteristics':sec[9]}
 return result,secs,syms,defs,starts
def members(raw):
 if raw[:8]!=b'!<arch>\n':yield None,None,raw;return
 off=8;long=b''
 while off+60<=len(raw):
  pos=off;n=int(raw[off+48:off+58]);token=raw[off:off+16].decode().strip();b=raw[off+60:off+60+n];off+=60+n+(n&1)
  if token=='//':long=b
  if b[:2]!=b'\x4c\x01':continue
  name=long[int(token[1:]):].split(b'\0')[0].split(b'/\n')[0].decode() if token.startswith('/') and token[1:].isdigit() else token.rstrip('/')
  yield name,pos,b
old=Path('rebuild/2008-06/out/RbxgsApp/layer-glue/glue_instance_core.obj').read_bytes();a,*_=idx(old);b,*_=idx((out/'unit-000/candidate.obj').read_bytes());removed=a.keys()-b.keys();changed=[k for k in a.keys()&b.keys() if a[k]!=b[k]]
inputs=json.loads(Path('work/2008-06/native-doc-relinks/20261105-141437-a0617a57/inputs.json').read_text());archive=Path('work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib');paths=list(inputs);paths=[str(archive) if p.endswith('RbxgsApp\\linked\\linked.lib') else p for p in paths];audit={k:{'old':a[k],'alternates':[],'consumers':[]} for k in removed};errors=[];drift=[];count=0
for p in paths:
 raw=Path(p).read_bytes()
 if p in inputs and sha(raw)!=inputs[p]:drift.append(p)
 for name,offset,raw in members(raw):
  if raw[:2]!=b'\x4c\x01':continue
  count+=1
  if sha(raw)==sha(old):continue
  try:di,secs,syms,defs,starts=idx(raw)
  except Exception as e:errors.append([p,name,str(e)]);continue
  loc={'path':p,'member':name,'offset':offset,'sha256':sha(raw)}
  for k in removed&di.keys():audit[k]['alternates'].append(dict(loc,raw_identity_equal=di[k]==a[k]))
  for si,sec in enumerate(secs):
   for j in range(sec[7]):
    off,i,kind=struct.unpack_from('<IIH',raw,sec[5]+j*10);symbol=syms[i][0]
    if symbol in audit:audit[symbol]['consumers'].append(dict(loc,section=si,offset=off,kind=kind,owners=[k for k,(v,s) in defs.items() if s==si and v==max([v for v in starts[si+1] if v<=off],default=-1)]))
no_exact=[k for k,v in audit.items() if v['consumers'] and not any(x['raw_identity_equal'] for x in v['alternates'])];result={'input_count':len(paths),'coff_count':count,'drift':drift,'errors':errors,'retained_changed':changed,'retained_unchanged':len(a.keys()&b.keys())-len(changed),'removed_count':len(removed),'consumed_without_raw_identical_alternate':no_exact,'symbols':audit,'scope':'current329 inputs, cumulative archive substituted for original RbxgsApp; alternate identity covers bytes and relocations, not transitive ABI or selection'};(out/'consumer-audit.json').write_text(json.dumps(result,indent=2));print(json.dumps({k:v for k,v in result.items() if k!='symbols'},indent=2))

