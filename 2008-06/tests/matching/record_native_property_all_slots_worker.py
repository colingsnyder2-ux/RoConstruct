import json,sys,hashlib,struct
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match
rc=json.loads((root/'work/2008-06/shared-layouts/history-property-trial.json').read_text());paths=[root/'rebuild/2008-06/out/property-abi-trial/NativeParentDescriptorTrial.obj',root/'rebuild/2008-06/out/property-abi-trial/NativeParentVariantTrial.obj'];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(paths[0])==rc['fixture_object_sha256'] and sha(paths[1])==rc['variant_object_sha256'];functions={n:(b,r) for p in paths for n,b,r in match.coff_functions(p.read_bytes())};rows=[]
for k,name in sorted(rc['candidate_slots'].items(),key=lambda x:int(x[0])):
 i=int(k);addr=int(rc['original_slots'][i],16);row={'slot':i,'offset':hex(i*4),'candidate_symbol':name,'original':hex(addr)}
 if name in functions:
  b,r=functions[name];t,tr,_=match.target('2008-06','%08x'%addr);row.update(candidate_size=len(b),original_size=len(t),exact=match.exact_match(t,tr,b,r))
 else:row['status']='candidate body not in either fixture object'
 rows.append(row)
res={'scope':'Inactive existing typed fixtures hash-checked and compared against original Parent RefPropDescriptor slots. Absent body is not proof of mismatch. Exact bytes mask relocations and do not establish linked provider/runtime ABI.','vtable':'0x82d768','slots':rows,'fixture_sha256':[sha(p) for p in paths]};(root/'work/2008-06/shared-layouts/property-all-slots-worker.json').write_text(json.dumps(res,indent=2)+'\n');print(json.dumps(rows,indent=2))
