"""Verify inactive coordinate getters and their original storage references."""
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
out = base / 'out/native-debug-coordinate-getters-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = [('00563150', '?getShowModelCoordinateFrames@DebugSettings@RBX@@'),
          ('00563160', '?getShowWorldCoordinateFrames@DebugSettings@RBX@@')]
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/DebugSettingsCoordinateGetters.cpp'] +
                     [a + '=' + n for a, n in checks], cwd=root, env=env,
                     capture_output=True, text=True, check=True)
assert '2/2 exact' in run.stdout, run.stdout
obj = out / 'CheckDebugSettingsCoordinateGetters.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), int(address, 16)) for address, prefix in checks]
_, symbols, _, _ = match._coff_data_index(raw)
mapping = [('?showModelCoord@ModelInstance@RBX@@', 0x9753d9),
           ('?showWorldCoord@Workspace@RBX@@', 0x976899)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
rows = verify(Original(), obj, methods, internal)
paths = [base / 'native-classes/DebugSettingsCoordinateGetters.cpp',
         base / 'native-headers/v8datamodel/DebugSettings.h',
         base / 'native-headers/v8datamodel/ModelInstance.h',
         base / 'native-headers/v8datamodel/Workspace.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact getters and storage references. Definition ownership, ABI and runtime unverified.'}
(root / 'work/2008-06/native-debug-coordinate-getters.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
