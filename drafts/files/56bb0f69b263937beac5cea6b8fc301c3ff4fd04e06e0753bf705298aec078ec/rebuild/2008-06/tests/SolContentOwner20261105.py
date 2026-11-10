from pathlib import Path
import sys,json,hashlib,os,subprocess,struct
ROOT=Path.cwd(); sys.path.insert(0,str(ROOT)); sys.path.insert(0,str(ROOT/'rebuild/2008-06/p6'))
from roc import match,libs
from script_context_owner import references,data_symbols
F=ROOT/'work/2008-06/shared-layouts/sol-content-owner-20261105'; V=ROOT/'work/native-candidates/sol-content-owner-20261105'
F.mkdir(parents=True,exist_ok=True); V.mkdir(parents=True,exist_ok=True)
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(n,v): (F/n).write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8')
cp=ROOT/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/ContentProvider.command.json'; c=json.loads(cp.read_text()); src=Path(c['source']); obj=cp.with_name('ContentProvider.obj')
inputs={str(src):c['source_sha256'],**c['dependencies'],str(cp):sha(cp),str(obj):sha(obj),c['compiler']:sha(c['compiler'])}
def guard():
 bad=[p for p,h in inputs.items() if not Path(p).is_file() or sha(p)!=h]
 assert not bad,bad
 guard_dummy=None
guard(); save('canonical-command.json',c); save('frozen-inputs.json',inputs)
text=src.read_text(); sig='void ContentProvider::load(ContentId id, std::vector<boost::shared_ptr<Instance>>& instances)'; assert text.count(sig)==1
variant=V/'ContentProvider.cpp'; variant.write_text(text.replace(sig,'inline '+sig),encoding='utf-8')
args=[a for a in c['args'] if not a.lower().startswith('/fo') and a!=c['source']]+['/Fo'+str(F/'ContentProvider.obj'),str(variant)]
save('replay-command.json',dict(compiler=c['compiler'],args=args,cwd=str(ROOT),environment=c['environment'],variant_sha256=sha(variant)))
env=os.environ.copy(); env.update(c['environment']); env['PATH']=str(Path(c['compiler']).parents[2]/'Common7/IDE')+os.pathsep+str(Path(c['compiler']).parent)+os.pathsep+env.get('PATH','')
assert not (F/'ContentProvider.obj').exists(),'already compiled; reuse object'
p=subprocess.run([c['compiler'],*args],cwd=ROOT,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
(F/'compile.log').write_text(p.stdout.decode(errors='replace'),encoding='utf-8'); save('compile.json',{'exit':p.returncode,'distinct_compiles':1}); assert p.returncode==0,p.stdout[-2000:]; guard()
a_raw=obj.read_bytes(); b_raw=(F/'ContentProvider.obj').read_bytes()
a={n:(b,r) for n,b,r in match.coff_functions(a_raw)}; b={n:(v,r) for n,v,r in match.coff_functions(b_raw)}; common=set(a)&set(b); removed=set(a)-set(b)
ra,rb=references(a_raw),references(b_raw); da,db=data_symbols(a_raw),data_symbols(b_raw)
result=dict(retained_bodies=len(common),removed_bodies=sorted(removed),added_bodies=sorted(set(b)-set(a)),body_differences=[n for n in common if a[n]!=b[n]],relocation_differences=[n for n in common if ra[n]!=rb[n]],retained_named_data=len(set(da)&set(db)),removed_data=sorted(set(da)-set(db)),added_data=sorted(set(db)-set(da)),data_differences=[n for n in set(da)&set(db) if da[n]!=db[n]],baseline_object_sha256=sha(obj),candidate_object_sha256=sha(F/'ContentProvider.obj'))
save('comparison.json',result)
# Scan available current module objects only. Absence is explicitly partial coverage.
names=removed|(set(da)-set(db)); rows=[]; inventory=[]
for path in sorted((ROOT/'rebuild/2008-06/out').rglob('*.obj')):
 if path==obj: continue
 raw=path.read_bytes()
 try: sections,symbols,defs,_=match._coff_data_index(raw)
 except Exception: continue
 hits=[]
 for sec in sections:
  for i in range(sec[7]):
   off,idx,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i); name=symbols[idx][0]
   if name in names: hits.append(dict(symbol=name,offset=off,kind=kind,defined_here=name in defs))
 inventory.append(dict(path=str(path),sha256=hashlib.sha256(raw).hexdigest()))
 if hits: rows.append(dict(path=str(path),references=hits))
save('external-consumers.json',dict(scope='PARTIAL current out objects only; no complete archive/input manifest available; references may bind same-named alternate providers',objects=len(inventory),inventory=inventory,consumers=rows))
save('campaign.json',dict(swap_target='CRobloxDoc native diagnostic closure',session='43b8fd99b7fd47b0862a8e25fb0015f9',status='inactive source-owner proposal',canonical_command_sha256=sha(cp),inputs_unchanged=True,metrics={k:v for k,v in result.items() if isinstance(v,int)},next_gate='Complete current link input/archive manifest; classify removed-symbol consumers and alternate providers; normal librarian replacement with all other member bytes unchanged; selected diagnostic link remains parent-owned',activation=False,server_credit=0))
guard(); print(json.dumps({k:v for k,v in result.items() if k not in ('removed_bodies','removed_data')},indent=2)); print('consumer objects',len(rows),'scanned',len(inventory))
