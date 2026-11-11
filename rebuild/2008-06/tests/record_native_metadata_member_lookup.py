"""Verify recovered metadata child-search templates; wrappers remain inactive drafts."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-metadata-member-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = ['00443780=??$findFirstChildOfType@VProperties',
          '00443820=??$findFirstChildOfType@VFunctions',
          '004438c0=??$findFirstChildOfType@VEvents']
result = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                         'native-classes/MetadataMemberLookup.cpp'] + checks,
                        cwd=root, env=env, text=True, capture_output=True, check=True)
assert '3/3 exact' in result.stdout, result.stdout
obj = out / 'CheckMetadataMemberLookup.obj'
names = [n for n, _, _ in match.coff_functions(obj.read_bytes())]
methods = []
for address, prefix in ((0x443780, '??$findFirstChildOfType@VProperties'),
                        (0x443820, '??$findFirstChildOfType@VFunctions'),
                        (0x4438c0, '??$findFirstChildOfType@VEvents')):
    methods.append((next(n for n in names if n.startswith(prefix)), address))
rows = verify(Original(), obj, methods, {})
paths = [base / 'native-classes/MetadataMemberLookup.cpp', base / 'native-headers/reflection/Metadata.h',
         base / 'native-headers/v8tree/Instance.h', base / 'tests/check_native_class.py',
         base / 'native-headers/reflection/function.h', base / 'native-headers/reflection/signal.h',
         base / 'native-headers/reflection/property.h', root / 'tools/rbxgs/Client/App/include/reflection/object.h',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest(), 'methods': rows,
           'scope': 'Inactive child-search template bodies and relocation bindings; lookup wrappers not exact or selected.'}
path = root / 'work/2008-06/native-metadata-member-lookup.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(result.stdout, end='')
print(path)
