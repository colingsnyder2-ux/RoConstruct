import sys,json,hashlib,struct
from pathlib import Path
R=Path.cwd();sys.path.insert(0,str(R))
from roc import libs,match,rebuild
O=R/'work/2008-06/shared-layouts/sol-serializer-callees-20261105'
sha=lambda b:hashlib.sha256(b).hexdigest()
base=R/'work/2008-06/native-doc-relinks/20261105-145908-8c2e91ac'
inputs=json.loads((base/'inputs.json').read_text()); guards=[];rows=[]
focus={'??0ArchiveBinder@@':'00592940','?resolveRefs@ArchiveBinder@@':'00592720','??1ArchiveBinder@@':'005931e0','?create@?$AbstractFactoryProduct@VInstance@RBX@@@RBX@@':'00420190','?read@Instance@RBX@@':'0055b6f0'}
for path,expected in inputs.items():
 p=Path(path);raw=p.read_bytes();h=sha(raw);guards.append(dict(path=path,expected=expected,actual=h,unchanged=h==expected))
 if p.suffix.lower() not in ('.obj','.lib'):continue
 members=libs.archive_members(p) if p.suffix.lower()=='.lib' else [(None,raw)]
 for member,b in members:
  if not any(s.encode() in b for s in focus):continue
  try:defs=rebuild.coff_externals(b)
  except Exception:continue
  wanted={s:a for s,v in defs.items() if v for pre,a in focus.items() if s.startswith(pre)}
  if not wanted:continue
  secs,syms,funcs,starts=match._coff_data_index(b)
  for s,body,rel in match.coff_functions(b):
   if s not in wanted:continue
   addr=wanted[s];t,tr,_=match.target('2008-06',addr);tm=match.masked(t,set(tr)|set(rel));bm=match.masked(body,set(tr)|set(rel))
   value,sec=funcs[s];sc=secs[sec];rr=[]
   for k in range(sc[7]):
    off,ix,ty=struct.unpack_from('<IIH',b,sc[5]+10*k)
    if value<=off<value+len(body):rr.append(dict(offset=off-value,symbol=syms.get(ix),type=ty,addend=struct.unpack_from('<i',b,sc[4]+off)[0]))
   dc=match.data_check('2008-06',addr,t,match.coff_data_refs(b,s))
   rows.append(dict(path=path,member=member,object_sha256=sha(b),symbol=s,address=addr,target_size=len(t),size=len(body),normalized_exact=match.exact_match(t,tr,body,rel),firstdiff=next((i for i,(x,y) in enumerate(zip(tm,bm)) if x!=y),min(len(tm),len(bm)) if len(tm)!=len(bm) else None),relocations=rr,data_check=dc))
receipt=dict(scope='Read-only five-callee inventory across actual frozen command input objects and all archive members. Availability is not linker selection, ABI, runtime or credit.',command_sha256=sha((base/'command.json').read_bytes()),input_count=len(inputs),guards=guards,original_sha256=sha((R/'clients/2008-06/Roblox.exe').read_bytes()),providers=rows)
(O/'inventory.json').write_text(json.dumps(receipt,indent=2,default=str))
print(json.dumps(dict(inputs=len(inputs),drift=[g for g in guards if not g['unchanged']],providers=[{k:v for k,v in r.items() if k not in ('relocations','data_check')} for r in rows]),indent=2))
