"""Verify original initial bytes for render settings globals."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match

base = root / 'rebuild/2008-06'
out = base / 'out/native-render-defaults-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                'native-classes/CRenderSettingsDefaults.cpp'], cwd=root, env=env,
               capture_output=True, text=True, check=True)
obj = out / 'CheckCRenderSettingsDefaults.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'), fast_load=True)
image = pe.get_memory_mapped_image()
targets = [('?aaSamples@CRenderSettings@@', 0x930668),
           ('?defaultWindowSize@CRenderSettings@@', 0x93066c),
           ('?aggregateSize@CRenderSettings@@', 0x942df8)]
rows = []
for prefix, address in targets:
    name = next(n for n in definitions if n.startswith(prefix))
    offset, section = definitions[name]
    table = sections[section]
    value = raw[table[4] + offset:table[4] + offset + 4]
    rva = address - pe.OPTIONAL_HEADER.ImageBase
    assert value == image[rva:rva + 4]
    rows.append({'symbol': name, 'original': hex(address), 'bytes': value.hex()})
assert not any(n.startswith('??__E') for n in definitions)
paths = [base / 'native-classes/CRenderSettingsDefaults.cpp', base / 'native-headers/CRenderSettings.h', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'data': rows,
           'scope': 'Inactive static data bytes only; access, ownership and runtime not verified.'}
path = root / 'work/2008-06/native-render-defaults.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: 3 render settings initial data values')
