from pathlib import Path
import sys,json,hashlib,subprocess,os
from collections import Counter
R=Path.cwd();sys.path.insert(0,str(R));sys.path.insert(0,str(R/'rebuild/2008-06/tests'));from roc import libs,match
import native_check_runner as n
F=R/'work/2008-06/shared-layouts/sol-irenderable-20261105';base=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(k,v):(F/k).write_text(json.dumps(v,indent=2)+'\n')
c=json.loads((F/'comparison.json').read_text());assert not c['all_symbols_changed'] and c['all_symbols_removed']==['??1IRenderable@RBX@@QAE@XZ']
assert sha(base)==c['archive_sha256'];obj=F/'IRenderable.obj';obj.write_bytes((F/'run/unit-001/candidate.obj').read_bytes());ms=list(libs.archive_members(base));assert len(ms)==267
native=F/'run/unit-000/candidate.obj';proof=n.analyze_object({'checks':[{'addr':'0047d410','symbol':'??1IRenderable@RBX@@QAE@XZ','calls':[]}],'ranges':[],'layouts':[]},native);row=proof['checks'][0];assert row['status']=='exact' and row['data_errors']==[] and row['call_identity']['passed'];assert match.coff_data_refs(native.read_bytes(),row['symbol'])==[]
for unit in ['unit-000','unit-001']:
 receipt=json.loads((F/'run'/unit/'receipt.json').read_text());assert all(sha(p)==h for p,h in receipt['dependencies'].items())
save('native-proof.json',dict(proof,object_sha256=sha(native),scope='Saved object strict byte/data/calls proof. Mouse original adjustment and deleting ownership independently disassembled. No linked selection, full transitive ABI/EH or runtime claim.'))
command=json.loads((R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/IRenderable.command.json').read_text());tool=Path(command['compiler']).with_name('lib.exe');args=['/nologo','/OUT:'+str(F/'linked.lib'),str(base),'IRenderable.obj'];env=os.environ.copy();env['PATH']=str(tool.parents[2]/'Common7/IDE')+os.pathsep+str(tool.parent)+os.pathsep+env.get('PATH','');save('librarian-command.json',{'tool':str(tool),'sha256':sha(tool),'args':args,'cwd':str(F)})
p=subprocess.run([str(tool),*args],cwd=F,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);(F/'librarian.log').write_text(p.stdout.decode(errors='replace'));assert p.returncode==0
inv=lambda seq:Counter((name,hashlib.sha256(raw).hexdigest()) for name,raw in seq)
before=inv(ms);after=inv(libs.archive_members(F/'linked.lib'));assert list((before-after).elements())==[(c['member'],c['member_sha256'])];assert list((after-before).elements())==[(c['member'],sha(obj))];assert sha(base)==c['archive_sha256']
save('replacement.json',{'base_archive':str(base),'base_sha256':sha(base),'archive_proposal':str(F/'linked.lib'),'proposal_sha256':sha(F/'linked.lib'),'replaced_member':c['member'],'old_member_sha256':c['member_sha256'],'new_member_sha256':sha(obj),'unchanged_other_members':266,'native_provider':str(native),'native_provider_sha256':sha(native),'distinct_compiles':2,'rejected_hypotheses':0,'status':'inactive; parent owns cumulative link and selection','next_action':'Parent guard exact inputs then isolated cumulative link with native leaf plus proposed archive. Original three link blockers remain parked. Transitive ABI/EH, selection and runtime remain separate gates.'})
print((F/'replacement.json').read_text())
