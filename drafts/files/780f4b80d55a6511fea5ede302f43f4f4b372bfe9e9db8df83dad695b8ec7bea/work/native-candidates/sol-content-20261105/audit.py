from pathlib import Path
import json,hashlib,sys,shutil
sys.path.insert(0,str(Path.cwd()));sys.path.insert(0,str(Path('rebuild/2008-06/p6').resolve()))
from script_context_owner import references,data_symbols,sha
from roc import match
root=Path.cwd();folder=root/'work/2008-06/shared-layouts/sol-content-20261105'
rundir=root/'work/2008-06/native-check-runs/20261105-123027-1322787b'
a,b=[(rundir/f'unit-{i:03}/candidate.obj').read_bytes() for i in range(2)]
fa,fb=[{n:(body,refs) for n,body,refs in match.coff_functions(r)} for r in [a,b]]
common=fa.keys()&fb.keys(); ra,rb=references(a),references(b);da,db=data_symbols(a),data_symbols(b)
assert all(match.exact_match(*fa[n],*fb[n]) and ra[n]==rb[n] for n in common)
assert all(da[n]==db[n] for n in da.keys()&db.keys())
removed=set(fa)-set(fb)
retained_to_removed=[(n,ref) for n in common for ref in rb[n] if ref[1] in removed]
assert not retained_to_removed
native_run=root/'work/2008-06/native-check-runs/20261105-122951-04c3d3fa'
for path,name in [(native_run/'results.json','native-compile.json'),(native_run/'analysis-a25127c6.json','native-analysis.json'),(rundir/'results.json','donor-compile.json')]:shutil.copyfile(path,folder/name)
r={'swap_target':'CRobloxDoc native diagnostic closure','baseline_commit':'e9bfe6671a60913f56cc7efc99de1b9045ede2ecfe9570327ad0a53f2f195188','baseline_receipt':'donor-compile.json; fresh local source baseline, NOT historical archive identity','session':'7345dd7a6b814709b861f45519aa9159','hypotheses':[{'name':'inline only donor load definition','status':'retained preservation passes; external removed-provider consumers pending'}],'metrics':{'distinct_compiles':3,'native_exact_code_and_data':1,'native_size':327,'reviewed_direct_calls':9,'unresolved_indirect_calls':4,'retained_bodies':len(common),'removed_bodies_including_load_and_EH':len(removed),'retained_data':len(da.keys()&db.keys()),'removed_data':len(da.keys()-db.keys()),'retained_relocation_differences':0,'retained_body_differences':0,'retained_data_differences':0,'retained_to_removed_edges':0,'selected_exacts':None,'gated_swaps':0,'server_credit':0},'blockers':[{'provider':'donor ContentProvider::load ownership','status':'proposal only','next_proof':'Parent new snapshot: verify baseline object against actual member; audit all removed provider external consumers; preserve/provide each before archive replacement; compare other members and selected map.'},{'provider':'native load calls','status':'9 direct calls verified; --require-proof fails four indirect calls at offsets 59,126,287,301','next_proof':'IAT string ctor/dtor and virtual stream deleting-destructor ABI proof; no runner weakening.'}],'next_gate':'Parent source-built current archive replacement + serialized closure; no activation','hashes':{str(p.relative_to(root)):sha(p) for p in [root/'rebuild/2008-06/native-classes/ContentProviderLoad.cpp',root/'tools/rbxgs/Client/App/util/ContentProvider.cpp',root/'work/native-candidates/sol-content-20261105/baseline.cpp',root/'work/native-candidates/sol-content-20261105/inline.cpp']}}
(folder/'campaign.json').write_text(json.dumps(r,indent=2),encoding='utf-8'); print(json.dumps(r['metrics']))
