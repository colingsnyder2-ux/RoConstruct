import json, struct, hashlib
from pathlib import Path
from roc import match
D=Path('work/2008-06/shared-layouts/sol-doc-provider-20261105')
R=Path('work/2008-06/native-check-runs/20261105-133434-0c8c15a8')
rows=json.loads((R/'results.json').read_text())
manifest=json.loads((D/'batch.json').read_text())
# Targets independently reviewed in original assembly; symbols checked against native declarations.
expected=[{40:'00557330',48:'0048a460',114:'004124c0',160:'00557330',168:'00489c30',181:'00572a90',214:'00600660',277:'004025b0',294:'00600660'}, {92:'00403040',119:'004025b0',208:'00403040',283:'00456e80',472:'005e9340'}]
inventory=[]
for n,row in enumerate(rows):
 raw=Path(row['object']).read_bytes(); secs,syms,defs,_=match._coff_data_index(raw)
 name=row['checks'][0]['symbol']; start,idx=defs[name]; tab=secs[idx]; rel={}
 for i in range(tab[7]):
  off,sym,kind=struct.unpack_from('<IIH',raw,tab[5]+10*i)
  if kind==20 and start<=off<start+row['checks'][0]['object_size']: rel[off-start-1]=syms[sym][0]
 assert set(rel)==set(expected[n])
 manifest['jobs'][n]['checks'][0]['calls']=[dict(offset=o,target=t,symbol=rel[o]) for o,t in expected[n].items()]
 inventory.append({k:row[k] for k in ('source','source_sha256','object','object_sha256','dependencies','checks')})
(D/'reviewed-checks.json').write_text(json.dumps(manifest,indent=2))
(D/'provider-inventory.json').write_text(json.dumps(inventory,indent=2))
(D/'campaign.json').write_text(json.dumps(dict(swap_target='CRobloxDoc diagnostic closure',baseline_receipt='work/2008-06/native-doc-relinks/20261105-133112-e038d1b8/result.json',baseline_commit='package e9bfe6671a60913f56cc7efc99de1b9045ede2ecfe9570327ad0a53f2f195188',hypotheses=['Explicit Workspace specialization follows original cache/map shape; exact first trial','Unchanged ActiveDocument canonical body; exact first trial'],metrics=dict(compiled_units=2,exact_code_data=2,rejected_hypotheses=0,selected=0,gated_swaps=0,server_credit=0),blockers=['Indirect invalid-parameter calls in Workspace; separate import binding proof','ActiveDocument virtual update/shared-count disposal calls and EH ABI require separate proof','Parent must review additive objects and collision-free isolated link'],next_gate='Parent guarded additive provider selection; no activation'),indent=2))
