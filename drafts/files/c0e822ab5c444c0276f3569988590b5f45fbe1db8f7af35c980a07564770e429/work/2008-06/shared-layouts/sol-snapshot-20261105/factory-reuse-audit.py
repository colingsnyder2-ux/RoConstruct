import sys,json,hashlib
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root/'rebuild/2008-06/tests'))
import native_check_runner as runner
run=root/'work/2008-06/native-check-runs/20261105-122907-a81d3e5b'
r=json.loads((run/'unit-000/receipt.json').read_text())
changed=[p for p,h in r['dependencies'].items() if not Path(p).exists() or runner.sha(Path(p))!=h]
obj=Path(r['object'])
result={'changed_inputs':changed,'dependency_count':len(r['dependencies']),'object_sha256':runner.sha(obj),'recorded_object_sha256':r['object_sha256'],'source_sha256':runner.sha(Path(r['source'])),'recompiled':False}
result['analysis']=runner.analyze_object(json.loads((run/'manifest.json').read_text())['jobs'][0],obj)
(root/'work/2008-06/shared-layouts/sol-snapshot-20261105/factory-reuse-audit.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:v for k,v in result.items() if k!='analysis'}))
