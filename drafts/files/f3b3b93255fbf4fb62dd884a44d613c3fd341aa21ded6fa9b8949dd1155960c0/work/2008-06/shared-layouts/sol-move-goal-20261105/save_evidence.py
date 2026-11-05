import json,struct,hashlib
from pathlib import Path
from roc import match
root=Path('work/2008-06/shared-layouts/sol-move-goal-20261105')
run=Path('work/2008-06/native-check-runs/20261105-135158-96093b38')
r=json.loads((run/'results.json').read_text())[0]
b=Path(r['object']).read_bytes(); p,n=struct.unpack_from('<II',b,8); st=p+18*n
syms=[]; i=0
while i<n:
 row=b[p+18*i:p+18*(i+1)]; raw=row[:8]
 if raw[:4]==b'\0'*4:
  off=struct.unpack_from('<I',raw,4)[0]; name=b[st+off:b.index(b'\0',st+off)].decode('ascii')
 else: name=raw.split(b'\0')[0].decode('ascii')
 value,section,typ,storage,aux=struct.unpack_from('<IhHBB',row,8)
 if storage==2: syms.append(dict(name=name,section=section,value=value,type=typ))
 i+=1+aux
inventory=dict(functions=[dict(symbol=x[0],size=len(x[1])) for x in match.coff_functions(b)],externals=syms)
(root/'provider-inventory.json').write_text(json.dumps(inventory,indent=2))
(root/'compile-receipt.json').write_text(json.dumps(r,indent=2))
(root/'proof.json').write_bytes((run/'analysis-06f6a943.json').read_bytes())
handoff=dict(swap_target='CRobloxDoc native diagnostic closure',baseline_receipt='work/2008-06/native-doc-relinks/20261105-134712-a99864f1/result.json',hypothesis='Isolate existing genuine movePrimitivesGoal source: prior mixed-object disassembly showed no instruction differences; prior nonexact label not reproduced.',attempts=1,rejected=0,source=r['source'],source_sha256=r['source_sha256'],object=r['object'],object_sha256=r['object_sha256'],metrics=dict(compiles=1,exact_bodies=1,body_bytes=236,data_bytes=4,direct_calls_verified=2,changed_inputs=0),next_gate='Parent cumulative isolated link with additive object; static local COMDAT selection/data identity and complete ABI/runtime remain separate obligations.',frozen_sources_edited=False,session='6ee04df998ee49e6ad151fb5655dbe1b')
(root/'handoff.json').write_text(json.dumps(handoff,indent=2))
print(json.dumps(inventory,indent=2));print(json.dumps(handoff,indent=2))
