import json,struct,hashlib,difflib,re
from pathlib import Path
from collections import defaultdict
OUT=Path('work/2008-06/shared-layouts/sol-archive-resolve-owner-20261105'); OLD=Path('work/2008-06/shared-layouts/sol-serializer-owner-20261105')
H=lambda b:hashlib.sha256(b).hexdigest()
def save(n,v): (OUT/n).write_text(json.dumps(v,indent=2))
def members(b):
 if not b.startswith(b'!<arch>\n'): return [(None,None,b)]
 out=[];p=8;names=b''
 while p<len(b):
  hdr=b[p:p+60]; assert hdr[58:60]==b'`\n'; n=hdr[:16].decode().strip(); size=int(hdr[48:58]); data=b[p+60:p+60+size]
  if n=='//': names=data
  elif n not in ['/','/SYM64/']:
   if n.startswith('/') and n[1:].isdigit(): n=names[int(n[1:]):].split(b'\0')[0].decode().rstrip('/')
   else:n=n.rstrip('/')
   out.append((n,p,data))
  p+=60+size+(size&1)
 return out
def coff(b):
 if b[:4]==b'\0\0\xff\xff':return None
 if len(b)<20 or struct.unpack_from('<H',b)[0]!=0x14c:raise ValueError('unsupported COFF')
 _,ns,_,ps,nt,op,_=struct.unpack_from('<HHIIIHH',b); st=b[ps+nt*18:]; sy={};i=0
 def name(x):
  if x[:4]==b'\0'*4:return st[struct.unpack_from('<I',x,4)[0]:].split(b'\0')[0].decode(errors='replace')
  return x.split(b'\0')[0].decode(errors='replace')
 while i<nt:
  x=b[ps+i*18:ps+(i+1)*18]; v,s,t,c,a=struct.unpack_from('<IhHBB',x,8);sy[i]=(name(x[:8]),v,s,t,c);i+=1+a
 secs={}
 for j in range(ns):
  x=b[20+op+j*40:20+op+(j+1)*40]; n=name(x[:8]); size,ptr,rp=struct.unpack_from('<III',x,16);nr=struct.unpack_from('<H',x,32)[0];ch=struct.unpack_from('<I',x,36)[0]
  raw=bytes(size) if ch&0x80 and not ptr else b[ptr:ptr+size]; assert len(raw)==size
  rel=[]
  for k in range(nr):
   off,idx,typ=struct.unpack_from('<IIH',b,rp+k*10);rel.append((off,sy[idx][0],typ))
  secs[j+1]=(n,raw,rel,ch)
 return sy,secs
def bodies(obj):
 sy,secs=obj;out={}
 for n,v,s,t,c in sy.values():
  if s<=0 or n.startswith('.') or c==103:continue
  sec,raw,rel,ch=secs[s]
  if sec.startswith('.debug'):continue
  starts=sorted({v2 for n2,v2,s2,t2,c2 in sy.values() if s2==s and v2>v and not n2.startswith('.')}); end=starts[0] if starts else len(raw)
  rr=[(off-v,target,typ) for off,target,typ in rel if v<=off<end]
  out[n]={'size':end-v,'sha256':H(raw[v:end]),'relocations':rr,'characteristics':ch,'storage':c,'section':sec}
 return out
manifest=json.loads(Path('work/2008-06/native-doc-relinks/20261105-145908-8c2e91ac/inputs.json').read_text()); archive=Path('work/2008-06/shared-layouts/sol-clone-owner-20261105/linked.lib');ab=archive.read_bytes();mm=members(ab);target=[m for m in mm if m[0]=='SerializerV2.obj'];assert len(target)==1
n,off,ob=target[0];nb=(OUT/'unit-000/candidate.obj').read_bytes();old=bodies(coff(ob));new=bodies(coff(nb));removed=set(old)-set(new);changed={n:{'old':old[n],'new':new[n]} for n in old.keys()&new.keys() if old[n]!=new[n]};save('retained-changes.json',changed);save('members.json',[dict(name=n,offset=o,sha256=H(b)) for n,o,b in mm])
cons=defaultdict(list);alts=defaultdict(list);drift=[];errors=[];objects=[];imports=0
for p,expected in manifest.items():
 b=Path(p).read_bytes()
 if H(b)!=expected:drift.append(p)
 for mn,mo,mb in members(b):
  ident=dict(input=p,member=mn,offset=mo,sha256=H(mb))
  if p==str(archive.resolve()) and mo==off:continue
  try:obj=coff(mb)
  except Exception as e:errors.append([ident,str(e)]);continue
  if obj is None:imports+=1;continue
  oid=len(objects);objects.append(ident);sy,secs=obj;bd=bodies(obj)
  for name in removed & bd.keys():alts[name].append(dict(object_id=oid,strict_equal=bd[name]==old[name]))
  for sec,(sn,raw,rels,ch) in secs.items():
   if sn.startswith('.debug'):continue
   for ro,rn,rt in rels:
    if rn in removed:cons[rn].append(dict(object_id=oid,section=sec,offset=ro,type=rt,addend=int.from_bytes(raw[ro:ro+4],'little')))
for sec,(sn,raw,rels,ch) in coff(nb)[1].items():
 if sn.startswith('.debug'):continue
 for ro,rn,rt in rels:
  if rn in removed:cons[rn].append(dict(object_id='candidate',section=sec,offset=ro,type=rt,addend=int.from_bytes(raw[ro:ro+4],'little')))
missing=sorted(n for n in removed if cons[n] and not any(a['strict_equal'] for a in alts[n]));save('consumers.json',dict(objects=objects,removed={n:dict(old=old[n],consumers=cons[n],alternates=alts[n]) for n in sorted(removed)}))
resolve='?resolveRefs@ArchiveBinder@@UAE_NXZ';vt='??_7ArchiveBinder@@6B@';vt_equal=old.get(vt)==new.get(vt);undefined=any(n==resolve and sec==0 for n,v,sec,t,c in coff(nb)[0].values())
r=json.loads((OUT/'unit-000/receipt.json').read_text());depdrift=[p for p,h in r['dependencies'].items() if H(Path(p).read_bytes())!=h]
summary=dict(status='NEGATIVE_PARK' if changed or drift or depdrift or not vt_equal or not undefined or any(n!=resolve for n in missing) else 'CONDITIONAL_PASS',archive_sha256=H(ab),old_member_header_offset=off,old_member_sha256=H(ob),candidate_sha256=H(nb),retained_unchanged=len(old.keys()&new.keys())-len(changed),retained_changed=list(changed),removed_named_definitions=len(removed),missing_strict_alternates=missing,vtable_identical=vt_equal,resolve_undefined=undefined,input_count=len(manifest),drift=drift,candidate_dependency_drift=depdrift,non_coff_inputs=errors,condition='Independent native resolveRefs exact provider, parent cumulative composition and all ABI/selection/runtime gates remain required',compile_count=1)
save('summary.json',summary);print(json.dumps(summary,indent=2))
