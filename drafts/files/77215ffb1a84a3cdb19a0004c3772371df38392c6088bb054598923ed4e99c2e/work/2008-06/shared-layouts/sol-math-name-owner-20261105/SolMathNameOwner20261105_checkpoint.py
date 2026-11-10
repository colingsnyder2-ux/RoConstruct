import json,sys
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root/'rebuild/2008-06/tests'));import native_check_runner as r
out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105';results=json.loads((out/'reviewed-call-proof.json').read_text())
proof=[]
for row in results:
 try:r.require_proof([dict(status='complete',**row)]);state='passed'
 except SystemExit as e:state='rejected: '+str(e)
 proof.append(dict(object=row['object'],require_proof=state))
campaign=dict(swap_target='CRobloxDoc native diagnostic ownership closure',baseline_receipt='work/2008-06/native-doc-relinks/20261105-131253-90ee3d03/result.json',session='103bd3163b3a4e4ebab230512c6674c8',metrics=dict(compiled_distinct_sources=2,native_body_data_exact=4,retained_bodies=181,retained_named_data=194,changed_retained_bodies=0,changed_retained_data=0,other_members_preserved_per_step=266,new_selected_executable=0,fully_gated_swaps=0,server_credit=0),proof=proof,blockers=[dict(symbol='Name::compare imported std::string::compare',evidence='Original0041fb1a FF15 IAT00802424 MSVCP90.dll decorated compare; runner intentionally rejects indirect call. Separate import/provider/ABI proof required.',status='separate obligation'),dict(provider='Math switch jump table / all linked providers',status='parent isolated cumulative link selection + data/EH/ABI/runtime gates outstanding')],next_gate='Parent compose guarded Math.obj and WorldHelpers.obj replacements against cumulative Content archive; preserve other266members at each step.',hypotheses=['inline annotations only on four named methods; accepted retained source body/data/callee preservation'],resume_queue=['independent imported string compare ABI proof','selected linked provider/data and implicit library closure'],rejected_hypotheses=0)
(out/'campaign.json').write_text(json.dumps(campaign,indent=2));print(json.dumps(proof,indent=2))
