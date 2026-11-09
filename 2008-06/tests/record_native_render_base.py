"""Verify render-settings base lifecycle and class-name methods."""
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
out = base / 'out/native-render-base-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
checks = ['00448120=??0?$GlobalSettingsItem@VCRenderSettings@@',
          '00445c10=??1?$GlobalSettingsItem@VCRenderSettings@@',
          '00445cf0=?getClassName@?$FactoryProduct@VCRenderSettings@@']
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/CRenderSettingsBase.cpp'] + checks,
                     cwd=root, env=env, text=True, capture_output=True, check=True)
assert '3/3 exact' in run.stdout, run.stdout
obj = out / 'CheckCRenderSettingsBase.obj'
raw = obj.read_bytes()
names = [n for n, _, _ in match.coff_functions(raw)]
methods = [(next(n for n in names if n.startswith(prefix)), address) for address, prefix in
           ((0x448120, '??0?$GlobalSettingsItem@VCRenderSettings@@'),
            (0x445c10, '??1?$GlobalSettingsItem@VCRenderSettings@@'),
            (0x445cf0, '?getClassName@?$FactoryProduct@VCRenderSettings@@'))]
sections, symbols, definitions, _ = match._coff_data_index(raw)
lookup = [
    ('??0?$DescribedCreatable@VCRenderSettings@@', 0x448040),
    ('?sRenderSettings@@', 0x815bd4), ('?setName@Instance@RBX@@', 0x55af90),
    ('?sing@?$GlobalSettingsItem@VCRenderSettings@@', 0x96cbec),
    ('?format@G3D@@', 0x509b10), ('??0runtime_error@std@@', 0x409d50),
    ('__TI2?AVruntime_error@std@@', 0x8d1bc8),
    ('??1?$FactoryProduct@VCRenderSettings@@', 0x445410),
    ('?flag@?1???$declare@$1?sRenderSettings@@', 0x96c308),
    ('??$callDoDeclare@$1?sRenderSettings@@', 0x406e90),
    ('?call_once@boost@@', 0x557330), ('??$doDeclare@$1?sRenderSettings@@', 0x406770),
]
internal = {next(s[0] for s in symbols.values() if s[0].startswith(prefix)): address for prefix, address in lookup}
vtables = [0x815e84, 0x815e78, 0x815e70, 0x815e68, 0x815e58,
           0x815e48, 0x815e38, 0x815e28, 0x815e18, 0x815e08]
raw_body, _, _ = match.target('2008-06', '00445c10')
name, body, refs = next(x for x in match.coff_functions(raw) if x[0] == methods[1][0])
start, section = definitions[name]
table = sections[section]
import struct
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    symbol = symbols[index][0]
    if symbol.startswith('??_7?$GlobalSettingsItem@VCRenderSettings@@') and 0 <= offset < len(body) - 3:
        address = struct.unpack_from('<I', raw_body, offset)[0]
        assert address in vtables
        internal[symbol] = address
assert len([x for x in internal if x.startswith('??_7?$GlobalSettingsItem')]) == 10
original = Original()
assert original.string(0x815bd4) == 'RenderSettings'
rows = verify(original, obj, methods, internal)
paths = [base / 'native-classes/CRenderSettingsBase.cpp', base / 'native-headers/CRenderSettings.h',
         base / 'native-headers/v8datamodel/GlobalSettings.h', base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'methods': rows,
           'scope': 'Inactive exact bodies and binding addresses. Complete vtable contents, provider ownership and runtime unverified.'}
path = root / 'work/2008-06/native-render-base.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print(run.stdout, end='')
print(path)
