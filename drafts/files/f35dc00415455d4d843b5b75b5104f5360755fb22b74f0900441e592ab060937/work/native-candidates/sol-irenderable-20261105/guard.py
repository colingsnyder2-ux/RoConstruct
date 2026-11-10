from pathlib import Path
import json,hashlib
R=Path.cwd();F=R/'work/2008-06/shared-layouts/sol-irenderable-20261105'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
r=json.loads((F/'replacement.json').read_text())
for p,h in [(r['base_archive'],r['base_sha256']),(r['archive_proposal'],r['proposal_sha256']),(r['native_provider'],r['native_provider_sha256']),(F/'IRenderable.obj',r['new_member_sha256'])]:assert sha(p)==h,p
for unit in ['unit-000','unit-001']:
 c=json.loads((F/'run'/unit/'receipt.json').read_text());assert sha(c['object'])==c['object_sha256'];assert all(sha(p)==h for p,h in c['dependencies'].items())
print('PASS proposal and saved source/dependency/object guards')
