import json,hashlib,shutil,sys
from pathlib import Path
from collections import Counter
R=Path.cwd();O=R/'work/2008-06/shared-layouts/sol-archive-resolve-refresh-20261105';P=R/'work/2008-06/shared-layouts/sol-archive-resolve-owner-20261105'
ns={};exec((O/'audit.py').read_text().split('manifest=json.loads')[0],ns);H=ns['H'];members=ns['members']
s=json.loads((O/'summary.json').read_text());g=json.loads((O/'guards.json').read_text());c=json.loads((O/'consumers.json').read_text());assert s['status']=='CONDITIONAL_PASS' and not g['original_dependency_drift']
base=R/'work/2008-06/shared-layouts/sol-cumulative-links-20261105/serializer-member-152732-82bc06/linked.lib';candidate=P/'unit-000/candidate.obj';before=members(base.read_bytes())
assert H(base.read_bytes())==g['base_sha256'] and H(candidate.read_bytes())==g['candidate_sha256']
for p,h in json.loads((R/'work/2008-06/native-doc-relinks/20261105-152734-3e8dd256/inputs.json').read_text()).items(): assert H(Path(p).read_bytes())==h,p
stage=O/'inactive';stage.mkdir(exist_ok=True);shutil.copyfile(candidate,stage/'SerializerV2.obj')
sys.path.insert(0,str(R));from roc import rebuild
tc=rebuild.toolchain(21022);args=['/nologo','/OUT:'+str(stage/'linked.lib'),str(base),'SerializerV2.obj'];code,log=rebuild.run(tc,'lib',args,stage);(O/'librarian.log').write_text(log);assert code==0,log
after=members((stage/'linked.lib').read_bytes());bc=Counter(H(b) for n,o,b in before);ac=Counter(H(b) for n,o,b in after);assert len(before)==len(after)==267
bc.subtract([g['old_member_sha256']]);ac.subtract([g['candidate_sha256']]);assert +bc==+ac and sum((+bc).values())==266
resolve='?resolveRefs@ArchiveBinder@@UAE_NXZ';rows=c['removed'][resolve]['consumers'];expanded=[dict(x,object=c['objects'][x['object_id']] if isinstance(x['object_id'],int) else 'candidate') for x in rows]
plan={'status':'CONDITIONAL_INACTIVE_ONLY','base_archive':str(base),'base_sha256':g['base_sha256'],'staged_archive':str(stage/'linked.lib'),'staged_sha256':H((stage/'linked.lib').read_bytes()),'old_member':'SerializerV2.obj','old_sha256':g['old_member_sha256'],'new_sha256':g['candidate_sha256'],'members':267,'other_members_byte_identical':266,'librarian_args':args,'current_input_count':332,'guards':'guards.json; summary.json; consumers.json; symbol-metadata.json','consumers':expanded,'other_removed_consumed':sum(bool(v['consumers']) for k,v in c['removed'].items() if k!=resolve),'missing_strict_provider':resolve,'pending':'Independent native resolveRefs original target code + referenced data + reviewed calls; a44d near-match is not an exact provider. Parent must verify fresh inputs, compose provider and deletion, then serialize selected-provider diagnostic. Complete ABI/EH/ODR, factory COMDAT selection, indirect calls and runtime remain separate gates.','no_default_selection_or_current_archive_change':True,'source_compiles':0,'executables_run':0,'next_gate':'Parent independently validates native resolveRefs exact candidate before selecting this archive.'}
(O/'composition-plan.json').write_text(json.dumps(plan,indent=2));print(json.dumps(plan,indent=2))
