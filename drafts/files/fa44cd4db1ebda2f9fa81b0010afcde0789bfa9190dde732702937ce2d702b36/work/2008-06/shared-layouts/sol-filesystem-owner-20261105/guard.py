from pathlib import Path
import hashlib,json
F=Path(__file__).resolve().parent
for p,h in json.loads((F/'guard-inputs.json').read_text()).items():
 assert Path(p).exists() and hashlib.sha256(Path(p).read_bytes()).hexdigest()==h,('stale input',p)
r=json.loads((F/'replacement.json').read_text())
for p,h in [(Path(r['base_archive']),r['base_sha256']),(F/'FileSystem.obj',r['object_sha256']),(F/'linked.lib',r['private_archive_sha256'])]:
 assert hashlib.sha256(p.read_bytes()).hexdigest()==h,('stale artifact',str(p))
print('PASS frozen FileSystem proposal guards; parent isolated link and original contract review pending')
