"""Verify render settings singleton's initial storage; no runtime claim."""
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
out = base / 'out/native-render-state-evidence'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out))
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/CRenderSettingsSingletonState.cpp'],
                     cwd=root, env=env, capture_output=True, text=True, check=True)
obj = out / 'CheckCRenderSettingsSingletonState.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?sing@?$GlobalSettingsItem@VCRenderSettings@@'))
offset, index = definitions[name]
table = sections[index]
native = raw[table[4] + offset:table[4] + offset + 4] if table[4] else b'\0' * 4
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'), fast_load=True)
image = pe.get_memory_mapped_image()
rva = 0x96cbec - pe.OPTIONAL_HEADER.ImageBase
assert native == image[rva:rva + 4] == b'\0' * 4
paths = [base / 'native-classes/CRenderSettingsSingletonState.cpp', base / 'native-headers/CRenderSettings.h',
         base / 'native-headers/v8datamodel/GlobalSettings.h', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'symbol': name,
           'original_address': '0096cbec', 'initial_bytes': native.hex(),
           'scope': 'Inactive singleton storage only; runtime ownership and initialization unverified.'}
path = root / 'work/2008-06/native-render-settings-state.json'
path.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS original and native singleton state zero:', name)
