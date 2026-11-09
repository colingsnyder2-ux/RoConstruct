"""Verify render-settings described constructor and class descriptor."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match, verify

base = root / 'rebuild/2008-06'
out = base / 'out/native-render-described-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = ['00448040=??0?$DescribedCreatable@VCRenderSettings@@',
          '00447980=?classDescriptor@?$Described@VCRenderSettings@@']
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/CRenderSettingsDescribed.cpp'] + checks,
                     cwd=root, env=env, capture_output=True, text=True, check=True)
assert '2/2 exact' in run.stdout, run.stdout
obj = out / 'CheckCRenderSettingsDescribed.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), address) for address, prefix in
           ((0x448040, '??0?$DescribedCreatable@VCRenderSettings@@'),
            (0x447980, '?classDescriptor@?$Described@VCRenderSettings@@'))]
mapping = [('??0?$FactoryProduct@VCRenderSettings@@', 0x4454d0),
           ('??_B?1??classDescriptor@?$Described@VCRenderSettings@@', 0x96d5f0),
           ('?sRenderSettings@@', 0x815bd4),
           ('?classDescriptor@?$Described@VInstance@RBX@@', 0x40ad80),
           ('?foo@?1??classDescriptor@?$Described@VCRenderSettings@@', 0x96d530),
           ('??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z', 0x5708f0),
           ('??__Ffoo@?1??classDescriptor@?$Described@VCRenderSettings@@', 0x7fad70),
           ('_atexit', 0x6a17af)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
expected_vtables = {0x8160b4, 0x8160a4, 0x81609c, 0x816094, 0x816084,
                    0x816074, 0x816064, 0x816054, 0x816044, 0x816034}
target, _, _ = match.target('2008-06', '00448040')
start, index = definitions[methods[0][0]]
section = sections[index]
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
    offset -= start
    name = symbols[symbol][0]
    if name.startswith('??_7?$DescribedCreatable@VCRenderSettings@@') and 0 <= offset < len(target) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        assert value in expected_vtables
        internal[name] = value
assert len([n for n in internal if n.startswith('??_7?$DescribedCreatable')]) == 10
original = Original()
assert original.string(0x815bd4) == 'RenderSettings'
rows = verify(original, obj, methods, internal)
paths = [base / 'native-classes/CRenderSettingsDescribed.cpp', base / 'native-headers/CRenderSettings.h',
         base / 'native-headers/reflection/reflection.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact bodies and binding addresses; factory base, vtable contents and runtime remain unverified.'}
path = root / 'work/2008-06/native-render-described.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
print(path)
