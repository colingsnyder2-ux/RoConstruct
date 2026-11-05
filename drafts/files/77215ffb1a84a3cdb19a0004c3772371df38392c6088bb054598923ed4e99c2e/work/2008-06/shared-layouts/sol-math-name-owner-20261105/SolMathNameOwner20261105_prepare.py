import json,hashlib,re
from pathlib import Path
root=Path.cwd(); out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105'; variants=root/'work/native-candidates/sol-math-name-owner-20261105'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
rows=[]
for stem,names in [('Math',['matrixTiltQuadrant','toYAxisQuadrant','closestPointOnRay']),('WorldHelpers',['compare'])]:
 command=root/f'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/{stem}.command.json'; c=json.loads(command.read_text()); src=Path(c['source']); text=src.read_text(); changed=[]
 for name in names:
  owner='Math' if stem=='Math' else 'Name'
  pattern=r'(?m)^(\s*)([^\n;{}/]*\b'+owner+r'::'+name+r'\s*\()'
  text,n=re.subn(pattern,lambda m:m[1]+'inline '+m[2],text); assert n==1,(name,n); changed.append(owner+'::'+name)
 dst=variants/(stem+'.cpp'); dst.write_text(text,encoding='utf-8')
 rows.append(dict(member=stem+'.obj',command=str(command),command_sha256=sha(command),source=str(src),source_sha256=sha(src),recorded_source_sha256=c['source_sha256'],variant=str(dst),variant_sha256=sha(dst),annotations=changed,dependency_changes=[dict(path=p,expected=h,actual=sha(Path(p)) if Path(p).is_file() else None) for p,h in c['dependencies'].items() if not Path(p).is_file() or sha(Path(p))!=h]))
(out/'source-guards.json').write_text(json.dumps(rows,indent=2));print(json.dumps([{k:v for k,v in x.items() if k!='dependency_changes'}|dict(dependency_changes=len(x['dependency_changes'])) for x in rows],indent=2))

