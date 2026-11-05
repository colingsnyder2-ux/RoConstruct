"""Verify RaiseRange listener-removal loop against the original."""
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
out = base / 'out/native-raise-range-evidence'
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/RaiseRange.cpp', '00420740=?removeIndex@RaiseRange@RBX@@'],
                     cwd=root, env=dict(os.environ, NATIVE_CHECK_OUT=str(out)),
                     capture_output=True, text=True, check=True)
assert '1/1 exact' in run.stdout, run.stdout
obj = out / 'CheckRaiseRange.obj'
raw = obj.read_bytes()
name = next(n for n, _, _ in match.coff_functions(raw) if n.startswith('?removeIndex@RaiseRange@RBX@@'))
rows = verify(Original(), obj, [(name, 0x420740)], {})
assert not rows[0]['verified_targets'] and not rows[0]['local_eh']
paths = [base / 'native-classes/RaiseRange.cpp', base / 'native-headers/util/Events.h',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact leaf. Linked ownership and runtime unverified.'}
(root / 'work/2008-06/native-raise-range.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
