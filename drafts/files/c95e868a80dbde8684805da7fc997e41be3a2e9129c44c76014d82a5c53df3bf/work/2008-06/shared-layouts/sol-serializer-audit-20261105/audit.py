import json,struct,hashlib,difflib,re
from pathlib import Path
from collections import defaultdict
OUT=Path('work/2008-06/shared-layouts/sol-serializer-audit-20261105'); OLD=Path('work/2008-06/shared-layouts/sol-serializer-owner-20261105')
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
manifest=json.loads(Path('work/2008-06/native-doc-relinks/20261105-145908-8c2e91ac/inputs.json').read_text()); archive=Path('work/2008-06/shared-layouts/sol-clone-owner-20261105/linked.lib'); ab=archive.read_bytes(); mm=members(ab); target=[m for m in mm if m[0]=='glue_serializer.obj'];assert len(target)==1
n,off,ob=target[0];nb=(OLD/'unit-000/candidate.obj').read_bytes();assert H(ob)=='242d36b8806d7843d65eb3c37dbea60e40e288cca3549a3255fe6d4920d4418b';assert H(nb)=='410f7416ff2ab4dd10ca8c608affa2637efcfbad04cee7ac8c7e160f6e0ec58f';assert H(ab)=='3a0490de7239801417a5ae524ed5e54fd5301cf77a7b5cd88d170e8431a1fcbe'
save('members.json',[{'name':n,'header_offset':o,'size':len(b),'sha256':H(b)} for n,o,b in mm]);old=bodies(coff(ob));new=bodies(coff(nb));removed=set(old)-set(new);changed={n:{'old':old[n],'new':new[n]} for n in old.keys()&new.keys() if old[n]!=new[n]};save('retained-changes.json',changed)
cons=defaultdict(list);alts=defaultdict(list);drift=[];errors=[];objects=[];imports=0
for p,expected in manifest.items():
 try:
  b=Path(p).read_bytes()
  if H(b)!=expected:drift.append(p)
  for mn,mo,mb in members(b):
   ident={'input':p,'member':mn,'offset':mo,'sha256':H(mb)}
   if p==str(archive.resolve()) and mo==off:continue
   try: obj=coff(mb)
   except Exception as e:errors.append([ident,str(e)]);continue
   if obj is None:imports+=1;continue
   oid=len(objects);objects.append(ident);sy,secs=obj;bd=bodies(obj)
   for name in removed & bd.keys():alts[name].append({'object_id':oid,'strict_equal':bd[name]==old[name],'identity':bd[name]})
   for sec,(sn,raw,rels,ch) in secs.items():
    if sn.startswith('.debug'):continue
    for ro,rn,rt in rels:
     if rn in removed:cons[rn].append({'object_id':oid,'section':sec,'section_name':sn,'offset':ro,'type':rt})
 except Exception as e:errors.append([p,str(e)])
# Candidate retained bodies are consumers too.
for sec,(sn,raw,rels,ch) in coff(nb)[1].items():
 if sn.startswith('.debug'):continue
 for ro,rn,rt in rels:
  if rn in removed:cons[rn].append({'object_id':'candidate','section':sec,'section_name':sn,'offset':ro,'type':rt})
missing=sorted(n for n in removed if cons[n] and not any(a['strict_equal'] for a in alts[n]));save('consumers.json',{'objects':objects,'removed':{n:{'old':old[n],'consumers':cons[n],'alternates':alts[n]} for n in sorted(removed)}})
a=json.loads((OLD/'actual-command.json').read_text());r=json.loads((OLD/'unit-000/receipt.json').read_text());e=json.loads((OLD/'executed-command.json').read_text());deps=[]
for p,h in a['dependencies'].items():
 if not Path(p).exists() or H(Path(p).read_bytes())!=h:deps.append(p)
src=Path(r['source']).read_text();original=Path(a['source']).read_text();save('source-diff.json',list(difflib.unified_diff(original.splitlines(),src.splitlines())))
includes=re.findall(r'^\s*#\s*include\s*[<"]([^>"\n]+)[>"]',src,re.M);dirs=[Path(r['source']).parent]+[Path(f[2:]) for f in e['command'] if f.startswith('/I')]+[Path(x) for x in e['environment']['INCLUDE'].split(';')];resolution={tok:[str(d/tok) for d in dirs if (d/tok).exists()] for tok in includes}
save('provenance.json',{'actual_command_sha256':H((OLD/'actual-command.json').read_bytes()),'executed_command_sha256':H((OLD/'executed-command.json').read_bytes()),'source_sha256':H(Path(r['source']).read_bytes()),'original_source_hash_verified':H(Path(a['source']).read_bytes())==a['source_sha256'],'dependencies_count':len(a['dependencies']),'dependencies_drift':deps,'include_order':[str(d) for d in dirs],'direct_include_candidates':resolution,'limitation':'Saved executed-command lists /showIncludes but adapter omitted it. Current include resolution is evidence of present candidates only; actual new transitive include provenance unknown. No exact argument replay claim.'})
summary={'status':'NEGATIVE_PARK' if changed or missing or drift or errors else 'STRICT_PASS','input_count':len(manifest),'manifest_sha256':H(Path('work/2008-06/native-doc-relinks/20261105-145908-8c2e91ac/inputs.json').read_bytes()),'archive_sha256':H(ab),'member_count':len(mm),'old_member_header_offset':off,'old_member_sha256':H(ob),'candidate_sha256':H(nb),'coff_count':len(objects),'short_import_count':imports,'drift':drift,'errors':errors,'retained_unchanged':len(old.keys()&new.keys())-len(changed),'retained_changed':list(changed),'removed_named_definitions':len(removed),'consumed_without_strict_alternate':missing,'no_compiles':True,'no_archive_mutation':True};save('summary.json',summary);print(json.dumps(summary))
