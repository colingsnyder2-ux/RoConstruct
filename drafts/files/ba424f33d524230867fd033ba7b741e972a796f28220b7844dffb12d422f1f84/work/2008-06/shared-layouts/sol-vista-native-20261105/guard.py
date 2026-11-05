from pathlib import Path
import json,hashlib
F=Path(__file__).resolve().parent
for p,h in json.loads((F/'guard-inputs.json').read_text()).items():
 assert hashlib.sha256(Path(p).read_bytes()).hexdigest()==h,('input drift',p)
r=json.loads((F/'comparison.json').read_text());assert r['status']=='PASS_NO_LOSS_COMDAT' and not r['changed'] and not r['lost'];assert all(x['new_selection']==2 for x in r['vista'])
print('PASS guarded inactive replacement',r['new'],r['new_sha256'])
