import sys,json,hashlib,struct
from pathlib import Path
sys.path.insert(0,str(Path.cwd()))
from roc import match,libs
out=Path('work/2008-06/shared-layouts/sol-xml-actual-20261105')
sym='?clearValue@XmlNameValuePair@@ABEXXZ'
ip=Path('work/2008-06/native-doc-relinks/20261105-141437-a0617a57/inputs.json')
inputs=json.loads(ip.read_text()); rows=[]; errors=[]; drift=[]; hashes={}
target,tr,_=match.target('2008-06','0057c2d0')
for p,expected in inputs.items():
 path=Path(p); raw=path.read_bytes(); h=hashlib.sha256(raw).hexdigest(); hashes[p]=h
 if h!=expected: drift.append(p)
 if path.suffix.lower() not in ('.obj','.lib'): continue
 members=libs.archive_members(path) if raw.startswith(b'!<arch>\n') else [(None,raw)]
 for member,b in members:
  if sym.encode() not in b: continue
  try: secs,syms,defs,_=match._coff_data_index(b)
  except Exception as e: errors.append([p,member,str(e)]); continue
  definition=sym in defs
  refs=[]
  for si,s in enumerate(secs):
   for i in range(s[7]):
    off,idx,kind=struct.unpack_from('<IIH',b,s[5]+10*i)
    if syms.get(idx,('',))[0]!=sym: continue
    owners=[(n,v) for n,(v,sec) in defs.items() if sec==si and v<=off and syms and any(x[0]==n and x[3]==32 for x in syms.values())]
    start=max((v for n,v in owners),default=-1)
    refs.append(dict(section=si+1,offset=off,kind=kind,owners=[n for n,v in owners if v==start]))
  row=dict(path=p,member=member,sha256=hashlib.sha256(b).hexdigest(),definition=definition,references=refs)
  if definition:
   funcs=[x for x in match.coff_functions(b) if x[0]==sym]
   row['bodies']=[]
   for n,body,rels in funcs:
    mask=set(tr)|set(rels); a=match.masked(target,mask); c=match.masked(body,mask)
    data=match.coff_data_refs(b,n); ok,bad=match.data_check('2008-06','0057c2d0',target,data)
    v,sec=defs[n]; s=secs[sec]; rr=[]
    for k in range(s[7]):
     off,idx,kind=struct.unpack_from('<IIH',b,s[5]+10*k)
     if v<=off<v+len(body): rr.append(dict(offset=off-v,symbol=syms[idx][0],kind=kind,addend=struct.unpack_from('<i',b,s[4]+off)[0]))
    row['bodies'].append(dict(size=len(body),target_size=len(target),exact=match.exact_match(target,tr,body,rels),first_difference=next((i for i in range(min(len(a),len(c))) if a[i]!=c[i]),min(len(a),len(c)) if len(a)!=len(c) else None),data_ok=ok,data_errors=bad,relocations=rr,body_hex=body.hex()))
  rows.append(row)
receipt=dict(inputs_file=str(ip),inputs_sha256=hashlib.sha256(ip.read_bytes()).hexdigest(),input_count=len(inputs),input_hashes=hashes,drift=drift,errors=errors,symbol=sym,rows=rows,selection='unproven: failed link, no selected PE/map')
(out/'actual-provider.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps({k:v for k,v in receipt.items() if k not in ('input_hashes',)},indent=2))
