"""Verify render-settings factory base constructor and destructor."""
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
out = base / 'out/native-render-factory-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = ['004454d0=??0?$FactoryProduct@VCRenderSettings@@',
          '00445410=??1?$FactoryProduct@VCRenderSettings@@']
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/CRenderSettingsFactory.cpp'] + checks,
                     cwd=root, env=env, capture_output=True, text=True, check=True)
assert '2/2 exact' in run.stdout, run.stdout
obj = out / 'CheckCRenderSettingsFactory.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), address) for address, prefix in
           ((0x4454d0, '??0?$FactoryProduct@VCRenderSettings@@'),
            (0x445410, '??1?$FactoryProduct@VCRenderSettings@@'))]
mapping = [('??0Item@GlobalSettings@RBX@@', 0x409e00), ('??1Instance@RBX@@', 0x55a540)]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in mapping}
expected_vtables = {0x815d4c, 0x815d3c, 0x815d34, 0x815d2c, 0x815d1c,
                    0x815d0c, 0x815cfc, 0x815cec, 0x815cdc, 0x815ccc}
target, _, _ = match.target('2008-06', '00445410')
start, index = definitions[methods[1][0]]
section = sections[index]
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * i)
    offset -= start
    name = symbols[symbol][0]
    if name.startswith('??_7?$FactoryProduct@VCRenderSettings@@') and 0 <= offset < len(target) - 3:
        value = struct.unpack_from('<I', target, offset)[0]
        assert value in expected_vtables
        internal[name] = value
assert len([n for n in internal if n.startswith('??_7?$FactoryProduct')]) == 10
rows = verify(Original(), obj, methods, internal)
paths = [base / 'native-classes/CRenderSettingsFactory.cpp', base / 'native-headers/CRenderSettings.h',
         base / 'native-headers/reflection/reflection.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact factory base lifecycle and binding addresses; full vtables and runtime unverified.'}
path = root / 'work/2008-06/native-render-factory.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
print(path)
