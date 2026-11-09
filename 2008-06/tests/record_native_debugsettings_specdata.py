"""Verify native SpecData destruction and DebugSettings profile getters."""
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
out = base / 'out/native-debug-specdata-evidence'
checks = [('00563230', '?videoMemory@DebugSettings@RBX@@'), ('00563260', '?cpuSpeed@DebugSettings@RBX@@'),
          ('00563290', '?cpuCount@DebugSettings@RBX@@'), ('00563940', '?ram@DebugSettings@RBX@@'),
          ('00563a50', '?shaderModel@DebugSettings@RBX@@'), ('00563430', '?glVendor@DebugSettings@RBX@@'),
          ('005638c0', '?cpu@DebugSettings@RBX@@'), ('00563970', '?resolution@DebugSettings@RBX@@'),
          ('005631c0', '??1SpecData@Render@RBX@@')]
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/DebugSettingsSpecData.cpp'] + [a + '=' + p for a, p in checks],
                     cwd=root, env=dict(os.environ, NATIVE_CHECK_OUT=str(out)),
                     capture_output=True, text=True, check=True)
assert '9/9 exact' in run.stdout, run.stdout
obj = out / 'CheckDebugSettingsSpecData.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), int(address, 16)) for address, prefix in checks]
_, symbols, _, _ = match._coff_data_index(raw)
ctor = next(s[0] for s in symbols.values() if s[0].startswith('??0SpecData@Render@RBX@@'))
rows = verify(Original(), obj, methods, {ctor: 0x501ae0})
paths = [base / 'native-classes/DebugSettingsSpecData.cpp', base / 'native-headers/RenderLib/Profiler.h',
         base / 'native-headers/v8datamodel/DebugSettings.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact getters and destructor; direct targets verified. Constructor implementation, ABI and runtime unverified.'}
(root / 'work/2008-06/native-debug-specdata.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
