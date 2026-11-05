import sys,json,hashlib,shutil,struct
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root));from roc import libs,rebuild,match
out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105';sha=lambda b:hashlib.sha256(b).hexdigest()
c=json.loads((root/'work/2008-06/native-doc-relinks/20261105-131253-90ee3d03/command.json').read_text());baseline=next(Path(x) for x in c['arguments'] if x.endswith('null-tool-owner\\linked.lib'))
a=dict(libs.archive_members(baseline));rows=json.loads((out/'preservation.json').read_text()); steps=[];current=baseline
for row in rows:
 name=row['member'];raw=Path(row['original_object']).read_bytes();assert a[name]==raw,(name,'baseline identity failed')
 folder=out/(Path(name).stem+'-archive');folder.mkdir(exist_ok=True);shutil.copyfile(row['replacement'],folder/name)
 dest=folder/'linked.lib';code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo',str(current),name,'/OUT:'+str(dest)],folder);assert code==0,log
 before=dict(libs.archive_members(current));after=dict(libs.archive_members(dest));assert before.keys()==after.keys();others=[n for n in before if n!=name];assert all(before[n]==after[n] for n in others);assert after[name]==Path(row['replacement']).read_bytes()
 steps.append(dict(member=name,input_archive=str(current),input_sha256=sha(current.read_bytes()),output_archive=str(dest),output_sha256=sha(dest.read_bytes()),unchanged_other_members=len(others),baseline_member_sha256=sha(a[name]),replacement_sha256=sha(after[name])))
 current=dest
lost=set(n for row in rows for n in row['lost'] if not n.startswith(('?closestPointOnRay@','?matrixTiltQuadrant@','?toYAxisQuadrant@','?compare@Name@')));refs=[];count=0;short=0
for arg in c['arguments']:
 p=Path(arg)
 if p.suffix.lower() not in ['.obj','.lib'] or not p.is_file():continue
 inputs=libs.archive_members(p) if p.suffix.lower()=='.lib' else [(p.name,p.read_bytes())]
 for member,raw in inputs:
  count+=1
  if raw[:4]==b'\0\0\xff\xff':short+=1;continue
  if raw[:2]!=b'L\x01':continue
  for n,defined in rebuild.coff_externals(raw).items():
   if n in lost and not defined:refs.append(dict(input=str(p),member=member,symbol=n))
receipt=dict(baseline=str(baseline),baseline_sha256=sha(baseline.read_bytes()),member_steps=steps,lost_helpers=sorted(lost),external_references=refs,explicit_objects_audited=count,short_imports_counted=short,implicit_default_library_closure='separate unproven obligation',composition='Use guarded member replacements against parent current cumulative archive; never select this whole private archive over Content changes')
(out/'archive-proof.json').write_text(json.dumps(receipt,indent=2));print(json.dumps(receipt,indent=2))
