from pathlib import Path
import sys,json,hashlib,struct,subprocess,os
from collections import Counter
R=Path.cwd();sys.path.insert(0,str(R));from roc import match,libs
F=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(n,v):(F/n).write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8')
archive=R/'work/2008-06/shared-layouts/sol-cumulative-links-20261105/member-step-1/linked.lib';ah=sha(archive);assert ah=='8ef9dbeb5d4f5bc7699aa28e662638e286e431086b5b6a0229aaa1237ca1d580'
ms=list(libs.archive_members(archive));name,old=next((n,b) for n,b in ms if Path(n).name=='FileSystem.obj');new=(F/'FileSystem.obj').read_bytes();native=R/'work/2008-06/p6-probe-runs/20261105-130705-87b5983d/output/NativeFileSystemFull.obj';nr=native.read_bytes()
def signatures(raw):
 secs,syms,defs,starts=match._coff_data_index(raw);out={}
 for n,(start,idx) in defs.items():
  if n.startswith('.'):continue
  sec=secs[idx];end=min([v for v in starts[idx+1] if v>start]+[sec[3]]);data=raw[sec[4]+start:sec[4]+end] if sec[4] else bytes(end-start)
  rel=[]
  for i in range(sec[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i)
   if start<=off<end:rel.append((off-start,syms[sym][0],kind))
  out[n]=(data,rel)
 return out
a,b=signatures(old),signatures(new);lost=set(a)-set(b);changed=[n for n in a.keys()&b.keys() if a[n]!=b[n]];save('symbol-comparison.json',{'retained':len(a.keys()&b.keys()),'changed':changed,'lost':sorted(lost),'new':sorted(b.keys()-a.keys())});print('changed symbols',changed)
# Full explicit link inputs, including both prepended Axis candidate objects.
inputs=json.loads((R/'work/2008-06/native-doc-relinks/20261105-132212-105c59ff/inputs.json').read_text());inventory=[];consumers=[];providers={};count=0
for p,h in inputs.items():
 path=Path(p);assert sha(path)==h,(p,'input drift');inventory.append({'path':p,'sha256':h})
 objects=list(libs.archive_members(path)) if path.suffix.lower()=='.lib' else [(str(path),path.read_bytes())] if path.suffix.lower()=='.obj' else []
 for member,raw in objects:
  if path==archive and member==name:raw=new
  try:secs,syms,defs,_=match._coff_data_index(raw)
  except (struct.error,IndexError,ValueError):continue
  count+=1
  for n in lost&set(defs):providers.setdefault(n,[]).append(p+'('+member+')')
  used=set()
  for sec in secs:
   for i in range(sec[7]):
    off,idx,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i);n=syms[idx][0]
    if n in lost:used.add(n)
  if used:consumers.append({'input':p,'member':member,'symbols':sorted(used)})
used=set(n for row in consumers for n in row['symbols']);missing=used-set(providers);save('consumer-audit.json',{'inputs':inventory,'objects':count,'consumers':consumers,'providers':providers,'referenced_without_provider':sorted(missing)});assert not missing
# Existing selected native body vs original, independently evaluated now.
proof=[];nf={n:(v,r) for n,v,r in match.coff_functions(nr)}
for prefix,addr in [('?GetIntegrity@VistaAPIs','005a7780'),('?getUserAppDataDirectory@FileSystem','005a7ac0')]:
 n=next(n for n in nf if n.startswith(prefix));body,refs=nf[n];target,tr,_=match.target('2008-06',addr);exact=match.exact_match(target,tr,body,refs) and set(tr)<=set(refs);dm,de=match.data_check('2008-06',addr,target,match.coff_data_refs(nr,n));proof.append({'symbol':n,'address':addr,'size':len(body),'exact':exact,'data_errors':de});assert exact and not de
save('native-proof.json',{'object':str(native),'sha256':sha(native),'checks':proof,'limitation':'Indirect calls, EH graph and original standalone ctor/dtor/wrapper contracts require separate proof; no runtime/gate claim.'})
c=json.loads((F/'compile-command.json').read_text());tool=Path(c['compiler']).with_name('lib.exe');args=['/nologo','/OUT:'+str(F/'linked.lib'),str(archive),'FileSystem.obj'];env=os.environ.copy();env['PATH']=str(tool.parents[2]/'Common7/IDE')+os.pathsep+str(tool.parent)+os.pathsep+env.get('PATH','');save('librarian-command.json',{'tool':str(tool),'sha256':sha(tool),'args':args,'cwd':str(F)})
p=subprocess.run([str(tool),*args],cwd=F,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);(F/'librarian.log').write_text(p.stdout.decode(errors='replace'));assert p.returncode==0
inv=lambda seq:Counter((n,hashlib.sha256(raw).hexdigest()) for n,raw in seq)
before=inv(ms);after=inv(libs.archive_members(F/'linked.lib'));assert list((before-after).elements())==[(name,hashlib.sha256(old).hexdigest())];assert list((after-before).elements())==[(name,sha(F/'FileSystem.obj'))];assert sha(archive)==ah
save('replacement.json',{'base_archive':str(archive),'base_sha256':ah,'private_archive_sha256':sha(F/'linked.lib'),'member':name,'object_sha256':sha(F/'FileSystem.obj'),'unchanged_other_members':len(ms)-1,'normal_librarian':True,'state':'PROPOSAL pending original call/EH/standalone contract review and parent isolated link','missing_providers':sorted(missing)})
print('PASS',count,'input objects;',len(ms)-1,'other archive members unchanged')
