"""Verify the Visit factory creator's original body and call target."""
import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-visit-creator-evidence'
prefix = '?create@Creator@?$FactoryProduct@VVisit@RBX@@'
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/VisitCreator.cpp', '00452950=' + prefix], cwd=root,
                     env=dict(os.environ, NATIVE_CHECK_OUT=str(out)), capture_output=True, text=True, check=True)
assert '1/1 exact' in run.stdout, run.stdout
obj = out / 'CheckVisitCreator.obj'
raw = obj.read_bytes()
name = next(n for n, _, _ in match.coff_functions(raw) if n.startswith(prefix))
_, symbols, _, _ = match._coff_data_index(raw)
factory = next(s[0] for s in symbols.values() if s[0].startswith('??$create@VVisit@RBX@@'))
rows = verify(Original(), obj, [(name, 0x452950)], {factory: 0x4528d0})
paths = [base / 'native-classes/VisitCreator.cpp', base / 'native-headers/v8datamodel/Visit.h',
         base / 'native-headers/util/Object.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact creator and factory relocation. Indirect calls, linked ownership, ABI and runtime unverified.'}
(root / 'work/2008-06/native-visit-creator.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
