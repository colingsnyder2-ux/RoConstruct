from pathlib import Path
import json,hashlib,struct,subprocess
from roc import match
p=Path('work/2008-06/shared-layouts/sol-archive-resolve-20261105')
run=Path('work/2008-06/native-check-runs/20261105-151941-b983051c')
r=json.loads((run/'results.json').read_text())[0]
raw=Path(r['object']).read_bytes()
sections,symbols,defs,_=match._coff_data_index(raw)
start,sec=defs['?resolveRefs@ArchiveBinder@@UAE_NXZ']; table=sections[sec]
relocs=[]
for i in range(table[7]):
 off,idx,kind=struct.unpack_from('<IIH',raw,table[5]+10*i)
 if start<=off<start+96: relocs.append({'body_offset':off-start,'symbol':symbols[idx],'kind':kind})
diff=subprocess.run(['python','rebuild/2008-06/tests/diff_native_body.py',r['object'],'00592720','?resolveRefs@ArchiveBinder@@UAE_NXZ','2'],capture_output=True,text=True)
(p/'diff.txt').write_text(diff.stdout)
asm=subprocess.run(['cmd','/c','roc.cmd','native-asm','2008-06','00592720'],capture_output=True,text=True)
(p/'original.txt').write_text(asm.stdout)
(p/'runner-results.json').write_text(json.dumps(r,indent=2))
summary={'target':'00592720','swap_target':'serializer dependency closure','baseline_receipt':'sol-serializer-callees-20261105','status':'parked pending parent guidance; one authorized compile consumed','rejected_hypotheses':1,'source_sha256':r['source_sha256'],'object_sha256':hashlib.sha256(raw).hexdigest(),'target_size':96,'candidate_size':96,'first_difference':79,'difference':'candidate mov eax,1 before pop edi/esi/ebp; original after','relocations':relocs,'runner':str(run),'profile':'profile.json','direct_binding_proof':False,'missing_inputs':['parent authorization/evidence for second source hypothesis','strict exact body before binding acceptance','count_if helper and resolveIDREF transitive ABI/EH identity','linked provider selection and runtime gates'],'next_bounded_action':'parent review saved object and scheduling evidence; no unchanged recompile','metrics':{'inactive_exact':0,'selected_exact':None,'fully_gated_swaps':0,'server_credit':0}}
(p/'summary.json').write_text(json.dumps(summary,indent=2))
print(json.dumps(summary,indent=2))
