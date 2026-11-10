from pathlib import Path
import sys,json,hashlib,struct
R=Path.cwd();sys.path.insert(0,str(R));from roc import match,libs
F=R/'work/2008-06/shared-layouts/sol-vista-native-20261105'
old=R/'work/2008-06/p6-probe-runs/20261105-130705-87b5983d/output/NativeFileSystemFull.obj';new=R/'work/2008-06/native-check-runs/20261105-135237-9f79a3ac/unit-000/candidate.obj';archive=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib';donor=next(b for n,b in libs.archive_members(archive) if Path(n).name=='FileSystem.obj')
def sig(raw):
 secs,syms,defs,starts=match._coff_data_index(raw);out={}
 for n,(start,idx) in defs.items():
  if n.startswith('.'):continue
  sec=secs[idx];end=min([v for v in starts[idx+1] if v>start]+[sec[3]]);data=raw[sec[4]+start:sec[4]+end] if sec[4] else bytes(end-start);rel=[]
  for i in range(sec[7]):
   off,sym,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i)
   if start<=off<end:rel.append((off-start,syms[sym][0],kind))
  out[n]=(data,rel)
 return out
a,b,d=map(sig,[old.read_bytes(),new.read_bytes(),donor]);lost=sorted(a.keys()-b.keys());changed=[n for n in a.keys()&b.keys() if a[n]!=b[n]]
rows=[]
for n in sorted(n for n in a if 'VistaAPIs@' in n):rows.append({'symbol':n,'old_size':len(a[n][0]),'new_size':len(b[n][0]) if n in b else None,'donor_size':len(d[n][0]) if n in d else None,'new_equal':a[n]==b.get(n),'donor_equal':a[n]==d.get(n)})
report={'old':str(old),'new':str(new),'old_sha256':hashlib.sha256(old.read_bytes()).hexdigest(),'new_sha256':hashlib.sha256(new.read_bytes()).hexdigest(),'retained_symbols':len(a.keys()&b.keys()),'changed':changed,'lost':lost,'lost_without_identical_donor':[n for n in lost if a[n]!=d.get(n)],'vista':rows,'status':'FAIL' if changed or any(a[n]!=d.get(n) for n in lost) else 'PENDING_COMDAT','next':'Park native inline strategy on any regression; no flags grid or body rewrite.'}
(F/'comparison.json').write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2))
def selections(raw):
 ptr,count=struct.unpack_from('<II',raw,8);out={};i=0
 while i<count:
  off=ptr+i*18;sec=struct.unpack_from('<h',raw,off+12)[0];storage=raw[off+16];aux=raw[off+17]
  if sec>0 and storage==3 and aux:out[sec-1]=raw[off+18+14]
  i+=1+aux
 return out
raws=[old.read_bytes(),new.read_bytes(),donor];sels=list(map(selections,raws));indexes=[match._coff_data_index(raw)[2] for raw in raws]
for row in rows:
 n=row['symbol']
 for label,ss,defs in zip(['old','new','donor'],sels,indexes):row[label+'_selection']=ss.get(defs[n][1]) if n in defs else None
report['status']='PASS_NO_LOSS_COMDAT' if not changed and not lost and all(row['new_selection']==2 for row in rows) else 'FAIL'
report['next']='Parent isolated direct-object replacement and selected-provider audit; original ABI/EH/runtime gates remain.'
report['retained_bytes']=sum(len(a[n][0]) for n in a.keys()&b.keys());report['all_named_data_and_eh_relocations_equal']=not changed and not lost
(F/'comparison.json').write_text(json.dumps(report,indent=2));print(json.dumps({'status':report['status'],'retained_bytes':report['retained_bytes'],'vista':rows},indent=2))
