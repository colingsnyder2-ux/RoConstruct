"""Verify SpecData::glLoaded initial storage and original writer."""
import hashlib
import json
import os
import struct
import subprocess
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
from native_bind import Original, match

base = root / 'rebuild/2008-06'
out = base / 'out/native-render-specdata-state-evidence'
run = subprocess.run([sys.executable, str(base / 'tests/check_native_class.py'),
                      'native-classes/RenderSpecDataState.cpp'], cwd=root,
                     env=dict(os.environ, NATIVE_CHECK_OUT=str(out)), capture_output=True, text=True, check=True)
obj = out / 'CheckRenderSpecDataState.obj'
raw = obj.read_bytes()
sections, _, definitions, _ = match._coff_data_index(raw)
symbol = next(n for n in definitions if n.startswith('?glLoaded@SpecData@Render@RBX@@'))
offset, section = definitions[symbol]
assert offset == 0 and sections[section][3] == 1 and sections[section][4] == 0
original = Original()
assert original.pe.get_memory_mapped_image()[0x972888 - original.image:0x972889 - original.image] == b'\0'
writer, _, _ = match.target('2008-06', '0045ba90')
assert b'\xc6\x05' + struct.pack('<I', 0x972888) + b'\x01' in writer
paths = [base / 'native-classes/RenderSpecDataState.cpp', base / 'native-headers/RenderLib/Profiler.h',
         base / 'tests/native_bind.py', Path(__file__)]
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'sources': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'original_address': '00972888',
           'original_writer': '0045ba90', 'initial_value': False,
           'scope': 'Inactive storage and original write verified. Linked ownership, native writer and runtime unverified.'}
(root / 'work/2008-06/native-render-specdata-state.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: zero-initialized glLoaded storage and original writer')
